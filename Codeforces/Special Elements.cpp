#include <bits/stdc++.h>
using namespace std;
int arr[8010];
bool check[8010];
int t, n, add, counter=0;
int main() {
    cin>>t;
    while(t--){
        memset(check, false, sizeof(check));
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        for(int i=0; i<n-1; i++){
            add=arr[i];
            for(int j=i+1; j<n; j++){
                add+=arr[j];
                if(add<=n){
                    check[add]=true;
                }else{
                    break;
                }
            }
        }
        counter=0;
        for(int i=0; i<n; i++){
            if(check[arr[i]]){
                counter++;
            }
        }
        cout << counter << endl;
    }
    return 0;
}

/*Logic:
 * Created an array for storing values from input
 * and another for storing values from different summation
 * values.
 * Marked all possible summation values, and checked
 * with the input values. Printed the number of matches
 * found
 */
