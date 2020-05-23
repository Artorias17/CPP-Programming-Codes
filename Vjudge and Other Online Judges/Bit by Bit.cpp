#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[32];
    int t;
    while(cin>>t){
        if(t==0){
            break;
        }
        cin.ignore();
        memset(arr, -1, sizeof(arr));
        while(t--){
            string op;
            int index1, index2;
            cin>>op;
            if(op=="SET"){
                cin>>index1;
                cin.ignore();
                arr[31-index1]=1;
            }else if(op=="CLEAR"){
                cin>>index1;
                cin.ignore();
                arr[31-index1]=0;
            }else if(op=="OR"){
                cin>>index1>>index2;
                cin.ignore();
                if(arr[31-index1]==1 || arr[31-index2]==1){
                    arr[31-index1]=1;
                }
                else if(arr[31-index1]==0 && arr[31-index2]==0){
                    arr[31-index1]=0;
                }else{
                    arr[31-index1]=-1;
                }
            }else if(op=="AND"){
                cin>>index1>>index2;
                cin.ignore();
                if(arr[31-index1]==0 || arr[31-index2]==0){
                    arr[31-index1]=0;
                }else if(arr[31-index1]==1 && arr[31-index2]==1){
                    arr[31-index1]=1;
                }else{
                    arr[31-index1]=-1;
                }
            }
        }
        for(int i=0; i<32; i++){
            if(arr[i]==-1){
                cout<< "?";
            }else{
                cout<< arr[i];
            }
        }
        cout<< endl;
    }
    return 0;
}

//Logic: Brute Force
