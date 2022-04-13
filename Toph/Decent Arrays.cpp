/*
 * Logic:
 * Since the all the values of the friend array is a value that is subtracted from a constant value
 * which is the last value of the main array. We only need to check if the main array is in ascending order
 * or not. If it is in ascending order then its friend array will be in descending order.
 *
 * Time complexity = O(n)
 */

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[100];
    bool is_sorted = true;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(i != 0){
            if(arr[i-1] > arr[i]) {
                is_sorted = false;
                break;
            }
        }
    }
    if(is_sorted) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
