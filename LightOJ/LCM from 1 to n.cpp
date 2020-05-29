#include <bits/stdc++.h>
#define MAXN 100000001
#define PrimeNumbers 5761457
using namespace std;


unsigned int primeList[PrimeNumbers];
unsigned int ProductOfPrimeToThePower1[PrimeNumbers];
bitset<MAXN>notPrime(0);

void seive(){
    int PrimeListIterator=0;
    notPrime[0]=true;
    notPrime[1]=true;
    primeList[PrimeListIterator++]=2;
    for(int i=4; i<MAXN; i+=2){
        notPrime[i]=true;
    }

    for(int i=3; i<=MAXN; i+=2){
        if(!notPrime[i]){
            primeList[PrimeListIterator++]=i;
            if(i<=sqrt(MAXN)){
                for(int j=i*i; j<MAXN; j+=i+i){
                    notPrime[j]=true;
                }
            }
        }
    }
}

void pre_Calc(){
    ProductOfPrimeToThePower1[0]=primeList[0];
    for(int i=1; i<PrimeNumbers; i++){
        ProductOfPrimeToThePower1[i]=ProductOfPrimeToThePower1[i - 1] * primeList[i];
    }
}

unsigned int calculateLCM(int n){
    auto indexForLastPrime=upper_bound(primeList, primeList+PrimeNumbers, n)-primeList-1;
    unsigned int answer=ProductOfPrimeToThePower1[indexForLastPrime];
    unsigned int working;
    for(unsigned int i=0; primeList[i]<=(unsigned int)sqrt(n); i++){
        working=n/primeList[i];
        while(working/primeList[i]>0){
            answer*=primeList[i];
            working/=primeList[i];
        }
    }
    return answer;
}
int main() {
    seive();
    pre_Calc();
    int t;
    int n;
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        scanf("%d", &n);
        printf("Case %d: %u\n", i, calculateLCM(n));
    }
    return 0;
}

/*Logic:
 * The idea is simple, we are required to find the LCM from 1 to N.
 * LCM of multiple numbers is found by
 * P1^H1*P2^H2*P3^H3*P4^H4... where P=prime number and H=It's highest power
 * Due to time and space constraint normal approach didn't work.
 * Therefore, initially bitset of size 10^8 is used as it uses 1 bit for each index.
 * Along with that an array of primes, and an array of product of prefix primes
 * was initialized. The size of these arrays was 5761457 as 5761457 many primes
 * are there in the range.
 *
 * Next ran seive, and every primes were put in primes array.
 * Next from these primes, generated the prefix product array
 * such that prefixPrduct[i]=prefixProduct[i-1]*prime[i].
 * Idea behind this is that, for any number n, primes less than
 * or equal to sqrt(n) will have power greater than 1. This helps
 * reduce the time cost for finding the product of all primes after
 * sqrt(n).
 *
 * Next, for every n, using upper bound on the array, found the pointer
 * for the index of prime array, where the value is strictly greater than
 * n. Subtracting the pointer for the prime array gives us the actual prime
 * array index. Since this index holds the strictly greater value, then index-1
 * holds the last prime of n.
 *
 * Since, the highest power of primes less than or equal to  of sqrt(n) are not
 * known, traversal through those primes and finding the highest power -1 is
 * required. -1 because the prefix product for the last prime of n, has the
 * product of primes^1. So multiplying prime^highestPower-1 to the prefix product
 * will produce the answer.
 *
 * As mod operation is slow, unsigned int is used as this will automatically discard
 * the carry bit when 2^32 is reached, acting as a mod opeator.
 *
 * MISC:
 * vectors take up more space than arrays.
 * Upper bound function greatly reduces time complexity.
 * Macro (define) reduced space complexity.
 * bitwise seive reduces space.
 */
