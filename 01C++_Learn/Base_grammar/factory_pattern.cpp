#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Car{
public:
    Car(string name):_name(name){}
    virtual void show() = 0;
protected:
    string _name;
};

class Bwm : public Car{
public:
    Bwm(string name):Car(name){}
    void show() override {cout << "get a Bwm " << _name << endl;}
    ~Bwm(){}
};
class Audi : public Car{
public:
    Audi(string name):Car(name){}
    void show() override {cout << "get a Audi " << _name << endl;}
    ~Audi(){}
};

#ifdef SIMPLE_FACTORY
//Simple Factory
enum Cartype{
    BWM, AUDI
};

class SimpleFactory{
public:
    Car* createCar(Cartype ct){
        switch (ct){
            case BWM:
                return new Bwm("x1");
            case AUDI:
                return new Audi("A6");
            default:
                cerr << "Parameter error" << endl;
                break;
        }
        return nullptr;
    }
};

void test_simplefactory(){
    unique_ptr<SimpleFactory> sf(new SimpleFactory());
    unique_ptr<Car> p1(sf->createCar(BWM));
    unique_ptr<Car> p2(sf->createCar(AUDI));

    p1->show();
    p2->show();
}
#endif

#ifdef FACTORY_METHOD
//factory method
class Factory{
public:
    virtual Car* createCar(string name) = 0;
};

class BWMFactory : public Factory{
public:
    Car* createCar(string name) override{
        return new Bwm(name);
    }
};
class AUDIFactory : public Factory{
public:
    Car* createCar(string name) override{
        return new Audi(name);
    }
};

void test_factory_method(){
    unique_ptr<Factory> bwmfty(new BWMFactory());
    unique_ptr<Factory> audifty(new AUDIFactory());
    unique_ptr<Car> p1(bwmfty->createCar("X1"));
    unique_ptr<Car> p2(audifty->createCar("A6"));
    p1->show();
    p2->show();
}
#endif

//系列产品2
class Light{
public:
    virtual void show() = 0;
};
class BWMLight : public Light{
public:
    void show() override{
        cout << "BWM light" << endl;
    }
};
class AUDILight : public Light{
public:
    void show() override{
        cout << "AUDI light" << endl;
    }
};

class AbstractFactory{
public:
    virtual Car* createCar(string name) = 0;
    virtual Light* createLight() = 0;
};

class BWMFactory : public AbstractFactory{
public:
    Car* createCar(string name) override{
        return new Bwm(name);
    }
    Light* createLight() override{
        return new BWMLight();
    }
};
class AUDIFactory : public AbstractFactory{
public:
    Car* createCar(string name) override{
        return new Audi(name);
    }
    Light* createLight() override{
        return new AUDILight();
    }
};

void test_abstract_factory(){
    unique_ptr<AbstractFactory> bwmabsf(new BWMFactory());
    unique_ptr<AbstractFactory> audiabsf(new AUDIFactory());
    unique_ptr<Car> c1(bwmabsf->createCar("X1"));
    unique_ptr<Car> c2(audiabsf->createCar("A6"));
    unique_ptr<Light> l1(bwmabsf->createLight());
    unique_ptr<Light> l2(audiabsf->createLight());
    c1->show();
    l1->show();
    c2->show();
    l2->show();
}

int main(){
    //test_simplefactory();
    //test_factory_method();
    test_abstract_factory();
}