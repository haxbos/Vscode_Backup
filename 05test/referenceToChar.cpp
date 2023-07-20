#include <iostream>
#include <string>
using namespace std;

class TextBlock{
public:
    TextBlock(string s):text(s){}
    char& operator[](size_t position){
        return text[position];
    }

    const char& operator[](size_t position)const{
        return text[position];
    }
private:
    string text;
};

void test(){
    TextBlock tb("hello");
    tb[0] = 'x';
    cout << tb[0] << endl;
}

int main(){
    test();
}