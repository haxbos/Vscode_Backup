#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class InRange{
public:
    InRange(const size_t &lower, const size_t &upper):
        _lower(lower),_upper(upper){}
    
    bool operator()(const string& str) const{
        return str.size() >= _lower && str.size() <= _upper;
    }

    size_t lower_limit() const{
        return _lower;
    }

    size_t upper_limit() const{
        return _upper;
    }

private:
    size_t _lower;
    size_t _upper;
};

int main(){

    //创建各种具有上限的范围
    size_t lower = 1;
    auto uppers = {3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u};
    vector<InRange> vec;

    for(auto &upper : uppers)
        vec.emplace_back(InRange{lower,upper});
    
    //给map置0
    map<size_t,size_t> counts;
    for(auto &upper : uppers)
        counts[upper] = 0;

    //read file
    ifstream ifs("article.txt");
    for(string word; ifs >> word; ){
        for(auto is_in_range : vec){
            if(is_in_range(word)){
                ++counts[is_in_range.upper_limit()];
                //if(is_in_range.upper_limit() == 9u)  cout << word << endl;
                break;
            }
        }
    }

    //print
    for(auto pair : counts){
        cout << "count in range [1, " << pair.first << "] : " << pair.second << endl; 
    } 

}