#include <bits/stdc++.h>
using namespace std;
bool prime[1000001];
void seive(){
    int lim=sizeof(prime)/ sizeof(prime[0]);
    fill(prime, prime+lim, true);
    prime[0]=prime[1]=false;
    for(int i=4; i<lim; i+=2){
        prime[i]=false;
    }
    for(int i=3; i<sqrt(lim); i+=2){
        if(prime[i]){
            for(int j=i*i; j<lim; j+=i+i){
                prime[j]=false;
            }
        }
    }
}
long coprime(long v){
    if((v<1000001 && prime[v])||(v==1)) return --v;
    long ans=v;
    double lim=sqrt(v);
    for(long i=2; i<=lim && v>=i; i+=2){
        if(prime[i] && v%i==0){
            ans*=(1-(1.0/i));
            long power=0;
            while (v%(long)pow(i, power+1)==0) power++;
            v/=(long)pow(i, power);
        }
        if(i==2) i--;
    }
    if(v!=1) ans*=(1-(1.0/v));
    return ans;
}
int main() {
    seive();
    long n;
    while(cin>>n && n!=0){
        cout << coprime(n) << endl;
    }
}

/* Logic:
 * Two numbers are coprimes when their gcd is 1.
 * Therefore, we have to find the numbers whose gcd is not 1 with N
 * and these numbers are always multiples of prime factors of N.
 * So, if N=p1*p2*p3*...
 * Then, number of coprimes of N smaller than N is
 * N- (N/p1) - (N/p2) - (N/p3)
 * Here, some numbers were cancelled out multiple times.
 * For that we have to compensate such that those numbers are cancelled
 * one time only. To do that we have to add (N/C) where C is product of 
 * prime numbers in different combinations.
 * Finally, all this can be simplified by the formula
 * number of coprimes less than N= N(1-(N/p1))(1-(N/p2))(1-(N/p3))...
 */
