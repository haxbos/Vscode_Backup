#include <iostream>
#include <memory>
#include <string>
#include <initializer_list>
using namespace std;

class StrVec{
public:
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
    StrVec(const StrVec&);
    StrVec(StrVec&&) noexcept;
    StrVec(initializer_list<string>);
    StrVec& operator=(const StrVec&);
    StrVec& operator=(StrVec&&) noexcept;
    size_t size() const {return first_free - elements; }
    size_t capacity() const {return cap - elements; }
    string *begin() const {return elements; }
    string *end() const {return first_free; }

    void push_back(const string&);
    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const string&);
    void print();

    ~StrVec();

private:
    allocator<string> alloc;
    string *elements;   //内存头部
    string * first_free;    //实际存储数据的后一个位置
    string *cap;    //内存尾部后一个位置
    
private:
    //分配内存，并保存一个给定范围的元素,返回一个pair
    //其中第一个元素分配新内存的开始位置，第二个元素为末尾最后一个位置的下一个
    pair<string*, string*> alloc_n_copy(const string*, const string*);  
    void reallocate();  //当内存使用完时，为StrVec 分配新内存
    void alloc_n_move(size_t new_cap);  //把数据从旧数组移动到新数组

    //chk_n_alloc保证StrVec至少有容纳一个新元素的空间。
    //如果没有空间添加新元素，chk_n_alloc会调用rea11ocate来分配更多内存。
    void chk_n_alloc();
    void range_initialize(const string*, const string*);
    void free();    //释放空间
};