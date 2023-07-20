#include <iostream>
#include <memory>
using namespace std;

class Car{
public:
    virtual void show() = 0;
};
class BWM : public Car{
public:
    void show() override{
        cout << "I'm BWM, only base function";
    }
};
class ADUI : public Car{
public:
    void show() override{
        cout << "I'm ADUI, only base function";
    }
};
class BENZ : public Car{
public:
    void show() override{
        cout << "I'm BENZ, only base function";
    }
};

//decorator01 定速巡航
class ConcreteDecorator01 : public Car{
public:
    ConcreteDecorator01(unique_ptr<Car> car) : csptr(move(car)) {}
    void show() override{
        csptr->show();
        cout << ",cruise control";
    }
private:
    //Car *_p;
    unique_ptr<Car> csptr;
};
//decorator02 自动刹车
class ConcreteDecorator02 : public Car{
public:
    ConcreteDecorator02(unique_ptr<Car> car) : csptr(move(car)) {}
    void show() override{
        csptr->show();
        cout << ",automatic braking";
    }
private:
    //Car *_p;
    unique_ptr<Car> csptr;
};
//decorator03 车道偏离
class ConcreteDecorator03 : public Car{
public:
    ConcreteDecorator03(unique_ptr<Car> car) : csptr(move(car)) {}
    void show() override{
        csptr->show();
        cout << ",lane departure";
    }
private:
    //Car *_p;
    unique_ptr<Car> csptr;
};

#ifdef POINTER
void test_decorator(){
    Car* p1 = new ConcreteDecorator01(new BWM());
    p1 = new ConcreteDecorator02(p1);
    Car* p2 = new ConcreteDecorator02(new ADUI());
    Car* p3 = new ConcreteDecorator03(new BENZ());
    p1->show();
    cout << endl;
    
    p2->show();
    cout << endl;

    p3->show();
    cout << endl;

    delete p1;
    delete p2;
    delete p3;
}
#endif

void test_decorator2(){
    unique_ptr<Car> p1(make_unique<ConcreteDecorator01>(make_unique<BWM>()));
    p1 = make_unique<ConcreteDecorator02>(move(p1));
    p1 = make_unique<ConcreteDecorator03>(move(p1));
    p1->show();
}

int main(){
    //test_decorator();
    test_decorator2();
}