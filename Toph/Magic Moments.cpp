/*
 * Logic
 * Take in the array. Sort the array in descending order.
 * Since array index starts from 0.
 * Then kth number will be found from k-1 index.
 *
 * Time complexity = O(n log n)
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[1000];

    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n, greater<>());

    cout << arr[k-1] << endl;
    return 0;
}
