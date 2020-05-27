#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        int biggerStrength, smallerStrength;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        int leastDiff=INT_MAX;
        for(int i=0; i<n-1; i++){
            if(leastDiff>(int)abs(arr[i]-arr[i+1])){
                biggerStrength=max(arr[i], arr[i+1]);
                smallerStrength=min(arr[i], arr[i+1]);
                leastDiff=(int)abs(arr[i]-arr[i+1]);
            }
        }
        cout<< leastDiff << endl;
    }
    return 0;
}

/*Logic:
 * Find 2 numbers in a sorted array whose abs(x-y) is the least.
 * Suppose x>y.
 * Then, put x in Team A, and y in Team B.
 * Now, Team A will have all numbers which are less than x and
 * team B will have all numbers which are greater than y.
 */
