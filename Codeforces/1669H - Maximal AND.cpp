#include <iostream>
#include <bitset>
using namespace std;

int main(){
    unsigned int t, n, k;
    bitset<31> ans(0);
    unsigned int arr[(int)2e5] {0};
    unsigned int zeroCount[31] {0};

    cin >> t;
    while(t--){
        cin >> n >> k;
        for(unsigned int i=0; i<n; i++){
            cin >> arr[i];
            ans.reset();
            ans |= arr[i];
            ans = ~ans;
            for(unsigned int j=0; j <= 30; j++){
                if(ans[j]) zeroCount[j] += 1;
            }
        }
        for(unsigned int i=30; i!= UINT32_MAX && k > 0; i--){
            if(zeroCount[i]!= 0 && zeroCount[i] <= k){
                k-= zeroCount[i];
                zeroCount[i] = 0;
            }
        }

        ans.reset();
        for(unsigned int i=30; i!= UINT32_MAX; i--){
            if(!zeroCount[i]) ans[i] = true;
        }

        for(unsigned int j=0; j < 32; j++){
            zeroCount[j] = 0;
        }

        cout << ans.to_ulong() << endl;
    }
    return 0;
}

/*
 * Logic:
 * Take in the array. Starting from the 31st bit to the 0th bit,
 * check the binary number of all integer number and store the positional total counts of zero bit
 * in an array. Then starting from the 31st bit to the 0th bit,
 * use the remaining k to completely remove the count for 0 bit from those positions.
 * This will make sure that all numbers having 0 bit in that position will have 1,
 * effectively making 1 when all numbers are AND'ed at that position.
 */
