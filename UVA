#include <bits/stdc++.h>
using namespace std;

int EuclideanGCD(int x, int y){
    if(x==0){
        return y;
    }else{
        return EuclideanGCD(y%x, x);
    }
}

int main() {
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        int val=0;
        vector<int> arr;
        stringstream ss(s);

        while(ss>> val){
            arr.push_back(val);
        }

        val=-1;
        for(int i=0; i<arr.size()-1; i++){
            for(int j=i+1; j<arr.size(); j++){
               int temp=EuclideanGCD(arr[i],  arr[j]);
               if(temp>val){
                   val=temp;
               }
            }
        }

        cout<< val << endl;

    }
    return 0;
}
