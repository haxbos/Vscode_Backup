#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void test_char(){
    char *concatenate_string = new char[strlen("hello" "world") + 1]();
    strcat(concatenate_string, "hello");
    strcat(concatenate_string, "world");
    cout << concatenate_string << endl;
    delete[] concatenate_string;

    string str1("hello"), str2("world");
    cout << str1 + str2 << endl;
}

void test_dynamic_input(){
    cout << "how long do you want the string?\n";
    int size = 0;
    cin >> size;

    char *input = new char[size + 1]();
    //cin.ignore()函数中有两个参数，分别为数值型的a 和 字符型的 ch ，
    // 即cin.ignore( a, ch )。它表示从输入流 cin 中提取字符，提取的字符被忽略，不被使用。
    // 而每抛弃一个字符，它都要进行计数和比较字符：
    // 如果计数值达到 a 或者被抛弃的字符是 ch ，则cin.ignore() 函数执行终止；否则，它继续等待。
    cin.ignore();   //忽略输入数字时的回车
    
    cout << "input the string: " << endl;
    cin.get(input,size+1);
    cout << input;
    delete[] input;
}

int main(){
    //test_char();
    test_dynamic_input();
}