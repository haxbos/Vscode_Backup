#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class HasPtr{
public:
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);

    HasPtr(const string &s = string()):ps(new string(s)),i(0){}
    HasPtr(const HasPtr& hp):ps(new string(*hp.ps)),i(hp.i){}
    HasPtr(HasPtr &&hp) noexcept : ps(hp.ps),i(hp.i){ hp.ps = 0; }

    //此时的赋值运算符既是 移动赋值运算符， 也是拷贝赋值运算符
    HasPtr& operator=(HasPtr tmp){
        this->swap(tmp);
        return *this;
    }

    void swap(HasPtr &rhs){
        using std::swap;
        cout <<"*this->ps : " << *ps << "    " << "*rhs.ps : " << *rhs.ps << endl;
        cout <<"this->ps : " << ps << "    " << "rhs.ps : " << rhs.ps << endl;
        swap(ps,rhs.ps);
        swap(i,rhs.i);
        cout << "call swap(HasPtr &rhs)" << endl;
    }

    void show() const {
        cout << *ps << endl;
    }
    ~HasPtr(){
        delete ps;
    }
private:
    string *ps;
    int i;
};

void swap(HasPtr &lhs, HasPtr &rhs){
    lhs.swap(rhs);
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs){
    return *lhs.ps < *rhs.ps;
}

int main(){
    HasPtr s{"s"},a{"a"},c{"c"};
    vector<HasPtr> vec{s,a,c};
    sort(vec.begin(),vec.end());

    for(auto const &elem : vec)
        elem.show();
    
    return 0;
}