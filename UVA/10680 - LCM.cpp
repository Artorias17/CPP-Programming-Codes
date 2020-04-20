#include <bits/stdc++.h>
using namespace std;
bool isPrime[1000001];
void seive(){
    int max=1000001;
    int limit=sqrt(1000000);
    fill(isPrime + 0, isPrime + max, true);
    isPrime[0]= false, isPrime[1]= false;
    for(int i=4; i<max; i+=2){
        isPrime[i]=false;
    }
    for(int i=3; i<=limit; i+=2){
        if(isPrime[i]){
            for(int j=i*i; j<max; j+=i+i){
                isPrime[j]= false;
            }
        }
    }
}
long findLCM(long v){
    long powof2=floor(log(v)/log(2));
    long powof5=floor(log(v)/log(5));
    powof2-=min(powof2, powof5);
    powof5-=min(powof2, powof5);
    long ans=(((long)pow(2, powof2)%10)*((long)pow(5, powof5)%10))%10;
    for(int i=3; i<=v;){
        if(isPrime[i]){
            long curPow=floor(log(v)/log(i));
            ans*=(((long)pow(i, curPow)%10));
            ans%=10;
        }
        if(i==3) i=7;
        else i+=2;
    }
    return ans%10;
}

int main() {
    seive();
    long n;
    while(cin>>n && n!=0){
        cout << findLCM(n) << endl;
    }
}

/*Logic:
 * Using seive to find the primes.
 * We know lcm(a, b)= a*b/gcd(a, b).
 * As gcd is 1 across all the numbers,
 * then lcm will the product of prime^maximum power
 * from the range 1 through n.
 * One way of finding maxmum power= floor(ln(n)/ln(prime))
 */
