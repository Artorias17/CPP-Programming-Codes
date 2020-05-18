#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int ans, t, n;
    cin>>t;
    while(t--){
        cin>>n;
        n=n/2;
        ans=0;
        for(long long int i=1; i <=n; i++){
            ans+=(8*i*i);
        }
        cout << ans << endl;
    }
    return 0;
}

/*Logic:
 * Best place to bring all te figures is at the centre.
 * When n=3, there are 8 blocks surrounding the centre that requires 1 move.
 * When n=5, there are 8 blocks surrounding the centre that requires 1 move
 * and there are 16 blocks surrounding that that requires 2 moves to get to centre.
 * So, a pattern is found
 * (8*1)+ (16*2) + (24*3)+...
 * (8*1*1) + (8*2*2) + (8*3*3)+...
 * When n=1, max moves=0
 * When n=3, max moves=1
 * When n=5, max moves=2
 * So max moves= floor(n/2)
 * Thus, the summation becomes (8*1*1) + (8*2*2) + (8*3*3)+...+(8*maxMove*maxMove)
 *
 * Misc:
 * Had issue with type casting
 */
