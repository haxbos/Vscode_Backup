#include <iostream>
#include <string>
#include <typeinfo>
#include <cxxabi.h>
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

    // virtual void Debug() const{
    //     cout << "Data members of " << typeid(*this).name() << " \n"
    //          << "bookNo : " << this->bookNo
    //          << "\nprice : " << this->price << endl;
    // }

    virtual void Debug() const {
        int status;
        std::string name = abi::__cxa_demangle(typeid(*this).name(), nullptr, nullptr, &status);
        std::cout << "Data members of " << name << "\n"
                << "bookNo : " << this->isbn() << "\n"
                << "price : " << this->price << "\n";
    }

    virtual ~Quote() = default;
    //~Quote() = default;

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

    //return ret;
}

void print_debug(const Quote& item){
    item.Debug();
}

void test_debug(){
    Quote q("aaa",12);
    Bulk_Quote bq("bbb",12,10,0.7);


    Quote& r = q;
    print_debug(r);

    r = bq;
    print_debug(r);

    print_debug(q);
    print_debug(bq);
}

void test_print_total(){
    Quote q("textbook",10.60);
    Bulk_Quote bq("textbook",10.60, 10, 0.7);

    print_total(cout, q, 12);
    print_total(cout, bq, 12);
}

int main(){
    test_debug();
    //test_print_total();
}