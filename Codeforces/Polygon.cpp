#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> mp(n);
        for(int i=0; i<n; i++){
            cin>>mp[i];
        }
        bool found=true;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mp[i][j]=='1'){
                    if(j+1==n || i+1==n){
                        continue;
                    }
                    if(j+1<n && mp[i][j+1]=='1'){
                        continue;
                    }
                    if(i+1<n && mp[i+1][j]=='1'){
                        continue;
                    }else{
                        found=false;
                        break;
                    }
                }
            }
        }
        if(found) cout<< "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

/*Logic:
 * For any 1 fired by one of the cannons and be placed at the position
 * given, there has to be a boundary or another 1 immediately to its right
 * or bottom. Just check to see for all 1s, whether this codition holds.
 */
