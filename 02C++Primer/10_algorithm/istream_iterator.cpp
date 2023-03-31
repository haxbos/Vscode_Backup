#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

//使用istream_iterator 输入流迭代器 从 cin 中获取数据，初始化 vector
void test01(){
    istream_iterator<int> iter(cin);
    istream_iterator<int> eof;

    vector<int> arr;

    while(iter != eof){
        arr.push_back(*iter++);
    }

    for(auto num : arr)  cout << num << " ";
}

void test02(){
    ifstream ifs("str_in.txt");
    istream_iterator<string> s_in(ifs);
    istream_iterator<string> eof;

    vector<string> arr(s_in,eof);

    for(auto str : arr) cout << str << endl;


}
int main(){
    //test01();
    test02();
}