#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    int n0, n1, n2;
    cin>>t;
    while(t--){
        cin>>n0 >> n1 >> n2;
        //Default case: create a sequence in the format 0...01...10101...
        //So put n0+1 0s at the front, n2+1 1s in the middle, and at n1-1 alternates
        //starting from 0.
        if(n1!=0){
            string text;
            for(int i=1; i<=n0+1; i++){
                text.insert(text.begin(), '0');
            }

            for(int i=1; i<=n2+1; i++){
                text.push_back('1');
            }
            n1--;

            int one= 0;
            for(int i=1; i<=n1; i++){
                text.push_back(one ? '1' : '0');
                one=(one+1)%2;
            }


            cout << text;
        }
        //Special cases: all 0s, no alternates and all 1s OR
        // all 0s, no alternates and no 1s OR
        // no 0s, no alternates and all 1s
        // Either print n0+1 0s or print n2+1 1s.
        else{
            if(n0!=0){
                for(int i=0; i<=n0; i++){
                    cout << "0";
                }
            }else{
                for(int i=0; i<=n2; i++){
                    cout << "1";
                }
            }
        }
        cout<< endl;
    }
    return 0;
}
