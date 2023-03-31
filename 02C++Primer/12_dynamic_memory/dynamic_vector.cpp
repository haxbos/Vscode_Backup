#include <iostream>
#include <vector>
#include <memory>
using namespace std;

//内置指针
namespace test_new{
    vector<int> * Foo(){
        return new vector<int>{};
    }
    vector<int> *cin_Foo(vector<int> *vec){
        for(int i; cout << "Please enter:\n", cin >> i; vec->push_back(i));
        return vec;
    }

    ostream& print(vector<int> *vec){
        for(auto i : *vec)  cout << i << " ";
        return cout;
    }
}

using namespace test_new;
void test01(){
    vector<int> *vec = cin_Foo(Foo());
    print(vec) << endl;
    delete vec;
}

//shared_ptr
namespace test_shared_ptr{
    shared_ptr<vector<int>> make_Foo(){
        return make_shared<vector<int>>();
    }

    shared_ptr<vector<int>> shared_cin_Foo(shared_ptr<vector<int>> vec){
        for(int i; cout << "Please enter:\n",cin >> i; vec->push_back(i));
        return vec;
    }

    ostream& shared_print(shared_ptr<vector<int>> vec){
        for(auto num : *vec) cout << num << " ";
        return cout;
    }
}

using namespace test_shared_ptr;
void test02(){
    shared_ptr<vector<int>> vec = shared_cin_Foo(make_Foo());
    shared_print(vec) << endl;
}
int main(){
    //test01();
    test02();
    return 0;
}



