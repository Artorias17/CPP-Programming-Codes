#include <bits/stdc++.h>
using namespace std;
long long int doMath(int b, int a, long long l, long long r){ //b=bigger divisor, a=smaller divisor
    long long int LCM=(a*b)/__gcd(a,b);
    long long int ans=(r/b)-(l/b); //Number of multiples of b between l and r
    ans-=(r/LCM)-(l/LCM); // Excluding number of multiples of both a and b between l and r
    ans*=b; //Number of numbers where x % a % b != x % b % a
    if((l/b)*b<=l && ((l/b)*b)%a!=0){
        ans+=b-(l-((l/b)*b)); //Adding those  numbers near l which were not included
    }
    if((r/b)*b<=r && ((r/b)*b)%a!=0){
        ans-=b; //Excluding the one near r as not all numbers will be in the range
        ans+=r-((r/b)*b)+1; //Adding those extra ones in range back.
    }
   return ans;
}
int main() {
    int t,a,b,q;
    long long l, r;
    cin>>t;
    while(t--){
        cin>>a>>b>>q;
        vector<long long int> ans;
        while(q--){
            cin>>l>>r;
            if(a>b){
                ans.push_back(doMath(a, b, l, r));
            }else{
                ans.push_back(doMath(b, a, l, r));
            }
        }
        cout<< ans[0];
        for(int i=1; i<ans.size(); i++){
            cout<< " " << ans[i];
        }
        cout<< endl;
        ans.clear();
    }
    return 0;
}

/* Logic:
 * remainders of a = 0 .... a-1
 * remainders of b= 0 ... b-1
 * If any number, x is multiple of both a and b,
 * then max(a, b) of numbers including x
 * will result in x%a%b==x%b%a.
 * However, x, which are multiples of max(a, b)
 * and which are not multiples of min(a, b)
 * will have max(a, b) numbers including x
 * that fulfill the condition of x%a%b!=x%b%a.
 */
