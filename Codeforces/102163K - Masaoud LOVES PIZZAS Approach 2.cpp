#include <iostream>
using namespace std;

int main() {
    long long int t, n, x, start, end, counter, cumulativeSum[(unsigned int)1e5 + 1];
    cin >> t;
    cumulativeSum[0] = 0;
    while(t--){
        cin >> n >> x;
        for(long long int i=1; i<=n; i++){
            cin >> cumulativeSum[i];
            cumulativeSum[i] += cumulativeSum[i - 1];
        }

        start = end = counter = 0;
        while(end <= n){
            if(cumulativeSum[end] - cumulativeSum[start] >= x){
                start++;
                continue;
            }
            if(start < end){
                counter += end - start;
            }
            end++;
        }
        cout << counter << endl;
    }

    return 0;
}

/*
 * Logic:
 * (Cumulative array approach)
 * Take in the array.
 * Transform that to a running sum array or cumulative sum array.
 * Use a sliding window technique that uses a start and the end index.
 * For any array within a range of start and end indices for that cumulative array, the number of contiguous subarray can be calculated by end - start.
 * Example -> 5 1 3 4
 * Cumulative array -> 0 5 6 9 13
 * The sub-arrays are [5], [5 1], [5 1 3], [5 1 3 4]. So, if start = 0 and end = 4 -> number of subarray is 4-0 = 4
 * Time complexity = O(n)
 */
