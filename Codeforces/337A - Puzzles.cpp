#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int c, p;
    cin>>c>>p;
    int arr[p];
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        cin>>arr[i];
    }
    sort(arr, arr+sizeof(arr)/sizeof(arr[0]));
    int diff=INT32_MAX;
    for(int i=0; i<sizeof(arr)/sizeof(arr[0])-c+1; i++){
        diff=min(diff, abs(arr[i]-arr[i+c-1]));
    }
    cout << diff << endl;
    return 0;
}
