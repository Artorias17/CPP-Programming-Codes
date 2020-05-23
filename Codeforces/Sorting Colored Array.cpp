#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int index=0;
    vector<vector<int>> colours(200001);
    for(int i=0; i<n; i++){
        int value, colour;
        cin>>value>>colour;
        colours[colour].push_back(value);
    }

    for(int i=0; i<colours.size(); i++){
        if(colours[i].size()>1){
            int largestValueSeen=colours[i][0];
            for(int j=1; j<colours[i].size(); j++){
                if(largestValueSeen>colours[i][j]){
                    cout<< "NO" << endl;
                    return 0;
                }else{
                    largestValueSeen=colours[i][j];
                }
            }
        }
    }

    cout<< "YES" << endl;
    return 0;
}

/*Logic:
 * Since Bubble sort has O(n^2) time complexity it's going to get TLE.
 * So, idea is that we are going to store in the values as they appear
 * in their corresponding colour vector. Then, we are going to search
 * those colours vectors whose sizes are greater than 1. While serching,
 * if any big value appears before any smaller value, then we cannot sort
 * it. Thus, print "NO". Else we can sort it and so print "YES".
 *
 * MISC:
 * Maps are really slow!!!
 * Also, instead of using a variable to store the largest value seen so far
 * for a colour vector and using that to compare, was using another loop to
 * compare all possible values. This definitely gave TLE as time complexity
 * rose to O(n^3).
 */
