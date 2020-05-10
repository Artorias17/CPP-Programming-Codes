#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int d=10;
        vector<int> ans;
        while(n!=0){
            if(n%d!=0){
                ans.push_back(n%d);
                n-=(n%d);
            }else{
                d=d*10;
            }
        }
        cout<< ans.size() << endl;
        for(int i=0; i<ans.size()-1; i++){
            cout<< ans[i] << " ";
        }
        cout<< ans[ans.size()-1] << endl;
    }
    return 0;
}
/*Logic:
 * Divide n by 10 and store the non zero remainder.
 * Subtract remainder found from n.
 * If any remainder becomes zero, multiply 10 to the divisor
 * and again divide n by divisor to get the non zero remainder
 * and subtract the new remainder from n.
 */
