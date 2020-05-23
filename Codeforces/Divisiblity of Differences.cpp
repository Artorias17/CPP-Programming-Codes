#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin>>n>>k>>m;
    map<int, vector<int>> numbers;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        numbers[temp%m].push_back(temp);
    }
    for(auto i=numbers.begin(); i!=numbers.end(); i++){
        if(i->second.size()>=k){
            cout<< "Yes\n";
            vector<int> ans=i->second;
            for(int j=0; j<k-1; j++){
                cout<< ans[j] << " ";
            }
            cout<< ans[k-1] << "\n";
            return 0;
        }
    }
    cout<< "No\n";
    return 0;
}

/*Logic:
 * Idea was that, going to k numbers whose mod by m is the same.
 * This was done storing the remainders in a map as key, and the original
 * numbers as values. Then printed out any k numbers from vector whose size
 * was greater than or equal to k.
 */
