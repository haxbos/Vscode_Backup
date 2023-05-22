#include <iostream>
using namespace std;
int arr[200010];
int N;

int main(){
    cin >> N;
    int sum = 0;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
        sum += arr[i];
        if(arr[i] == 0){
            if((sum % 2) != 0){
                cout << "NO" <<endl;
                return 0;
            }
            else{
                sum = 0;
            }
        }
    }
    if((sum % 2) != 0) cout << "NO" <<endl;
    else cout << "YES" <<endl;
}