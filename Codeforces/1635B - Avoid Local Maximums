#include <iostream>
#include <algorithm>
using namespace std;

void print(int answer, int* arr, int n){
    cout << answer << endl;
    for(int i=0; i<n-1; i++) cout << arr[i] << " ";
    cout << arr[n-1] << endl;
}

int main(){
    int t, n, answer;
    int arr[200000];
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++) cin >> arr[i];
        if(n<3){
            print(0, arr, n);
        }else{
            answer = 0;
            for(int i=0, j=1, k=2; k<n; i++, j++, k++){
                if(arr[j] > arr[i] && arr[j] > arr[k]) {
                    if(k+1 < n){
                        arr[k] = max(arr[k+1], arr[j]);
                    }else{
                        arr[k] = arr[j];
                    }
                    answer++;
                }
            }
            print(answer, arr, n);
        }
    }
    return 0;
}

/*
 * Logic:
 * We need to first find the local maxima. According to question, a local maxima is the one
 * whose neighbours are strictly smaller than it. So we sweep through the array using a sliding
 * window where we consider 3 values.
 *
 * If a local maxima is found, we need to change either it or either of its neighbours.
 * Now, it would be ideal to increase the value of the i+1 (next) neighbour because we can remove
 * the current maxima and also the potential next maxima. So in order to kill 2 birds with one stone,
 * we need to set the value for i+1 to the maximum from either the current maxima or the potential next maxima
 * at i+2.
 */
