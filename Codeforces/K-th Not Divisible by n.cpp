#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        long long int n, k;
        cin>>n>>k;
        int answer=k, adder, prev=0, current=k/n;
        while(current>prev){
            adder=current-prev;
            answer+=adder;
            prev=current;
            current=answer/n;
        }
        cout<< answer << endl;
    }
}

/*Logic:
 * At first choose k as the answer. Then find out how many numbers
 * within that number are divisible by n. Add that many numbers to answer.
 * Recheck how many numbers are divisible by n within the new answer. If number of
 * divisors are the same as previous number of divisors, then we have found our answer.
 */
