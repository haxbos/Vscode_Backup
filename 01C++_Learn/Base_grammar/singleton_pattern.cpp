#include <iostream>
#include <mutex>
using namespace std;

//饿汉式单例模式
#ifdef 0
class Singleton{
public:
    static Singleton* getInstance(){
        return &instance;
    }
private:
    static Singleton instance;  //定义一个唯一的类的实例对象
    Singleton(){    //构造函数私有化

    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
};
Singleton Singleton::instance;
#endif

#ifdef 1
std::mutex _mutex;
//懒汉式单例模式1
class Singleton{
public:
    static Singleton* getInstance(){
        if(instance == nullptr){
            lock_guard<std::mutex> lgd(_mutex);
            if(instance == nullptr){
                /*开辟内存
                  构造对象
                  给instance赋值
                */
                instance = new Singleton();
            }
        }
        return instance;
    }
private:
    //添加 volatile属性，禁止编译器对语句进行优化，防止出现不安全现象
    static Singleton *volatile instance;  //定义一个唯一的类的实例对象
    Singleton(){    //构造函数私有化

    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
};
Singleton *volatile Singleton::instance = nullptr;
#endif

//懒汉式单例模式2
class Singleton{
public:
    static Singleton* getInstance(){
        //函数局部静态变量的初始化，在汇编指令中，已经自动添加了线程互斥指令
        static Singleton instance;
        return &instance;
    }
private:
    Singleton(){    //构造函数私有化

    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

int main(){
    Singleton *p1 = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();
    Singleton *p3 = Singleton::getInstance();
    return 0;
}