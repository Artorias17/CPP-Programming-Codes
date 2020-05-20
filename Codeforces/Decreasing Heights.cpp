#include <bits/stdc++.h>
using namespace std;

long long int matrix[100][100];
long long int dp[100][100];
int t, r, c;
long long int ans;

void resetDP(){
    for(int i=0; i<r; i++){
        memset(dp[i], -1, sizeof(dp[i]));
    }
}
long long int minCostPathDP(long long int currentHeight, int gotoI, int gotoJ){
    if(gotoI==r || gotoJ==c){
        return LLONG_MAX;
    }else if(matrix[gotoI][gotoJ]<currentHeight){
        return LLONG_MAX;
    }else if(dp[gotoI][gotoJ]!=-1){
        return dp[gotoI][gotoJ];
    }else{
        long long int current=matrix[gotoI][gotoJ]-currentHeight;
        long long int bottom=minCostPathDP(currentHeight+1, gotoI+1, gotoJ);
        long long int right=minCostPathDP(currentHeight+1, gotoI, gotoJ+1);
        if(bottom==LLONG_MAX && right==LLONG_MAX) {
            if(gotoI==r-1 && gotoJ==c-1){
                dp[gotoI][gotoJ]=current;
            }else{
                dp[gotoI][gotoJ]=LLONG_MAX;
            }
        }else{
            dp[gotoI][gotoJ]=current+min(bottom, right);
        }
        return dp[gotoI][gotoJ];
    }
}
int main() {
    cin>>t;
    while(t--){
        ans=LLONG_MAX;
        cin>>r>>c;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin>>matrix[i][j];
            }
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                resetDP();
                ans= min(minCostPathDP(matrix[i][j]-(i+j), 0, 0), ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*Logic:
 * This problem requires the usage of Minimum Cost Path of Dynamic Programming.
 * Idea is that, assuming a constant value for the starting coordinate (0,0)
 * we will check every possible path that can be traversed to reach (r-1, c-1).
 * For that, we will first change the (0, 0) coordinate's height to that constant value.
 * Next, we will recursively check bottom and right with new (x, y) height + 1 and store the
 * subtraction in another matrix. If we hit a coordinate where the height we want
 * is not possible via reduction then that path is a dead end. In that case, from (x, y), if both bottom and right
 * paths are blocked, store infinity as move for (x, y). Otherwise, if we are able to reach (r-1, c-1) coordinate
 * then that is one of the possible paths. Store in another matrix for (x, y), the returned minimum of the summations of
 * subtractions + subtraction of (x, y)'s height.
 *
 * Now, the constant values can be found from the given matrix. For any (x, y) height, required height for (0, 0)
 * can be found by height at (x, y) - (x+y). Meaning subtracting the number of indices required to traverse
 * to reach (x, y), from the height of (x, y). For every constant height, we need to redo checking. Thus, it has a
 * time complexity of O(n^4).
 *
 * MISC:
 * https://www.youtube.com/watch?v=zBQzocZwEZk for detailed explanation.
 *
 * First attempt for this problem had similar idea, except went for greedy approach. This failed given test cases
 * because choosing the minimum cost index at every index meant that ignoring a possible path which later would be
 * smaller overall.
 */
