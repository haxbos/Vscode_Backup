#include <iostream>
#include <vector>
#include <atomic>
#include <thread>
using namespace std;

volatile atomic_bool flag = false;
volatile atomic_int mycnt = 0;

void handler(){
    while(!flag){
        this_thread::yield();   //线程让出当前CPU时间片，等待下一次调度
    }
    for(int i=0; i<100; ++i){
        ++mycnt;
    }
}

int main(){
    vector<thread> vec;
    for(int i=0; i<10; ++i){
        vec.push_back(thread(handler));
    }

    this_thread::sleep_for(chrono::seconds(2));
    flag = true;
    for(auto &t : vec){
        t.join();
    }
    cout << mycnt << endl;
    return 0;
}