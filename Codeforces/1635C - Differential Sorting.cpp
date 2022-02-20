#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t, n;
    int arr[200000];
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++) cin >> arr[i];
        if(arr[n-2] > arr[n-1]) cout << -1 << endl;
        else if(arr[n-1] < 0){
            if(is_sorted(arr, arr+n)) cout << 0 << endl;
            else cout << -1 << endl;
        }else{
            cout << n-2 << endl;
            for(int i=1; i<=n-2; i++){
                cout << i << " " << n-1 << " " << n << endl;
            }
        }
    }
    return 0;
}

/*
 * Logic:
 * Using index numbering 0.....n-1 both inclusive.
 * Looking at the values of arr[n-2] and arr[n-1], if there are not sorted in ascending order, then there's
 * no value left to change arr[n-2] with. So, by default the answer will be -1.
 *
 * Now, if both arr[n-2] and arr[n-1] are in ascending order, then arr[n-2] - arr[n-1] < arr[n-2]. With this logic
 * in mind, we can simply substitute all values starting from index 0 to index n-3 with (arr[n-2] - arr[n-1]).
 * Since the question doesn't require us to find the minimum the number of operations performed but to perform
 * no more than n operations to sort the array by setting arr[x] = arr[y] - arr[z], it would be much simpler
 * to make everything equal to each other except for the last two. The answer will be n-2 operations.
 *
 * However, there is a caveat to the last statement. If arr[n-1] is negative, then arr[n-2] - arr[n-1] > arr[n-2].
 * So unless the array was sorted in the first place for which the answer will be 0, there is no way to sort it and
 * thus the answer will be -1.
 */
