#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, vector<int>> m;
    int ma=0;

    for(int i=1; i<=1000; i++){
        int count=0;
        double limit=sqrt(i);
        for(int j=1; j<=limit; j++){
            if(i%j==0){
                count+=2;
            }
        }
        if(ceil(limit)==floor(limit)){
            count--;
        }
        ma=max(ma, count);
        m[count].push_back(i);
    }

    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        int temp;
        cin>>temp;
        int j=1;
        for(; m[j].size()<temp;){
            temp-=m[j].size();
            j++;
        }
        printf("Case %d: %d\n", i, m[j][m[j].size()-temp]);

    }
}
