#include <bits/stdc++.h>
using namespace std;

long num[500001];
void preCalc(){
    fill(num, num+500001, 1);
    num[1]=1, num[2]=3;
    long powerPlusOne;
    for(long i=4; i<500001; i+=2){
        powerPlusOne=0;
        while(i%(long)(pow(2, ++powerPlusOne))==0);
        num[i]*= (long)(pow(2, powerPlusOne) - 1);
    }
    long lim=500000/2;
    for(long i=3; i<=lim; i+=2){
        if(num[i]==1){
            num[i]=1+i;
            for(long j=i*2; j<500001; j+=i){
                powerPlusOne=0;
                while(j%(long)(pow(i, ++powerPlusOne))==0);
                num[j]*= (long)(pow(i, powerPlusOne)-1)/(i-1);
            }
        }
    }
    for(long i=lim+2; i<500001; i++){
        if(num[i]==1) num[i]=1+i;
    }
}
int main() {
    preCalc();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long t, n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<< num[n]-n<< endl;
    }
    return 0;
}

/*Logic:
 * We know that number of divisors can be found by
 * the product of each prime's (power+1)
 *
 * Now these divisors are in the form
 * (prime1^x)*(prime2^y)*(prime3^z)*...*(primeN^somePower)
 * Let that be comb1
 * Summation of the divisors is
 * comb1+comb2+comb3...+combN
 * ((prime1^0)*...*(prime1^somePower))*...*((primeN^0)*...*(primeN^somePower))
 * (1(prime1^(power+1))-1)/(prime1-1))*..*(1(primeN^(power+1))-1)/(primeN-1))
 * Therefore, product of geometric summation of all prime divisors for their
 * respective (power+1) terms gives us the summation of divisors.
 */
