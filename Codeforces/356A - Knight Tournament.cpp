#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin>>n>>m;
    vector<int> answer(n, -1);
    set<int> st;
    for(int i=0; i<n; i++) st.insert(i);
    int l, r, x;
    for(int i=0; i<m; i++){
        cin>>l>>r>>x;
        l--, r--, x--;
        for(auto j=st.lower_bound(l); j!=st.upper_bound(r);){
            if(*j!=x){
                answer[*j]=x;
                st.erase(*j);
                j=st.lower_bound(l);
            }else{
                j++;
            }
        }
    }
    for(int i=0; i<n-1; i++){
        cout<< answer[i]+1<< " ";
    }
    cout<< answer[n-1]+1<< endl;

}

/*Logic:
 * Using a set of fighters is required.
 * Each fighter has unique ID.
 * We will be given a range between l and r.
 * All the fighters with l<=ID<=r will be eliminated
 * fighter with ID x.
 * So using lower_bound and upper_bound of set we will choose
 * the remaining fighters in the range and those fighters
 * except for x will be defeated by x. So we will store that
 * info in an array. We will also erase defeated fighters from
 * the array after each query. Keep on doing this till end of
 * query.
 */
