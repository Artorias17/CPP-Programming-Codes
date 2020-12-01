#include <iostream>
using namespace std;

int main() {
    int x;
    cin>> x;
    while (x--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=n, j=0 ; j<n; ++j, --i) arr[j] = i;
        if(n%2 != 0){
            arr[n-1]= arr[n/2];
            arr[n/2]=1;
        }
        for(int i=0 ; i<n-1; ++i) cout << arr[i] << " ";
        cout << arr[n-1] << '\n';
    }
    return 0;
}
