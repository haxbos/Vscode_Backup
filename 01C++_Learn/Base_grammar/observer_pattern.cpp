#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <unordered_map>
using namespace std;

class Observer{
public:
    virtual void handler(int msgid) = 0;
};
class Observer01 : public Observer{
public:
    void handler(int msgid) override {
        switch(msgid)
        {
            case 1:
                cout << "Observer01 recv 1 msg" << endl;
                break;
            case 2:
                cout << "Observer01 recv 2 msg" << endl;
                break;
            default:
                cout << "Observer01 recv unknow msg" << endl;
                break;
        }
    }
};
class Observer02 : public Observer{
public:
    void handler(int msgid) override {
        switch(msgid)
        {
            case 2:
                cout << "Observer02 recv 2 msg" << endl;
                break;
            default:
                cout << "Observer02 recv unknow msg" << endl;
                break;
        }
    }
};
class Observer03 : public Observer{
public:
    void handler(int msgid) override {
        switch(msgid)
        {
            case 1:
                cout << "Observer03 recv 1 msg" << endl;
                break;
            case 3:
                cout << "Observer03 recv 3 msg" << endl;
                break;
            default:
                cout << "Observer01 recv unknow msg" << endl;
                break;
        }
    }
};

class Subject{
public:
    void addObserver(Observer *ob, int msgid){
        hash[msgid].emplace_back(ob);
    }
    void dispatch(int msgid){
        if(hash.find(msgid) != hash.end()){
            for(Observer* ob : hash[msgid]){
                ob->handler(msgid);
            }
        }
    }
private:
    unordered_map<int, vector<Observer*>> hash;
};

void test_Observer(){
    int msgid;

    Observer *p1 = new Observer01();
    Observer *p2 = new Observer02();
    Observer *p3 = new Observer03();
    Subject sub;
    sub.addObserver(p1, 1);
    sub.addObserver(p1, 2);
    sub.addObserver(p2, 2);
    sub.addObserver(p3, 1);
    sub.addObserver(p3, 3);

    while(1){
        cout << "Please input msgid : ";
        cin >> msgid;
        if(msgid == -1) break;
        sub.dispatch(msgid);
    }
    delete p1;
    delete p2;
    delete p3;
}
int main(){
    test_Observer();
}
