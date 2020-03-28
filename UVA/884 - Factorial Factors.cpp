#include <bits/stdc++.h>
using namespace std;

static const int primeLen=1000001;
static bool prime[primeLen];
void seive(){
    fill(prime+0, prime+primeLen, true);
    prime[0]= prime[1]=false;
    for(int i=4; i<primeLen; i+=2){
        prime[i]=false;
    }

    for(int i=3; i<=sqrt(primeLen); i+=2){
        if(prime[i]){
            for(int j=i*i; j<primeLen; j+=2*i){
                prime[j]=false;
            }
        }
    }
}
static int look[1000001];
void preCalculate(){
    memset(look, 0, sizeof(look));
    for(int i=2; i<1000001; i++){
        look[i]=look[i-1];
        if(prime[i]){
            look[i]++;
        }else{
            int val=i;
            double limit=sqrt(val);
            for(int j=2; j<=limit;){
                if(val==1) break;
                if(prime[j] && val%j==0){
                    look[i]++;
                    val/=j;
                }else{
                    if(j==2) j++;
                    else j+=2;
                }
            }
            if(val!=1) look[i]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive();
    preCalculate();
    int given,count;
    while(cin >> given){
        cout << look[given] << endl;
    }
    return 0;
}

/* Logic
 * Find the primes using seive.
 * Then pre-calculate for all the numbers by adding the number of prime divisors
 * the previous number has with the number of prime divisors it has and continuing
 * this chain of operation till the last number.
 */
