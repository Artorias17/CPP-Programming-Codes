#include <bits/stdc++.h>
using namespace std;

int chooseMinimumByChoosingStartPosition(int k, string &g, vector<int> &v){
    int ones_to_the_left=0; //1s that needs to be flipped
    int minimum=INT_MAX;
    for(int i=0; i<g.size(); i++){
        v[i]+=ones_to_the_left;
        minimum=min(minimum, v[i]);
        if(g[i]=='1'){
            ones_to_the_left+=1;
        }
    }
    return minimum;
}

void checkMovesFromRightToLeft(int k, string &g, vector<int> &v){
    int ones_between=0; //between i and k (i+1...k-1)
    int ones_so_far=0; //number of 1s from i+1 to the end
    //thisOne= moves to make ith place 1 and (i+1...k-1)th place 0s and whatever minimum moves stored at v[k]
    //allZero=moves to make everything to the right 0.
    int allZero=0, thisOne=0;

    for(int i=g.size()-1;i>=0; i--){
        allZero=0, thisOne=0;
        if(g[i]=='0'){
            allZero=0+ones_so_far;
            thisOne=1+ones_between+ ((i+k)<g.size()? v[i+k]:0);
        }else{
            allZero=1+ones_so_far;
            thisOne=0+ones_between+ ((i+k)<g.size()? v[i+k]:0);
        }
        v[i]=min(allZero, thisOne);
        //For i-1, window will shift to the left, thus number of 1s found
        //from i to end needs to be updated.
        //Also, for i-1, if ith place is 1, then ones_between will increase by 1.
        if(g[i]=='1'){
            ones_so_far+=1;
            ones_between+=1;
        }
        //If for ith place (k-1)th place had 1, then sliding the window to the left
        //we will be losing that one. So, ones_between will reduce by 1.
        if(i+k-1<g.size()){
            if(g[i+k-1]=='1'){
                ones_between-=1;
            }
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t-->0){
        int n, k;
        cin>>n>>k;
        string g;
        cin.ignore();
        cin>>g;
        vector<int> prefix_array(n);
        checkMovesFromRightToLeft(k, g, prefix_array);
        int ans=chooseMinimumByChoosingStartPosition(k, g, prefix_array);
        cout << ans << endl;
    }
    return 0;
}

/*Logic:
 * Used prefix sum of Dynamic Programming
 * Initially, go from right to left.
 * For any character at a position, we will check how many moves
 * does it take to convert it and all characters to the right to 0,
 * meaning that position is not part of k period of 1s.
 * In addition to that, we will check how many moves does it take to
 * convert that character to 1 and everything in between that position
 * and k position to 0 and precalculated kth position minimum choice as this process
 * will precalculate what will become of that position and everything to the
 * right and put the minimum value in the prefix array.
 *
 * Next, at what position will we get the least moves if that
 * position is chosen to the start of the periodic sequence. Thus everything before
 * that will be 0. Therefore, we will add the number of 1s that needs to be flipped
 * before that position to the index value stored in prefix array.
 */
