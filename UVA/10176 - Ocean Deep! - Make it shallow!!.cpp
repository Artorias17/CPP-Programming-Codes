#include <bits/stdc++.h>
using namespace std;

string trimZero(string bin){
    int msb=bin.size();
    for(int i=0; i<bin.size(); i++){
        if(bin[i]=='1'){
            msb=i;
            break;
        }
    }
    if(bin.size() == msb){
        return "";
    }else{
        return bin.substr(msb, bin.size());
    }
}

int compare(string first, string second) {
    if (first.size() > second.size()) {
        return -1;
    }else if(first.size()<second.size()){
        return 1;
    }
    int f=0, s=0;
    while(f!=first.size() && s!=second.size()){
        if(first[f]==second[s]){
            f++, s++;
        }
        else{
            if(first[f]=='1') return -1;
            else return 1;
        }
    }
    return 0;
}

string subtract(string f, string s){
    string ans;
    bool carry=false;
    char top, bottom;
    for(int i=f.size()-1, j=s.size()-1; i>=0; i--, j--){
        top=f[i];
        if(j<0){
            bottom='0';
        }else{
            bottom=s[j];
        }
        if(top=='1' && bottom=='1'){
            if(carry){
                ans="1"+ans;
            }else{
                ans="0"+ans;
            }
        }
        else if(top=='0' && bottom=='0'){
            ans="0"+ans;
        }
        else if(top=='1' && bottom=='0'){
            if(carry){
                ans="0"+ans;
                carry=false;
            }else{
                ans="1"+ans;
            }
        }
        else if(top=='0' && bottom=='1'){
            if(carry){
                ans="0"+ans;
            }else{
                ans="1"+ans;
                carry=true;
            }
        }
    }
    return trimZero(ans);
}

int main(){
    string b;
    string d="11111111111111111";
    while(getline(cin, b)){
        while(b[b.size()-1]!='#'){
            string temp;
            getline(cin, temp);
            b+=temp;
        }
        b=b.substr(0, b.size()-1);
        for(int lim=1; lim<=b.size(); lim++){
            b=trimZero(b);
            if(compare(d, b.substr(0, lim))>-1){
                b=subtract(b.substr(0, lim), d)+ b.substr(lim);
                lim=0;
            }
        }
        if(b.size()==0){
            cout<< "YES" << endl;
        }else{
            cout<< "NO" << endl;
        }
    }
}
