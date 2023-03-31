#include <iostream>
#include <string>

//不能直接使用 using namespace std;
//这样会使得我们自己定义的tuple 会继承std下的tuple.导致编译错误
using std::cout,std::string,std::endl;

template<typename... Values> class tuple;
template<> class tuple<> {};

template<typename Head, typename... Tail>
class tuple<Head,Tail...>: private tuple<Tail...>
{
    typedef tuple<Tail...> inherited;
protected:
    Head m_head;
public:
    tuple(){}
    tuple(Head v, Tail... vtail):
        m_head(v),inherited(vtail...){}
    
    //typename Head::type head() { return m_head; } incorrect
    //auto head()->decltype(m_head) { return m_head; } correct
    Head head() {return m_head; }
    inherited& tail() { return *this; }
};

int main(){
    tuple<int,float,string> t(41,6.3,"nice");
    cout << sizeof(t) << endl;
    cout << t.head() << endl;
    cout << t.tail().head() << endl;
    cout << t.tail().tail().head() << endl;

    //std::cout << "Size of a pointer: " << sizeof(int*) << " bytes" << std::endl;
}
