#include <bits/stdc++.h>
using namespace std;
bool prime[1001];
void seive(){
    int l=sizeof(prime)/sizeof(prime[1]);
    memset(prime, true, sizeof(prime));
    prime[0]=prime[1]=false;
    for(int a=4; a<l; a+=2){
        prime[a]=false;
    }
    for(int b=3; b<=sqrt(l); b+=2){
        if(prime[b]){
            for(int a=b*b; a<l; a+=b+b){
                prime[a]=false;
            }
        }
    }
}
/*Logic:
 * We know sum of divisors= Product of (pow(primeN, power+1)-1)/(primeN-1)
 * where primeN is the nth prime factor.
 * Or simply, sum of divisors= Product of geometric sum of primeN till power+1 th term
 * Lets call this geoSum of PrimeN.
 * Then, sum/product of geoSum of PrimeN=1
 * The recursive function below checks if sum is divisible geoSum of primeN.
 * If so then re calls the method with sum being sum/geoSum of primeN.
 * The argument "startPrime" is used to start checking from that prime.
 * It returns the maximum number at each call by multiplying the
 * argument "number"  with pow(current prime, power).
 */
int run(int sum, int startPrime, int number){
    if(sum==1){
        return number;
    }else{
        int num=-1;
        for(int i=startPrime; i < sum; i+=2){
            if(i==2) startPrime=3;
            else startPrime+=2;
            if(prime[i]){
                int p=1;
                int geoSum=(int)(pow(i, p+1)-1)/(i-1);
                while(sum/geoSum!=0){
                    if(sum%geoSum==0){
                        num=max(run(sum/geoSum, startPrime, number * (int)(pow(i, p))), num);
                    }
                    p++;
                    geoSum=(int)(pow(i, p+1)-1)/(i-1);
                }
            }
            if(i==2) i--;
        }
        return num;
    }
}
int main() {
    seive();
    int sum, i=1;
    while(scanf("%d", &sum) && sum!=0){
        printf("Case %d: %d\n", i, run(sum, 2, 1));
        i++;
    }
    return 0;
}
