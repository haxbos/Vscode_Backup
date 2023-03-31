#include <iostream>
#include <string>
#include <vector>
using namespace std;

class GetInput{
public:
    GetInput(istream &i = cin): is(i){}

    string operator()() const{
        string str;
        getline(is,str);
        return is ? str : string();
    }
private:
    istream &is;
};

int main(){
    vector<string> vs;
    GetInput gi;
    //cout << gi() << endl;

    for(string tmp; !((tmp = gi()).empty()); vs.emplace_back(tmp));

    for(auto &str : vs)
        cout << str << endl;
}