#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        long long int a=(long long int)pow(2, n);
        long long int b=0;
        for(int i=1; i<n/2; i++){
            a+=(long long int)pow(2, i);
        }
        for(int i=n/2; i<n; i++){
            b+=(long long int)pow(2, i);
        }
        cout<<abs(a-b) << endl;
    }
}
/*
 * Logic:
 * For pile a-  put the heaviest coin along with n/2 lightest coins.
 * For pile b- put the rest n/2 coins.
 * Idea is that is the least difference between pile a and b without restriction
 * would be 2 by putting the heaviest weighted coin in one pile and the rest in the other.
 */
