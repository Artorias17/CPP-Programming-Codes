#include <bits/stdc++.h>
using namespace std;

bool prime[1000001];

//Finding prime numbers
void seive(){
    long size= sizeof(prime) / sizeof(prime[0]);
    fill(prime + 0, prime + size, true);
    prime[0]= prime[1]=false;
    for(int i=4; i<size; i+=2){
        prime[i]=false;
    }

    for(int i=3; i<=sqrt(size); i+=2){
        if(prime[i]){
            for(int j=i*i; j<size; j+=2*i){
                prime[j]=false;
            }
        }
    }
}

int numberOfDivisors(long number){
    vector<int> p; //Prime factorization for the number

    for(int i=2; i<=sqrt(number);){
        if(prime[i] && number%i==0){
            number/=i;
            p.push_back(i);
        }else if(i==2){
            i++;
        }else{
            i+=2;
        }
    }
    //if number is not a perfect square then add the current number as it is prime
    if(floor(sqrt(number))!=ceil(sqrt(number))){
        p.push_back(number);
    }

    //Finding the number of combinations by multiplying each prime's (power+1)
    int combinations=1;
    int pow=1;
    for(int i=1; i<p.size(); i++){
        if(p[i-1]==p[i]){
            pow++;
        }else{
            combinations*=(pow+1);
            pow=1;
        }
    }
    combinations*=(pow+1);
    //Excluding (prime1^0)*(prime2^0)*(prime3^0)*...*(primeN^0) which equals to 1
    combinations--;
    return combinations;
}

int main() {
    seive();
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        long n;
        cin >> n;
        if(n!=1){
            printf("Case %d: %d\n", i, numberOfDivisors(n));
        }else{
            printf("Case %d: 0\n", i);
        }
    }
}

/*
 *Logic:
 * Using prime factorization to find the prime numbers.
 * Then multiplying each prime's (power+1) to get the number of combinations.
 *
 * (power+1) is used because (prime^0) gives 1 which when multiplied with
 * the rest part of the primes in some combination gives some of the divisors.
 *
 * Example:- 36= 2*2*3*3= (2^2)* (3^2)
 * Then number of divisors= (2+1)* (2+1)= 9
 * the number of divisors are 1, 2, 3, 4, 6, 9, 12, 18, 36
 */
