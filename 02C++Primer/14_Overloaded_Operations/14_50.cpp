// #include <iostream>
// using namespace std;

// // struct LongDouble;

// struct LongDouble {
//     LongDouble(double = 0.0);
//     //operator double();
//     operator float();
//     operator int();
// };

// LongDouble::operator int() {
//     return static_cast<int>(static_cast<float>(*this));
// }

// int main(){
//     LongDouble ldObj;
//     int ex1 = ldObj;    // error ambiguous: double or float?
//     float ex2 = ldObj;  // legal

//     cout << "ex1 = " << ex1;
//     cout << "ex2 = " << ex2;

// }

// #include <iostream>
// using namespace std;

// struct LongDouble {
//     LongDouble(double = 0.0);
//     explicit operator double() const;
//     operator float() const;
//     explicit operator int() const;
// };

// LongDouble::operator double() const { return 0; }
// LongDouble::operator float() const { return 0; }
// LongDouble::operator int() const { return 0; }

// int main(){
//     LongDouble ldObj;
//     int ex1 = static_cast<int>(static_cast<float>(ldObj)); // legal
//     float ex2 = ldObj;  // legal

//     cout << "ex1 = " << ex1 << endl;
//     cout << "ex2 = " << ex2 << endl;
// }


#include <iostream>
using namespace std;

struct LongDouble {
    LongDouble(double = 0.0);
    operator float() const;
    //operator int() const;

    double value;
};

LongDouble::LongDouble(double value) : value(value) {}

LongDouble::operator float() const {
    return static_cast<float>(value);
}

// LongDouble::operator int() const {
//     return static_cast<int>(value);
// }

int main() {
    LongDouble ldObj(1.23456789);
    //int ex1 = static_cast<int>(static_cast<float>(ldObj)); // legal

    //先通过自定义类型转换，由ldObj
    int ex1 = ldObj;
    float ex2 = ldObj;  // legal

    cout << "ex1 = " << ex1 << endl;
    cout << "ex2 = " << ex2 << endl;
}
