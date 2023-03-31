#include <iostream>
#include <string>
#include <typeinfo>
#include <cxxabi.h>
#include <memory>
#include <vector>
using namespace std;

class Quote{
public:
    Quote() = default;
    Quote(const string& book,double sales_price):
        bookNo(book), price(sales_price){}
    
    string isbn() const { return bookNo; }

    virtual double net_price(size_t n) const {
        return n * price;
    }

    virtual void Debug() const {
        int status;
        std::string name = abi::__cxa_demangle(typeid(*this).name(), nullptr, nullptr, &status);
        std::cout << "Data members of " << name << "\n"
                << "bookNo : " << this->isbn() << "\n"
                << "price : " << this->price << "\n";
    }

    virtual ~Quote() = default;

protected:
    double price = 0.0;
private:
    string bookNo;
};

class Bulk_Quote :public Quote{
public:
    Bulk_Quote() = default;
    Bulk_Quote(const string&, double, size_t, double);

    double net_price(size_t) const override;
    void Debug() const override;

private:
    size_t min_quantity = 0; //使用折扣的最低购买量
    double discount = 0.0;   //以小数表示的折扣额
};

Bulk_Quote::Bulk_Quote(const string& book, double p, size_t qty, double disc):
    Quote(book,p),min_quantity(qty), discount(disc){}

double Bulk_Quote::net_price(size_t cnt) const{
    if(cnt >= min_quantity)
        return cnt * discount * price;
    else
        return cnt * price;
}

void Bulk_Quote::Debug() const{
    int status;
    std::string name = abi::__cxa_demangle(typeid(*this).name(), nullptr, nullptr, &status);
    std::cout << "Data members of " << name << "\n"
        << "bookNo : " << this->isbn() << "\n"
        << "price : " << this->price << "\n"
        << "min_quantity : " << this->min_quantity << "\n"
        << "discount : " << this->discount << endl;
}

void print_total(ostream& os, const Quote& item, size_t n){
    double ret = item.net_price(n);

    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: "
    << ret << endl;
}

void print_debug(const Quote& item){
    item.Debug();
}

void test_print_total(){
    Quote q("textbook",10.60);
    Bulk_Quote bq("textbook",10.60, 10, 0.7);

    print_total(cout, q, 12);
    print_total(cout, bq, 12);
}


void test_vector(){
    //因为vector<Quote>中的元素是Quote对象,
    //当容器中存放的是Bulk_Quote对象时,Bulk_Quote中属于派生类的部分会被“切掉”，只剩下属于基类的部分，
    //所以会调用Quote的net_price函数
    vector<Quote> vec;
    double total = 0;
    for(int i=0; i<=10; ++i){
        vec.emplace_back(Bulk_Quote("textbook",i * 10.20, 10, 0.7));
        total += vec[i].net_price(12);
    }
    
    cout << "vector<Quote> total : " << total << endl;
}

void test_shared_ptr(){
    //因为我们容器中存放的是shared_ptr<Quote> 智能指针时，
    //当存入 shared_ptr<Bulk_Quote> 智能指针时，会自动转换成 shard_ptr<Quote> 智能指针，
    //尽管形式上由区别，但是实际上是同一个对象，所以会调用Bulk_Quote的net_price函数
    vector<shared_ptr<Quote>> vec;
    double total = 0;
    for(int i=0; i<=10; ++i){
        vec.push_back(make_shared<Bulk_Quote>("xixibook",i * 10.20, 10, 0.7));
        total += vec[i]->net_price(12);
    }
    
    cout << "vector<shared_ptr<Quote>> total : " << total << endl;
}
int main(){
    //test_print_total();

    //当我们使用容器存放存在继承体系的对象时，需要注意：
    //容器中应该存放指针或者智能指针，而非对象本身
    test_vector();

    cout <<"------------------" << endl;

    test_shared_ptr();
}