#include <bits/stdc++.h>
using namespace std;
long long int fac[21];
int main(){
    fac[0]=1;
    fac[1]=1;
    for(int i=2; i<=20; i++){
        fac[i]=fac[i-1]*i;
    }
    int t;
    cin>>t;
    for(int s=1; s<=t; s++){
        long n;
        cin>>n;
        string ans="";
        for(int i=20; i>=0; i--){
            if(n>=fac[i]){
                ans=to_string(i)+"!+"+ans;
                n-=fac[i];
            }
        }

        cout<< "Case "<< s <<": ";
        if(n==0){
            cout<< ans.substr(0, ans.size()-1) << endl;
        }else{
            cout<< "impossible" << endl;
        }
    }
    return 0;
}
