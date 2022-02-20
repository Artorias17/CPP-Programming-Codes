#include <iostream>

using namespace std;
int main(){
    int t, n, answer;
    int arr[100];
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(arr[i]+arr[j] > (arr[i] | arr[j])){
                    arr[i] |= arr[j];
                    arr[j] = 0;
                }
            }
        }
        answer = 0;
        for(int i=0; i<n; i++) answer += arr[i];
        cout << answer << endl;
    }
    return 0;
}
