#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>

#define ull unsigned long long int

using namespace std;

vector <ull> prime;

void seive(){
    bitset<(ull)1e5+1> bits;
    bits.flip();
    bits[0] = false;
    bits[1] = false;
    int sqrtLimit= (int) sqrt(1e5);
    for(int i= 2; i<= sqrtLimit;){
        if(bits[i]){
            prime.push_back(i);
            for(int j=i*i; j<=1e5; j+=i+i){
                bits[j] = false;
            }
        }
        if(i==2) ++i;
        else i+=2;
    }
    for(int i=sqrtLimit+1; i<=1e5; i++){
        if(bits[i]) prime.push_back(i);
    }
}

vector<ull> getVector() {
    int clipStart=1;
    ull x;
    vector<ull> answer(100, 1);
    cin >> x;
    ull initialLimit=sqrt(x);
    for(int primeItr=0, vectItr=0;  prime[primeItr] <= initialLimit && prime[primeItr] <= x; ){
        if(x % prime[primeItr] == 0){
            answer[vectItr] *= prime[primeItr];
            x /= prime[primeItr];
            vectItr++;
            clipStart= max(clipStart, vectItr);
        }else if(x==1){
            break;
        }else{
            ++primeItr;
            vectItr=0;
        }
    }
    if (answer[clipStart-1]==x){
        answer[clipStart] = x;
        clipStart++;
    }else if(x!=1){
        answer[0] *= x;
    }
    answer.erase(answer.begin() + clipStart, answer.end());
    sort(answer.begin(), answer.end());
    return answer;
}

int main(){
    seive();
    vector<ull> answer;
    int t;
    cin>>t;
    while(t--){
         answer = getVector();

        cout << answer.size() << endl;
        for(int i = 0; i<answer.size(); ++i){
            cout << answer[i];
            if(i!=answer.size()-1) cout << " ";
            else cout << endl;
        }
    }
    return 0;
}

/*Logic:
 * Given a number, we need to find its prime factors.
 * For each prime factor p1 multiply it to other x prime factors
 * where x = power of p1
 */
