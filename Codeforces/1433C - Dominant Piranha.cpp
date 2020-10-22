#include <iostream>
#include <cstring>
#define SZ (unsigned long long)3e5

using namespace std;

int main() {
    int t, numberOfFish;
    int bigFish, arr[SZ];
    int printVal;

    cin>> t;
    while(t--){
        memset(arr, 0, sizeof(arr));
        printVal = -1;
        cin >> numberOfFish;
        bigFish=0;

        for(int i=0; i < numberOfFish; i++){
            cin >> arr[i];
            bigFish= max(bigFish, arr[i]);
        }

        for(int i=0; i < numberOfFish; i++){
            if(arr[i]==bigFish){
                if(i==0 && arr[0] > arr[1]) {
                    printVal = 1;
                    break;
                }
                else if(i==numberOfFish-1 && arr[numberOfFish-1] > arr[numberOfFish-2]) {
                    printVal = numberOfFish;
                    break;
                }
                else if((i!=0 && i!=numberOfFish-1) && (arr[i] > arr[i+1] || arr[i] > arr[i-1])) {
                    printVal = i + 1;
                    break;
                }
            }
        }

        cout << to_string(printVal) + "\n";
    }
    return 0;
}
