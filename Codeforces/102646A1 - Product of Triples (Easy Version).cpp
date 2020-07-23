#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int arr[((long long) 2e3)+1];
    memset(arr, 0, sizeof(arr));
    for(int a=1; a<=2e3; a++){
        for(int b=1; b<=2e3; b++){
            for(int c=1; c<=2e3; c++){
                if(a<=b && b<=c){
                    if((long long)a*b*c>(long long)2e3) break;
                    else arr[a*b*c]++;
                }
            }
        }
    }
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        cout << arr[i] << endl;
    }
    return 0;
}
