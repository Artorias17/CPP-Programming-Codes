#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,a,b,c,d;
        cin>>n>>a>>b>>c>>d;
        int minG= (a - b) * n;
        int maxG= (a + b) * n;
        int minP = c - d;
        int maxP = c + d;
        if(minG<minP && maxG>=minP){
            cout<< "YES" << endl;
        }else if(minG>=minP && minG<=maxP){
            cout<< "YES" << endl;
        }else{
            cout<< "NO" <<endl;
        }
    }
    return 0;
}
