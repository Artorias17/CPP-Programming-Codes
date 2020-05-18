#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        long long int n, m;
        cin>>n>>m;
        if(n==1){
            cout<< 0 << endl;
        }else if(n==2){
            cout << m << endl;
        }else{
            cout << 2*m << endl;
        }
    }
    return 0;
}

/*Logic:
 * If array size is 1, there is no way to find absolute difference,
 * so answer will be 0.
 * If array size is 2, then the the the array is [0, m].
 * So, the summation of absolute difference that is maximized is m.
 * If array size is greater than 2, then the array can be formed by
 * [0, m, 0, ....]. This gives the summation of absolute difference
 * as abs(0-m)+abs(m-0)+.... This is the maximized so answer is 2*m.
 */
