#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//一行一行储存
void readFileToVec(const string &fileName, vector<string> &vec){
    ifstream ifs(fileName);
    if(ifs){
        string buff;
        while(getline(ifs,buff)){
            vec.push_back(buff);
        }
    }
}

//以单词存储
void readFileToVec2(const string &fileName, vector<string> &vec){
    ifstream ifs(fileName);
    if(ifs){
        string buff;
        while(ifs >> buff){
            vec.push_back(buff);
        }
    }
}
int main(){
    string fileName = "fileName.txt";
    vector<string> vec;
    //readFileToVec(fileName,vec);

    readFileToVec2(fileName,vec);
    for(auto str : vec){
        cout << str << endl;
    }
}