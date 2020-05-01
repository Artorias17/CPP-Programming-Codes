#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        map<int, int> unique;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            unique[arr[i]]=1;
        }
        if(unique.size()>k) {
            cout << -1 << endl;
        }else{
            int index=0;
            for(auto i=unique.begin(); i!=unique.end(); i++, index++){
                if(arr[index]!=i->first){
                    arr.insert(arr.begin()+index, i->first);
                }
            }
            cout<< n*k << endl;
            while(n--){
                for(int i=0; i<k; i++){
                    cout<< arr[i];
                    if(n==0 && i==k-1){
                        cout<< endl;
                    }else{
                        cout<< " ";
                    }
                }
            }
        }
    }
    return 0;
}

/*Logic:
 * Idea is that if k is equal to or greater than  number of unique numbers,
 * then all that is required is to insert all unqiue number not within the
 * first block at the beginning and then print that block n number of times.
 * As, the array limit is 10^4, maximum array that will be provided is 100
 * and it is not required to print the smallest array, this method works.
 */
