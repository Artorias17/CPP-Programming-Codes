#include <bits/stdc++.h>
using namespace std;
int main() {
    long t;
    cin>>t;
    while(t--){
        long a, b;
        cin>>a>>b;
        if(__gcd(a, b)==a && (a*b)/__gcd(a, b)==b){
            cout<< a << " " << b << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}
