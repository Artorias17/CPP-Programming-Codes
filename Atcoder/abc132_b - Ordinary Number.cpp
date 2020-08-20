#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    int arr[t];
    for(int i=0; i<t; i++){
        cin>>arr[i];
    }
    int counter=0;
    for(int i=1; i<t-1; i++){
        if(arr[i]>min(arr[i-1], arr[i+1]) && arr[i]<max(arr[i-1], arr[i+1])) counter++;
    }
    cout << counter << endl;
    return 0;
}
