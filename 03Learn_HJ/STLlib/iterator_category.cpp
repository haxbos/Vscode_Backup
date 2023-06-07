#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <typeinfo>
#include <type_traits>
using namespace std;

void _display_category(random_access_iterator_tag){
    cout << "\t\trandom_access_iterator_tag" << endl;
}

void _display_category(bidirectional_iterator_tag){
    cout << "\t\tbidirectional_iterator_tag" << endl;
}

void _display_category(forward_iterator_tag){
    cout << "\t\tforward_iterator_tag" << endl;
}

void _display_category(input_iterator_tag){
    cout << "\t\tinput_iterator_tag" << endl;
}

void _display_category(output_iterator_tag){
    cout << "\t\toutput_iterator_tag" << endl;
}

template<typename I>
void display_category(I iter){
    cout << typeid(iter).name() << ": ";
    typename iterator_traits<I>::iterator_category cagy;
    _display_category(cagy);
}

void test_category(){
    cout << "test_iterator_category: " << endl;
    cout << "array<int, 10>::iterator: ";
    display_category(array<int, 10>::iterator());
    cout << "vector<int>::iterator: ";
    display_category(vector<int>::iterator());
    cout << "list<int>::iterator: ";
    display_category(list<int>::iterator());
    cout << "deque<int>::iterator: ";
    display_category(deque<int>::iterator());
    cout << "forward_list<int>::iterator: ";
    display_category(forward_list<int>::iterator());
    cout << "set<int>::iterator: ";
    display_category(set<int>::iterator());
    cout << "multiset<int>::iterator: ";
    display_category(multiset<int>::iterator());
    cout << "map<int, int>::iterator: ";
    display_category(map<int, int>::iterator());
    cout << "multimap<int, int>::iterator: ";
    display_category(multimap<int, int>::iterator());
    cout << "unordered_set<int>::iterator: ";
    display_category(unordered_set<int>::iterator());
    cout << "unordered_multiset<int>::iterator: ";
    display_category(unordered_multiset<int>::iterator());
    cout << "unordered_map<int, int>::iterator: ";
    display_category(unordered_map<int, int>::iterator());
    cout << "unordered_multimap<int, int>::iterator: ";
    display_category(unordered_multimap<int, int>::iterator());
    
    cout << "istream_iterator<int>: ";
    display_category(istream_iterator<int>());
    cout << "ostream_iterator<int>: ";
    display_category(ostream_iterator<int>(cout, ""));
}

int main(){
    test_category();
    return 0;
}
