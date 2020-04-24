#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> values(n, 0);
        for(int i=0; i<n; i++){
            cin>>values[i];
        }

        // stores the frequency of 0 change made sums
        map<int, int> Sum_Freq_Zero_Changes;

        // prefix array is an array where values are stored in index by adding its own value
        // with its predecessor's index value.
        // Used instead of manually filling up sum-range frequency array with frequencies by loop.
        int prefix[2*k+1+1];
        memset(prefix, 0, sizeof(prefix));

        for(int i=0, j=n-1; i<n/2; i++, j--){
            Sum_Freq_Zero_Changes[values[i] + values[j]]++;

            int Least_1_Change_Sum= min(values[i], values[j]) + 1;
            int Max_1_Change_Sum= max(values[i], values[j]) + k;

            prefix[Least_1_Change_Sum]+=1; // Range starts from Least_1_Change_Sum, so add 1.
            prefix[Max_1_Change_Sum+1]-=1; // Range lasts till Max_1_Change_Sum, so subtract the next index by 1
        }

        int MinimumChange=INT_MAX;
        // Filling up prefix array to turn it into a sum-range frequency array or x-frequency array
        for(int x=2; x<=2*k; x++){
            prefix[x]+=prefix[x-1];

            // Assuming the constant sum is x
            // Total pair is n/2.
            // Pair_Zero_Changes = Pair of numbers whose sum equals to x without changing the pair
            // Pair_One_Change = Pair of numbers whose sum equals to x by changing one of the number
            // Pair_Two_Change = Pair of numbers whose sum equals to x by changing the both the numbers
            // Pair_One_Change - Pair_Zero_Changes is done to remove Pair_Zero_Changes inside the prefix array for x
            int Pair_Zero_Changes= Sum_Freq_Zero_Changes.find(x)!= Sum_Freq_Zero_Changes.end() ? Sum_Freq_Zero_Changes[x] : 0;
            int Pair_One_Change= prefix[x]- Pair_Zero_Changes;
            int Pair_Two_Change= (n/2) - Pair_Zero_Changes - Pair_One_Change;

            MinimumChange= min(MinimumChange, (0*Pair_Zero_Changes) + (1*Pair_One_Change) +(2*Pair_Two_Change));
        }

        cout << MinimumChange << endl;
    }
    return 0;
}

/*Logic:
 * To get the constant sum across the n/2 pairs in the array
 * we need to make either no changes, 1 change or 2 changes in the pair of numbers.
 * For 0 change,
 * Add values from i index and (n-1-i) index.
 * Store these values.
 *
 * For 1 change,
 * Sum can be decreased or increased by varying any one of the numbers from the pair.
 * Thus, there will be a range of sum that can be achieved by changing 1 number for a particular pair.
 * To get the smallest number, choose the smallest number from the pair, the other number will be 1, add them.
 * To get the largest number, choose the largest number from the pair, the other number will be k, add them.
 * With these we can create a frequency array that starts from 2 and ends at 2*k.
 * However, filling these through normal looping will cause TLE.
 * To fill the array in O(2k) use prefix array.
 * Add 1 to array[smallest sum range] and subtract 1 from array[largest sum range+1].
 * Complete the array by adding array[index-1] to array[index] for index=2 to index=2*k
 *
 * For 2 change,
 * There are n/2 pairs, and the frequencies we have found thus far, tell us how many of the pairs
 * require what amount of change for a particular sum.
 * Now, let this sum be x from the question.
 * Then, pair of changed 2 number to get x = (n/2) - (pair of strictly changed 1 number to get x) - (pair of none changed number to get x)
 * Total change= 0*(none changed pair) + 1*(1 changed pair) + 2*(2 changed pair)
 * Find the minimum
 */
