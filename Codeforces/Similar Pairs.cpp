#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        int even=0, odd=0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            if(arr[i]%2==0){
                even++;
            }else{
                odd++;
            }
        }
        if(even%2==0 && odd%2==0){
            cout<< "YES" << endl;
        }else{
            sort(arr.begin(), arr.end());
            for(int i=0; i<n-1;){
                if(abs(arr[i]-arr[i+1])==1){
                    even--;
                    odd--;
                    i+=2;
                    if(even%2==0 && odd%2==0){
                        break;
                    }
                }else{
                    i++;
                }
            }
            if(even%2==0){
                even=0;
            }
            if(odd%2==0){
                odd=0;
            }
            if(even!=0 || odd!=0){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        }

    }
    return 0;
}

/*Logic:
 * Initially count how many even numbers are there and odd numbers are there.
 * Case 1: There are even numbers of both even and odd, then we can definitely make pairs.
 * Case 2: There are odd numbers of both even and odd, then we have to find 1 pair where
 *         abs(x-y) is 1, for to make rest of of the pairs.
 * Case 3: There are odd numbers of even and even numbers of odd OR
 *         There are odd numbers of odd and even numbers of even, then we can't make pairs.
 */
