#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int t;
    cin>>t;
    while(t--){
        long long int n, k;
        cin>>n>>k;
        auto sqrtN= (long long int)floor(sqrt(n));
        long long int package=0;
        for(long long int i=1; i<=sqrtN; i++){
            if(n%i==0){
                if(i>package && i<=k){
                    package=i;
                }
                if((n/i)>package && (n/i)<=k){
                    package=n/i;
                }
            }
        }
        cout << n/package << endl;
    }
    return 0;
}

/*Logic:
 * All we need to do is search from 1 to sqrt(n).
 * If we find a divisor for n. Then we are going to choose
 * for all the pairs of divisors found, the largest one that
 * is within the range of k. This will be the package.
 * Then answer will be n/package.
 *
 * Misc:
 * It may seem ideal to just iterate over 2 to sqrt(n)
 * output the first number which is a factor of n
 * and its counterpart is less than or equal to k.
 * However, assume a case where n=14 and k=2.
 * 14=1, 2, 7, 14. floor(sqrt(14))=3. When it sees 2
 * as a factor but fails as 7>k, its going to discard the
 * actual answer.
 */
