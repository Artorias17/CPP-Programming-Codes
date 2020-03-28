#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[502][502];
    for(int i=0; i<502; i++){
        for(int j=0; j<502; j++){
            if(i==0 || j==0 || i>=j){
                arr[i][j]=0;
            }else{
                arr[i][j]=arr[i][j-1]+__gcd(i, j);
            }
        }
    }

    while(true){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        int g=0;
        for(int i=1; i<n; i++){
            g+=arr[i][n];
        }
        cout<< g << endl;
    }
    return 0;
}
