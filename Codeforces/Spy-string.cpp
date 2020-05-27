#include <bits/stdc++.h>
using namespace std;

bool compare(string& a, string& b){
    int counter=0;
    for(int i=0; i<a.size(); i++){
        if(a[i]!=b[i]){
            counter++;
        }
    }
    if(counter<2){
        return true;
    }else{
        return false;
    };
}
int main(){
    int t, n, m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        cin.ignore();
        vector<string>str(n);
        vector<set<char>> charsAt(m, set<char>());
        vector<int>diff(n, 0);
        for(int i=0; i<n; i++){
            cin>>str[i];
            for(int j=0; j<m; j++){
                charsAt[j].insert(str[i][j]);
            }
        }
        string ans;
        bool found=false;
        for(int index=0; index < m; index++){ //index
            if(found){
                break;
            }
            ans=str[0];
            for(auto c=charsAt[index].begin(); c != charsAt[index].end(); c++) { //char at specific index for all strings
                ans[index]=*c;
                found=true;
                for (int s = 0; s < n; s++) { //strings
                    if (!compare(ans, str[s])) {
                        found=false;
                        break;
                    }
                }
                if(found){
                    cout<< ans << endl;
                    break;
                }
            }
        }
        if(!found){
            cout<< -1 << endl;
        }
    }
}

/*Logic:
 * We are required to find a string if it exists, such that
 * it differes by character with all the given strings by at
 * most 1. So, for a particular index we will have a set of
 * characters found from the given strings at that index.
 * Next, we will choose a dummy string out of the given string.
 * Then for every index, we will replace the dummy string's that
 * index's character with a character from that index's set and
 * cross check with all the strings. If they differ by at most 1,
 * we have found our answer.
 */
