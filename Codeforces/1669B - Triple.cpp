#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    long long int n;
    cin >> t;
    long long int temp;
    while(t--){
        cin >> n;
        bool answered = false;
        unordered_map<long long int, long long int> mp;
        for(int i=0; i<n; i++){
            cin >> temp;
            if(mp.find(temp) != mp.end()){
                mp[temp] += 1;
            }else{
                mp[temp] = 1;
            }
        }

        for(auto & i : mp){
            if(i.second >= 3){
                cout << i.first << endl;
                answered = true;
                break;
            }
        }

        mp.clear();
        if(answered) continue;
        cout << -1 << endl;
    }
    return 0;
}


/*
 * Logic:
 * Use an unordered map to store the numbers and their frequencies
 * then iterate through them and find the one that has a frequency of 
 * at least 3 and print the number. If none is found print -1.
 */
