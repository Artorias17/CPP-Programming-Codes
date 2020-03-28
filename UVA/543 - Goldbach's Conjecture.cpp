#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

bool isPrime(int x){
    if(x==1 || x==0){
        return false;
    }
    if(find(primes.begin(), primes.end(), x)!=primes.end()){
        return true;
    }

    for(int i=2; i<=sqrt(x); i++){
        if(x%i==0){
            return false;
        }
    }

    primes.push_back(x);
    return true;
}

int main() {
    int n;
    while(cin>> n && n!=0){
        bool done= false;
        for (int i=2; i <=n/2;) {
            if (isPrime(i) && isPrime(n-i)) {
                done=true;
                cout << n << " = " << i << " + " << n - i << endl;
                break;
            }
            if(i>2){
                i+=2;
            }else{
                i++;
            }
        }
        if(!done){
            cout << "Goldbach's conjecture is wrong." << endl;
        }

    }
}
