#include <bits/stdc++.h>
using namespace std;

static bool p[31624];
static int len=sizeof(p)/ sizeof(p[0]);
void runSeive(){
    int sqr=(int)sqrt(sizeof(p)/ sizeof(p[0]));
    memset(p, true, sizeof(p));
    p[0]=false, p[1]=false;
    for(int i=4; i<len; i+=2) p[i]=false;
    for(int i=3; i<=sqr; i+=2){
        if(p[i]){
            for(int j=i*i; j<len; j+=i+i) p[j]=false;
        }
    }
}
long numberOfCoprime(long n){
    if(n<len && p[n]) return n-1;
    long coP=n, power=0;
    if(n%2==0){
        coP*=0.5;
        while(n%(long)pow(2, power+1)==0) power++;
        n/=(long)pow(2, power);
    }
    for(int i=3; i <= sqrt(n); i+=2){
        if(p[i] && n%i==0){
            coP*=(1-(1.0/i));
            power=0;
            while(n%(long)pow(i, power+1)==0) power++;
            n/=(long)pow(i, power);
        }
    }
    if(n!=1) coP*=(1-(1.0/n));
    return coP;
}
int main() {
    runSeive();
    int n;
    while(cin>>n && n!=0){
        cout<< numberOfCoprime(n) << endl;
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
 * out one time only. To do that we have to add (N/C) where C is product of
 * prime numbers in different combinations.
 * Finally, all this can be simplified by the formula
 * number of coprimes less than N= N(1-(N/p1))(1-(N/p2))(1-(N/p3))...
 */
