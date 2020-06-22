#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    long long int ans=0;
    for(int i=n-1; i>0; i--){
        if(arr[i]%2==0){
            ans+=arr[i]-1;
        }else{
            ans+=arr[i];
        }
    }
    if(n%2!=0){
        if(arr[0]%2==0){
            ans--;
        }
        ans+=arr[0];
    }
    cout<< ans << endl;
    return 0;
}

/*Logic:
 * The problem statement was a bit confusing
 * because it wasn't clear to take all flowers in the
 * shop or not.
 *
 * However, we are only required to choose maximum
 * odd number of flowers.
 * And each type of flowers specifically in the bouquet,
 * has to be odd no matter whether the store has even type
 * or odd type.
 * As we know, odd+odd=even, flower type chosen has to be odd.
 */
