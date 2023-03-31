#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

map<string,string> buildMap(ifstream &map_life){
    map<string,string> hash;
    string m_key,m_value;
    
    while(map_life >> m_key && (getline(map_life,m_value))){
        if(m_value.size() > 1)  hash[m_key] = m_value.substr(1);    //去掉前面空格
        else throw runtime_error("no rule for " + m_key);
    }
    return hash;
}

void word_transform(ifstream &map_life , ifstream &input){
    auto trans_map = buildMap(map_life);
    string text;
    
    while(getline(input, text)){
        string word;
        istringstream stream(text);
        bool firstword = true;
        while(stream >> word){
            if(firstword)   firstword = false;
            else cout << " ";

            if(trans_map.find(word) == trans_map.end()) cout << word;
            else cout << trans_map[word];
        }
        cout << endl;
    }
}

int main(){
    ifstream map_life("map_life.txt");
    ifstream input("input.txt");
    word_transform(map_life, input);
}