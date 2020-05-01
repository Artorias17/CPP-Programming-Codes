#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        cin>>s;
        int i=0;
        while(s[i]==s[i+1] && i<s.size()-1){
            i++;
        }
        if(i==s.size()-1) cout << s << endl;
        else{
            cout<< s[0];
            i=1;
            while(i!=s.size()){
                if(s[i-1]==s[i]){
                    if(s[i-1]=='0') {
                        cout << 1;
                    }else {
                        cout << 0;
                    }
                }
                cout<<s[i];
                i++;
            }
            cout<< endl;
        }
    }
}

/* Logic:
 * If string is all 1 or all 0, period will be 1.
 * However, if there is deviation then we can expect a period of 2
 * as the pattern is either 0101.... or 10101....
 */
