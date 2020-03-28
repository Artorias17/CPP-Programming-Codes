#include <bits/stdc++.h>
using namespace std;

//Using the same procedure to divide as manual long division

string longdivide(string s, string t){
    long div=0;
    for(long i=0; i<t.size(); i++){
        div=(div*10)+ (t[i]-'0');
    }
    long rem=0;
    for(long j=0; j < s.size(); j++){
        rem= ((rem * 10) + (s[j] - '0')) % div;
    }
    rem%=div;

    if(rem == 0){
        return "divisible";
    }else{
        return "not divisible";
    }
}

int main() {
    long t;
    string number="", divide="";
    cin>> t;
    cin.ignore();
    for(long i=1; i<=t; i++) {
        cout << "Case " << i << ": ";
        cin >> number >> divide;
        if(number[0] == '-'){
            number=number.substr(1);
        }
        if(divide[0] == '-'){
            divide=divide.substr(1);
        }
        cout << longdivide(number, divide) << endl;
    }
    return 0;
}
