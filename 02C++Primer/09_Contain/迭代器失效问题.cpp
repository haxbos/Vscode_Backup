#include <iostream>
#include <vector>
using namespace std;

void test01(){
    vector<int> arr = {0,1,2,3,4,5,6,7,8,9};
    auto it = arr.begin() + 5;
    auto it2 = arr.begin() + 7;
    cout << "*it : " << *it << endl;
    cout << "it : " << &it << endl;

    cout << "it2 : " << &it2 << endl;
    cout << "*it2 : " << *it2 << endl;

    arr.insert(arr.begin()+6,0);
    for(auto num : arr) cout << num << " ";
    cout << endl;
    cout << "it : " << &it << endl;
    cout << "*it : " << *it << endl;

    cout << "it2 : " << &it2 << endl;
    cout << "*it2 : " << *it2 << endl;
}

void test02(){
	vector<int> q{ 1,2,3,4,5,6 };
	// 在这里想把大于2的元素都删除
	for (auto it = q.begin(); it != q.end(); it++) {
		if (*it > 2)
			q.erase(it); // 这里就会发生迭代器失效
	}
	// 打印结果
	for (auto it = q.begin(); it != q.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
int main(){
    //test01();
    test02();
}