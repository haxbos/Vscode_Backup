#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

template<typename Container>
ostream& print(const Container& ct, ostream& os = cout){
    for(typename Container::size_type i = 0; i != ct.size(); ++i){
        os << ct[i] << " ";
    }
    return os;
}

template<typename Container>
ostream& print_it(const Container& ct, ostream& os = cout){
    for(auto it = ct.cbegin(); it != ct.cend(); ++it){
        os << *it << " ";
    }
    return os;
}

int main(){
    vector<int> vec = {5,9,3,7,1,4,2,8,6};
    list<string> lst = {"hello", "world", "!"};

    print(vec) << endl;
    
    print_it(vec) << endl;
    print_it(lst) << endl;
    return 0;
}