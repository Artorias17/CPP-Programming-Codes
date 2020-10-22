#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    int block;
    int num;
    cin>> t;
    vector<int> arr;
    while(t--){
        cin >> num;
        arr.clear();
        arr.resize(num, 0);
        block=0;
        for(int i=0; i < arr.size(); i++){
            cin >> num;
            if(num) arr[block++] = i;
        }
        block=0;
        for(int i=0; i+1<arr.size(); i++){
            if(arr[i+1]!=0){
                block+=arr[i+1]-arr[i]-1;
            }
        }
        cout << block << endl;
    }
    return 0;
}
