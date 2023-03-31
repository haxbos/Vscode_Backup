#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class PersonInfo{
public:
    string m_name;
    vector<string> m_phone;
};

int main(){
    string line, word;
    fstream ifs("phone.txt",fstream::in);

    vector<PersonInfo> people;

    while(getline(ifs,line)){
        PersonInfo info;
        istringstream record(line);
        record >> info.m_name;
        while(record >> word){
            info.m_phone.push_back(word);
        }
        people.push_back(info);
    }

    for(auto n : people){
        cout <<"Name : " << n.m_name << " ";
        cout << n.m_phone.size() << "#" << endl;
        for(auto phone : n.m_phone)
            cout << phone << " ";
        cout << endl;
        cout << endl;
    }
}