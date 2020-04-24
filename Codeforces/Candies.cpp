#include <bits/stdc++.h>
using namespace std;

int main() {
    long t;
    cin>>t;
    while(t--){
        long n;
        cin>>n;
        for(long i=2; true; i++){
            if(n%((long)pow(2, i)-1)==0){
                cout<< n/((long)pow(2, i)-1) << endl;
                break;
            }
        }
    }
    return 0;
}

/*logic:
 * Given,
 * x + 2x + ... + (2^(k-1))x= n
 * or x(Summation of 2^i from i=0 to i=k-1)=n
 * Using geometric summation
 * a=1, r=2, n=k-1+1
 * a((r^n)-1)/(r-1)= (2^k)-1 =n/x
 * or x= n/((2^k)-1)
 */
