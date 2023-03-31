#include<iostream>
#include<vector>
#include<list>
using namespace std;

/*使用begin(c)而不 是使用 c.begin() 编写泛型 代码具有下述优点： 

它使得泛型代码能够在有begin/end作为成员函数的容器上正常运行， 
而且对那些没有begin/end,但以后可能用一些适当的非成员函数来扩充功能的容器也能正常运行。
*/

//原型
template<class Container>
auto begin(Container & c)->decltype(c.begin()){
    return c.begin();
}

template<class Container>
auto begin(const Container& c)->decltype(c.begin()){
    return c.begin();
}

//打印任意容器
template<class Container>
void Print(const Container& c,ostream &out=cout){
    if(c.empty())
        out<<"empty"<<endl;
    else{
        auto itr=begin(c);  //itr 是 Container::const_iterator
        out<<"["<<*itr++;
        while(itr!=end(c))
            out<<","<<*itr++;
        out<<"]";
    }
}
int main(){
    vector<int> v={1,2,3,4,5,6};
    Print(v);
}