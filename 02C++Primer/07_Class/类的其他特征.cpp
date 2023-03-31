#include <iostream>
#include <string>
using namespace std;

class Screen{
public:
    //由类定义的类型和类内其他成员一样存在返回限制，由public、private、protect决定
    //  而且必须先定义在使用！
    //（所以这时如果把下面private下的内容放在public前面就会报错）
    typedef string::size_type pos;

    //因为Screen有另外一个构造函数，所以本构造函数是必须的
    Screen() = default;
    Screen (pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}

    char get() const {return contents[cursor];} //隐式内联
    inline char get(pos r,pos c) const;         //显示内联
    Screen &move(pos r, pos c);                 //能在之后被设置为内联

    void some_member() const;

    Screen &set(char );
    Screen &set(pos , pos, char );
    
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;  

    //用mutable定义的成员是一个  “可变数据成员”，永远不会是const
    //即使它是const 对象的成员
    mutable size_t access_ctr = 0;
};

//获取光标所指字符
inline 
char Screen::get(pos r,pos c) const{
    pos row = r * width;
    return contents[row + c];
}

//移动光标到指定位置
inline 
Screen &Screen::move(pos r,pos c){
    pos row = r * width;
    cursor = row + c;
    return *this;       //以左值的形式返回对象
}

void Screen::some_member() const{
    ++access_ctr;
    cout << access_ctr << " : call" << endl;

}

inline
Screen &Screen::set(char c){
    contents[cursor] = c;
    return *this;
}

inline
Screen &Screen::set(pos r, pos col, char ch){
    contents[r*width + col] = ch;
    return *this;
}
int main(){
    Screen myscreen(5,5,'X');
    // char ch = myscreen.get();
    // cout << ch << endl;
    // ch = myscreen.get(0,0);
    // cout << ch << endl;

    // for(int i=0; i<5; ++i){
    //     myscreen.some_member();
    // }

    myscreen.move(4,0).set('#');
    char ch = myscreen.get(4,0);
    cout << ch << endl;

}