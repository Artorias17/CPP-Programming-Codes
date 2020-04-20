#include <bits/stdc++.h>
using namespace std;
vector<int> decide(const int tracks, const int trackLength[], int next, vector<int> RemainingAndTracks){
    if(next==tracks){
        return RemainingAndTracks;
    }else if(RemainingAndTracks[0] - trackLength[next] < 0){
        return decide(tracks, trackLength, next+1, RemainingAndTracks);
    }else{
        vector<int> noTaken=decide(tracks, trackLength, next+1, *new vector<int>(RemainingAndTracks));
        RemainingAndTracks[0]-=trackLength[next];
        RemainingAndTracks.push_back(trackLength[next]);
        vector<int> taken=decide(tracks, trackLength, next+1, RemainingAndTracks);
        if(taken[0]<noTaken[0]){
            return taken;
        }else if(taken[0]>noTaken[0]){
            return noTaken;
        }else{
            if(taken.size()-1>=noTaken.size()-1){
                return taken;
            }else{
                return noTaken;
            }
        }
    }
}
int main() {
    int maximum=0, tracks=0;
    while(cin>> maximum >>tracks) {
        int len[tracks];
        for (int i = 0; i < tracks; i++) {
            cin >> len[i];
        }
        vector<int> ans = decide(tracks, len, 0, *new vector<int>(1, maximum));
        for (int i = 1; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "sum:" << maximum-ans[0] << endl;
    }
    return 0;
}
/*Logic:
 * Used recursive tree search
 */
