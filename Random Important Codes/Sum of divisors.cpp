#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

bool prime[1000001];
void primes(){
    memset(prime + 0, true, sizeof(prime));
    prime[1]=false, prime[0]=false;
    for(int i=4; i<1000001; i+=2){
        prime[i]=false;
    }
    for(int i=3; i<=sqrt(1000001); i+=2){
        if(prime[i]){
            for(int j=i*i; j<1000001; j+=i+i){
                prime[j]=false;
            }
        }
    }
}

void run(int value, int end){
    double geoSum;
    while(value <= end){
        if(value==0) geoSum=0;
        else if(value==1) geoSum=1;
        else if(value > 1){
            geoSum=1;
            int curPow=0, lim=sqrt(value), i=value;
            for(int div=2; div<=lim;){
                if(prime[div] && i%div==0){
                    i/=div;
                    curPow++;
                }else{
                    if(curPow!=0) {
                        geoSum *= (1 * (pow(div, curPow + 1) - 1)) / (div - 1);
                        curPow = 0;
                    }
                    if(div==2)div++;
                    else div += 2;
                }
            }
            if(i!=1) geoSum *= (1 * (pow(i, 2) - 1)) / (i - 1);
        }
        cout << value << " = " << (long)geoSum << endl;
        value++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<< "Enter start and end numbers" << endl;
    int s, e;
    cin>>s>>e;
    auto NOW0=high_resolution_clock::now();
    primes();
    run(s, e);
    auto NOW1=high_resolution_clock::now();
    auto Time=duration_cast<milliseconds>(NOW1-NOW0);
    cout<< "Execution Time" << Time.count() << "ms" << endl;
    return 0;
}

/*Logic:
 * We know that number of divisors can be found by
 * the product of each prime's (power+1)/
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
