#ifndef ex13_05h
#define ex13_05h

#include <string>
using namespace std;

class HasPtr{
public:
    HasPtr(const string &s = string()): ps(new string(s)),i(0){}
    HasPtr(const HasPtr&hp): ps(new string(*hp.ps)),i(hp.i){}
private:
    string *ps;
    int i;
};

#endif

#ifndef ex13_08h
#define ex13_08h

#include <string>

class HasPtr{
public:
    HasPtr(const string &s = string()):ps(new string(s)),i(0){}
    HasPtr(const HasPtr &hp):ps(new string(*hp.ps)),i(hp.i){}
    HasPtr& operator=(const HasPtr &rhs){
        if(this != &rhs){
            string *temps_ps = new string(*rhs.ps);
            delete ps;
            ps = temps_ps;
            i = rhs.i;
        }
        return *this;
    }
private:
    string *ps;
    int i;
};

#endif

#ifndef ex13_11h
#define ex13_11h

#include <string>

//类值拷贝
class HasPtr{
public:
    HasPtr(const string &s = string()):ps(new string(s)),i(0){}
    HasPtr(const HasPtr &hp):ps(new string(*hp.ps)),i(hp.i){}
    HasPtr& operator=(const HasPtr &rhs){
        if(this != &rhs){
            auto *temps_ps = new string(*rhs.ps);
            //string *temps_ps = new string(*rhs.ps);
            delete ps;
            ps = temps_ps;
            i = rhs.i;
        }
        return *this;
    }
    ~HasPtr(){
        delete ps;
    }
private:
    string *ps;
    int i;
};

#endif