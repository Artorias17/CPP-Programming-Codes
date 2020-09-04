#include <bits/stdc++.h>
using namespace std;

vector<string> getVector(const string &s) {
    vector<string> ans;
    ans.emplace_back("");
    for(int i=0; i < s.size();){
        if(i+2<s.size()){
            if(!(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B')) {
                ans[ans.size() - 1] += s[i];
                i++;
            }
            else{
                if(!ans[ans.size()-1].empty()) ans.emplace_back("");
                i+=3;
            }
        }else{
            ans[ans.size()-1]+=s.substr(i);
            break;
        }
    }
    while(ans[ans.size()-1].empty()){
        ans.erase(--ans.end());
    }
    return ans;
}

int main() {
    string s;
    cin>>s;
    if(s.size()<3){
        cout << s << endl;
    }else{
        vector<string>ans = getVector(s);
        for(int i=0; i<ans.size()-1; i++){
            cout << ans[i] << " ";
        }
        cout << ans[ans.size()-1] << endl;
    }
    return 0;
}
