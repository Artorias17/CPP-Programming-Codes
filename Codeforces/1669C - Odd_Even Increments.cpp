#include <iostream>
using namespace std;


bool findAnswer(const int *arr, int n){
    for(int i=0; i<n; i+=2){
        if (arr[0] != arr[i]) return false;
    }
    for(int i=1; i<n; i+=2){
        if (arr[1] != arr[i]) return false;
    }
    return true;
}
int main() {
    int t, n;
    cin >> t;
    int arr[50];
    while(t--){
        cin >> n;
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            arr[i] %= 2;
        }
        if(findAnswer(arr, n)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}


/*
 * Logic:
 * Take in the array, but store their parity.
 * Then check if all even indexed values have the same parity or not.
 * Same goes for odd indexed values.
 * If all goes well, print YES, else NO.
 */
