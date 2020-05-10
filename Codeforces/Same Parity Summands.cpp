#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int>ans;
        bool found=false;
        if(k>n){
            found=false;
        }
        else if(k==1){
            ans.push_back(n);
            found=true;
        }else if(n%2!=0){
            if(k%2!=0){
                found=true;
                for(int i=1; i<k; i++){
                    ans.push_back(1);
                    n--;
                }
                ans.push_back(n);
            }
        }else{
            if(k>n/2 && k%2==0){
                found=true;
                for(int i=1; i<k; i++){
                    ans.push_back(1);
                    n--;
                }
                ans.push_back(n);
            }else if(k<=n/2){
                found=true;
                for(int i=1; i<k; i++){
                    ans.push_back(2);
                    n-=2;
                }
                ans.push_back(n);
            }
        }
        if(found){
            cout<< "YES" << endl;
            for(int i=0; i<k-1; i++){
                cout<< ans[i] << " ";
            }
            cout<< ans[k-1] << endl;
        }else{
            cout<< "NO" << endl;
        }
    }
    return 0;
}

/*Logic:
 * Limits---
 * if k==n, then there will be k 1s
 * For k 1 through n/2 where n is even, there will be k-1 2s and one n-(2*(k-1))
 * as even is found by eiter odo+odd or even+even
 *
 * For n being odd, odd is found by odd+odd+odd or odd
 * So if k is odd then there will be k-1 1s and one n-(k-1).
 *
 * There can't be any solution for k>n
 */
