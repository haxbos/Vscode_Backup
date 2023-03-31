#include <iostream>
#include <string>
using namespace std;

class Quote{
public:
    Quote() = default;
    Quote(const string& book, double p):bookNo(book),price(p){}
    string isbn() const { return bookNo; }
    
    //虚函数声明后必须定义
    virtual double net_price(size_t n) const{
        return n * price;
    };
    //virtual ~Quote() = default;
    ~Quote() = default;

protected:
    double price = 0;
private:
    string bookNo;
};

class Disc_Quote:public Quote{
public:
    Disc_Quote() = default;
    Disc_Quote(const string& book, double p, size_t qty, double disc):
        Quote(book,p), quantity(qty), discount(disc) {}
    virtual double net_price(size_t n) const override = 0;
protected:
    size_t quantity;
    double discount;
};

class Bulk_Quote : public Disc_Quote{
public:
    Bulk_Quote() = default;
    Bulk_Quote(const string& book, double p, size_t qty, double disc) :
        Disc_Quote(book, p, qty, disc) {}
    double net_price(size_t) const override;
};

double Bulk_Quote::net_price(size_t n) const{
    return n * price * (n < quantity ? discount : 1);
}

void print_total(ostream& os, const Quote& item, size_t n){
    double ret = item.net_price(n);

    os << "ISBN: " << item.isbn() << " # sold: " << n 
       << " total due: " << ret << endl;
}

int main(){
    Bulk_Quote bq("textbook", 10.60, 10, 0.8);
    print_total(cout, bq, 12);

    //不能定义抽象类
    //Disc_Quote dq("textbook", 10.60, 10, 0.8);
}