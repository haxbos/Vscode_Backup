#include <string>
using namespace std;

class HasPtr{
public:
    friend void swap(HasPtr &lhs,HasPtr &rhs);
    HasPtr(const string &s = string()):ps(new string(s)),i(0),use(new size_t(1)){}
    HasPtr(const HasPtr &rhs):ps(rhs.ps),i(rhs.i),use(rhs.use){ ++*use;}
    HasPtr& operator=(const HasPtr &rhs);
    ~HasPtr();

private:
    string *ps;
    int i;
    size_t *use;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs){
    //这里先对右值递增，在对左值递减
    //是为防止 左值和右值为同一个时，先递减，然后把自己的delete了，
    //然后赋值时发生不可预见的错误
    ++*rhs.use;
    if(--*use == 0){
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtr::~HasPtr(){
    if(--*use == 0){
        delete ps;
        delete use;
    }
}

inline
void swap(HasPtr &lhs, HasPtr &rhs){
    string *temp = rhs.ps;
    rhs.ps = lhs.ps;
    lhs.ps = temp;

    size_t *temp2 = rhs.use;
    rhs.use = lhs.use;
    lhs.use = temp2;

    std::swap(lhs.i,rhs.i);
}