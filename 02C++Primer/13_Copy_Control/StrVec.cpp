#include "StrVec.h"

void StrVec::chk_n_alloc(){
    if( size() == capacity() ) 
        reallocate();
}

void StrVec::push_back(const string &s){
    chk_n_alloc();
    alloc.construct(first_free++,s);
}

pair<string*,string*> StrVec::alloc_n_copy(const string *b, const string *e){
    auto data = alloc.allocate(e-b);
    return {data,uninitialized_copy(b, e, data)};
}

void StrVec::free(){
    if(elements){
        for(auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements,cap-elements);
    }
}

StrVec::StrVec(const StrVec &s){
    range_initialize(s.begin(),s.end());
}

StrVec::StrVec(StrVec &&s) noexcept
: elements(s.elements),first_free(s.first_free),cap(s.cap){
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec::StrVec(initializer_list<string> li){
    range_initialize(li.begin(),li.end());
}

StrVec& StrVec::operator=(const StrVec& rhs){
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept{
    if(this != &rhs){
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

void StrVec::alloc_n_move(size_t new_cap){
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;    //指向新数组中下一个空闲的位置
    auto elem = elements;   //指向旧数组中下一个元素

    //将旧数组中的元素 移动 到新数组中（注：不是拷贝）
    for(size_t i=0; i<size(); ++i){
        alloc.construct(dest++,move(*elem++));
    }
    
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}

void StrVec::reallocate(){
    auto newcapacity = size()? size() * 2 : 1;
    //alloc_n_move(newcapacity);
    auto first = alloc.allocate(newcapacity);

    auto last = uninitialized_copy(make_move_iterator(begin()),make_move_iterator(end()),first);
    free();
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}

void StrVec::reserve(size_t new_cap){
    if(new_cap <= capacity()) return;
    alloc_n_move(new_cap);
}

void StrVec::resize(size_t count){
    resize(count, string());
}

void StrVec::resize(size_t count, const string &s){
    if(count > size()){
        if(count > capacity()) reserve(count * 2);
        for(size_t i = size(); i!= count; ++i)
            alloc.construct(first_free++,s);
    }
    else if(count < size()){
        while(first_free != elements + count)
            alloc.destroy(--first_free);
    }
}
void StrVec::range_initialize(const string *first, const string *last){
    auto newdata = alloc_n_copy(first,last);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec(){
    free();
}

void StrVec::print(){
    string *first = elements;
    for(; first != first_free; ++first)
        cout << *first << endl;
}
int main(){
    
    StrVec vec{"xixi","haha"};
    string s = "xixihaha";
    vec.push_back(s);

    vec.print();
    //cout << *vec.begin() << endl;
}
