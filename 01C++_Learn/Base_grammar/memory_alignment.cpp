#include <iostream>
using namespace std;

/*
alignas : 指定对齐方式
alignof : 返回对齐方式
*/

//alignas 生效
struct Info{
    uint8_t a;  //1
    uint16_t b; //2
    uint8_t c;  //1
};

struct alignas(4) Info2{
    uint8_t a; 
    uint16_t b;
    uint8_t c;
};

//alignas 不生效
//alignas 如果小于结构体内 自然对其的最小单位，则不生效
struct Info3{
    uint8_t a;
    uint32_t b; //4
    uint8_t c;
};

struct alignas(2) Info4{
    uint8_t a;
    uint32_t b;
    uint8_t c;
};

void test_sucessful(){
    cout << "Info size: " << sizeof(Info) << endl;
    cout << "Info align: " << alignof(Info) << endl;

    cout << "Info2 size: " << sizeof(Info2) << endl;
    cout << "Info2 align: " << alignof(Info2) << endl;
}

void test_failed(){
    cout << "Info3 size: " << sizeof(Info3) << endl;
    cout << "Info3 align: " << alignof(Info3) << endl;

    cout << "Info4 size: " << sizeof(Info4) << endl;
    cout << "Info4 align: " << alignof(Info4) << endl;
}

void test_size(){
    Info info;
    cout << "Info.a size: " << sizeof(info.a) << endl;
    cout << "Info.b size: " << sizeof(info.b) << endl;
    cout << "Info.c size: " << sizeof(info.c) << endl;

    Info2 info2;
    cout << "Info2.a size: " << sizeof(info2.a) << endl;
    cout << "Info2.b size: " << sizeof(info2.b) << endl;
    cout << "Info2.c size: " << sizeof(info2.c) << endl;

    Info3 info3;
    cout << "Info3.a size: " << sizeof(info3.a) << endl;
    cout << "Info3.b size: " << sizeof(info3.b) << endl;
    cout << "Info3.c size: " << sizeof(info3.c) << endl;

    Info4 info4;
    cout << "Info4.a size: " << sizeof(info4.a) << endl;
    cout << "Info4.b size: " << sizeof(info4.b) << endl;
    cout << "Info4.c size: " << sizeof(info4.c) << endl;
}


// 使用1字节对齐，alignas 是无效的，但是可以使用宏定义
// 但是这种方式不推荐，因为这样会导致内存访问效率低下
#if defined(__GNUC__) || defined(__GNUG__)
  #define ONEBYTE_ALIGN __attribute__((packed))
#elif defined(_MSC_VER)
  #define ONEBYTE_ALIGN
  #pragma pack(push,1)
#endif

struct Info5 {
  uint8_t a;
  uint32_t b;
  uint8_t c;
} ONEBYTE_ALIGN;

#if defined(__GNUC__) || defined(__GNUG__)
  #undef ONEBYTE_ALIGN
#elif defined(_MSC_VER)
  #pragma pack(pop)
  #undef ONEBYTE_ALIGN
#endif

void test_onebyte_align(){
    cout << "Info5 size: " << sizeof(Info5) << endl;
    cout << "Info5 align: " << alignof(Info5) << endl;
}

//确定结构体中每个元素的大小--> 位域（限定每个变量的位数)
//如一个char为1个字节，有8位我们可以通过下面所示的方法，限定它只有1位;
//注意: 如果给一个变量限定了位数后，不能给它赋予超过它位数的值，否则这个行为是未定义的
// 位域的使用，可以使用宏定义
#if defined(__GNUC__) || defined(__GNUG__)
  #define ONEBYTE_ALIGN __attribute__((packed))
#elif defined(_MSC_VER)
  #define ONEBYTE_ALIGN
  #pragma pack(push,1)
#endif

/**
* 0 1   3     6   8 9            15
* +-+---+-----+---+-+-------------+
* | |   |     |   | |             |
* |a| b |  c  | d |e|     pad     |
* | |   |     |   | |             |
* +-+---+-----+---+-+-------------+
*/
struct Info6 {
  uint16_t a : 1;
  uint16_t b : 2;
  uint16_t c : 3;
  uint16_t d : 2;
  uint16_t e : 1;
  uint16_t pad : 7;
} ONEBYTE_ALIGN;

#if defined(__GNUC__) || defined(__GNUG__)
  #undef ONEBYTE_ALIGN
#elif defined(_MSC_VER)
  #pragma pack(pop)
  #undef ONEBYTE_ALIGN
#endif

void test_bit_align(){
    Info6 info6;
    info6.a = 5;    //warning, 不能赋予超过它位数的值, a只有1位，他的值只能是 0 或 1
    cout << "Info6.a: " << info6.a << endl;
    cout << "Info6 size: " << sizeof(Info6) << endl;
    cout << "Info6 align: " << alignof(Info6) << endl;
}

int main(){
    // test_sucessful();
    // cout << "=====================" << endl;
    // test_failed();
    // cout << "=====================" << endl;
    // test_size();
    // cout << "=====================" << endl;
    test_onebyte_align();
    cout << "=====================" << endl;
    test_bit_align(); 
    return 0;
}