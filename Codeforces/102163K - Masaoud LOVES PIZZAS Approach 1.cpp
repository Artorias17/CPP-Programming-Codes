#include <iostream>
using namespace std;

int main() {
    int t, n, x, start, end, arr[(unsigned int)1e5];
    cin >> t;
    long long int sum, counter;
    while(t--){
        cin >> n >> x;
        for(int i=0; i<n; i++) cin >> arr[i];
        counter = start = end = 0, sum = arr[0];

        while(start < n  && end < n){
            if(sum < x){
                if(start <= end) counter += end - start + 1;
                if(end < n) sum += arr[++end];
            }else{
                sum -= arr[start];
                start++;
            }
        }
        cout << counter << endl;
    }

    return 0;
}

/*
 * Logic:
 * Take in the array.
 * Use a sliding window technique that uses a start and the end index.
 * For any array within a range of start and end indices (both inclusive), the number of contiguous subarray can be calculated by end - start + 1.
 * Example -> 5 1 3 4
 * The sub-arrays are [5], [5 1], [5 1 3], [5 1 3 4]. So, if start = 0 and end = 4 -> number of subarray is 4 - 0 + 1 = 4
 * Time complexity = O(n)
 */
