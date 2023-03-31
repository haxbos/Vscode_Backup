#include <iostream>
#include <set>
#include <string>
#include <memory>
#include <typeinfo>
#include <cxxabi.h>
using namespace std;

class Quote;
double print_total(ostream& os, const Quote& item, size_t n);

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

class Basket{
public:
    void add_item(const shared_ptr<Quote> &sale){
        items.insert(sale);
    }

    double total_receipt(ostream&) const;

private:
    static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs){
        return lhs->isbn() < rhs->isbn();
    }

    multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double Basket::total_receipt(ostream &os) const{
    double sum = 0.0;
    
    for(auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
        sum += print_total(os, **iter, items.count(*iter));
    
    os << "Total Sale: " << sum << endl;
    return sum;
}

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

double print_total(ostream& os, const Quote& item, size_t n){
    double ret = item.net_price(n);

    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: "
    << ret << endl;
    
    return ret;
}

int main(){
    Basket bsk;
    bsk.add_item(make_shared<Quote>("make_shared<Quote>", 50));
    bsk.add_item(make_shared<Bulk_Quote>("make_shared<Bulk_Quote>", 50, 2, 0.25));
    bsk.add_item(make_shared<Bulk_Quote>("make_shared<Bulk_Quote>", 50, 2, 0.25));
    bsk.add_item(make_shared<Bulk_Quote>("make_shared<Bulk_Quote>", 50, 2, 0.7));
    bsk.add_item(make_shared<Bulk_Quote>("make_shared<Bulk_Quote>", 50, 2, 0.7));
    bsk.total_receipt(cout);
    return 0;
}