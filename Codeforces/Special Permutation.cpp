#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int count=0;
        if(n>3){
            for(int i=(n%2==0)? n-1 : n; i>0; i-=2){
                cout<< i << " ";
                count++;
            }
            cout<< 4;
            for(int i=2; i<=n; i+=2){
                if(i!=4){
                    cout << " " << i;
                }
            }
            cout<< endl;
        }else{
            cout<< -1 << endl;
        }
    }
    return 0;
}

/*Logic:
 * Put all odd numbers in decreasing order.
 * Then put 4 and 2.
 * After that put all even numbers from 6 in ascending order.
 */
