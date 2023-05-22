#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*给你一个长度为 n 的字符串数组 names 。你将会在文件系统中创建 n 个文件夹：在第 i 分钟，新建名为 names[i] 的文件夹。
由于两个文件 不能 共享相同的文件名，因此如果新建文件夹使用的文件名已经被占用，
系统会以 (k) 的形式为新文件夹的文件名添加后缀，其中 k 是能保证文件名唯一的 最小正整数 。
返回长度为 n 的字符串数组，其中 ans[i] 是创建第 i 个文件夹时系统分配给该文件夹的实际名称。
1 <= names.length <= 5 * 10^4
1 <= names[i].length <= 20
names[i] 由小写英文字母、数字和/或圆括号组成。*/

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ans;
        //q:为什么该程序既没有包含unordered_map头文件，也没有map头文件，却没有报错？
            unordered_map<string, int> m;
            for (auto &name : names) {
                if (m.count(name)) {
                    while (m.count(name + "(" + to_string(m[name]) + ")")) {
                        ++m[name];
                    }
                    ans.push_back(name + "(" + to_string(m[name]) + ")");
                    m[name + "(" + to_string(m[name]) + ")"]++;
                } else {
                    ans.push_back(name);
                    m[name] = 1;
                }
            }
        return ans;
    }
};

int main(){
    //写个示例，测试上面函数
    vector<string> names = {"gta","gta(2)","gta","gta","pes(2019)"};
    Solution s;
    vector<string> ans = s.getFolderNames(names);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}