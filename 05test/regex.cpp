#include <iostream>
#include <string>
#include <regex>
using namespace std;

string method_;
string path_;
string version_;

bool testRegex(const string& line) {
    regex patten("^([^ ]*) ([^ ]*) HTTP/([^ ]*)$");
    smatch subMatch;
    if(regex_match(line, subMatch, patten)) {   
        method_ = subMatch[1];
        path_ = subMatch[2];
        version_ = subMatch[3];
        return true;
    }
    return false;
}

int main(){
    //string str = "GET /index.html HTTP/1.1";
    //string str = "GET / HTTP/1.1";
    string str = "GET  HTTP/1.1";
    if(testRegex(str)) {
        cout << "method: " << method_ << endl;
        cout << "path: " << path_ << endl;
        cout << "version: " << version_ << endl;
    }
    else{
        cout << "RequestLine Error" << endl;
    }
}