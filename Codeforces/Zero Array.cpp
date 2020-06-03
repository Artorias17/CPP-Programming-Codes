#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        int ori[n];
        map<int, int> repeats;
        set<int> unique;
        for(int i=0; i<n; i++){
            cin>>ori[i];
            if(ori[i]!=0){
                repeats[ori[i]]++;
                unique.insert(ori[i]);
            }
        }
        int op, p, v;
        while(q--){
            cin>>op;
            if(op==1){
                cin>>p>>v;
                p--;
                if(ori[p]!=0){
                    repeats[ori[p]]--;
                    if(repeats[ori[p]]==0){
                        unique.erase(ori[p]);
                    }
                }
                ori[p]=v;
                if(ori[p]!=0){
                    repeats[ori[p]]++;
                    unique.insert(ori[p]);
                }
            }else{
                cout<< unique.size() << endl;
            }
        }
    }
    return 0;
}

/*Logic:
 * In order to create the zero array, the least number except
 * zero from the array and subtract them from all non-zero numbers.
 * We will rinse and repeat this process until the the whole array
 * becomes zero.
 * So, it can be seen that number of minimum moves will the number
 * of unqiue numbers present in the array after any update.
 *
 * We will use a set to store all unqiue numbers except 0.
 * Also we will use a map to store the repeats of the numbers.
 * For any update, if the number that is being replaced is the
 * only number present, then we need to remove that number from the set.
 * If the number that is updated with is the only 1 in the array and
 * that number is not 0, then add that number to the set.
 *
 * Misc:
 * Set is used to store all unqiue numbers.
 * map is used to store number of repeats.
 * array is used tot store the given array.
 * Faster CIN/COUT is required to get AC.
 */
