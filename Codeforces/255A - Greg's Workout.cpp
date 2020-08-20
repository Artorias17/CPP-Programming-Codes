#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int t;
    cin>>t;
    int arr[3];
    memset(arr, 0, sizeof(arr));
    int i=0, maxIndex=0, temp;
    while(t--){
        cin>>temp;
        arr[i]+=temp;
        if(arr[i]>arr[maxIndex]) maxIndex= i;
        i=(i+1)%3;
    }

    switch (maxIndex) {
        case 0:
            cout << "chest";
            break;
        case 1:
            cout << "biceps";
            break;
        case 2:
            cout << "back";
            break;
        default:
            break;
    }
    cout << endl;
    return 0;
}
