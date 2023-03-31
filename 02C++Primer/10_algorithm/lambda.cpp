#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void elimDups(vector<string> &arr){
    sort(arr.begin(),arr.end());
    auto new_end = unique(arr.begin(),arr.end());
    arr.erase(new_end,arr.end());
}

void biggies(vector<string> &words, size_t sz){
    elimDups(words);

    stable_sort(words.begin(),words.end(),[](const string &a, const string &b){
        return a.length() < b.length();
    });

    auto wc = find_if(words.begin(),words.end(),[sz](const string &a){
        return a.length() >= sz;
    });

    for_each(wc,words.end(),[](const string &s){
        cout << s << " ";
    });    
}
int main(){
    vector<string> words = {"12345","123","12322224","hi~", "alan", "alan", "cp","xixixhaha"};
    size_t sz = 5;
    biggies(words,sz);
}