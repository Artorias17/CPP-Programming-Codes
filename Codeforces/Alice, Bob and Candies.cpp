#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int moves=1, globalAlice=arr[0], globalBob=0, a=1, b=n-1, currentA=arr[0], currentB=0;
        bool Alice=false;
        int totalEaten=1;
        while(totalEaten!=n){
            if(Alice){
                moves++;
                currentA=0;
                while(currentA<=currentB && totalEaten!=n){
                    currentA+=arr[a];
                    globalAlice+=arr[a];
                    a++;
                    totalEaten++;
                }
                Alice=false;
            }else{
                moves++;
                currentB=0;
                while(currentB<=currentA && totalEaten!=n){
                    currentB+=arr[b];
                    globalBob+=arr[b];
                    b--;
                    totalEaten++;
                }
                Alice=true;
            }
        }
        cout<< moves << " " << globalAlice << " " << globalBob << endl;
    }
}

/*Logic:
 * Used brute force approach
 * Initialized current candy weight of Alice with array[0] value
 * and global weight for Alice to array[0].
 * Initialized current candy weight of Bob with 0
 * and global weight for Bob to 0.
 * Initialized moves to 1 as Alice's move is done.
 * Then used loop and boolean flag to interate from left to right for Alice
 * and right to left for Bob, kept a counter for how many candies have been
 * consumed so far.
 */
