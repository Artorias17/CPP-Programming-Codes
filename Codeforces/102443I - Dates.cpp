#include <bits/stdc++.h>
using namespace std;

enum block{
    DAY, MONTH, YEAR
};

string stringMaker(int num, block w){
    string ans=to_string(num);
    switch (w) {
        case DAY:
        case MONTH:
            if(ans.size()==1) ans="0"+ans;
            return ans;
        case YEAR:
            ans=to_string(num);
            while(ans.size()!=4){
                ans="0"+ans;
            }
            return ans;
    }
}

int main() {
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        string text;
        cin>>text;
        int arr[3];
        int mul=1;
        bool eu=false;
        arr[2]=arr[1]=arr[0]=0;
        int index=2;
        for(int i=(int)text.size()-1; i>=0; i--){
            if(text[i]=='.' || text[i]=='/'){
                mul=1;
                index--;
                if(text[i]=='.') eu=true;
            }else{
                arr[index]+= mul * (text[i] - '0');
                mul*=10;
            }
        }
        string d=stringMaker(arr[0], DAY);
        string m=stringMaker(arr[1], MONTH);
        if(!eu){
            text=d;
            d=m;
            m=text;
        }
        string y=stringMaker(arr[2], YEAR);
        cout<<d<<"."<<m<<"."<<y<<" ";
        cout<<m<<"/"<<d<<"/"<<y<<endl;
    }
    return 0;
}
