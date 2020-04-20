#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int f91(int n){
    if(arr[n]!=INT_MIN){
        return arr[n];
    }
    else if(n>=101){
        arr[n]=n-10;
        return arr[n];
    }else{
        return f91(f91(n+11));
    }
}
int main() {
    fill(arr+0, arr+1000001, INT_MIN);
    int n;
    while (cin>>n && n!=0){
        cout << "f91("<< n << ") = " <<f91(n) << endl;
    }
    return 0;
}
