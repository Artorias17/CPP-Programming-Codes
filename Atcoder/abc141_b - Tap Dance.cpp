#include <iostream>
using namespace std;
int main() {
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(!((i%2==0 && s[i]=='R') || (i%2!=0 && s[i]=='L') || (s[i]=='U' || s[i]=='D'))){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
