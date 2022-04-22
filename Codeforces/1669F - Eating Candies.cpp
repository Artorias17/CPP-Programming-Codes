#include <iostream>
using namespace std;

int main(){
    int t, n, left, right, totalCandies;
    long long int alice, bob;
    cin >> t;
    int arr[(int)2e5];
    bool leftChange, rightChange;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++) cin >> arr[i];
        alice = bob = totalCandies = 0;;
        left=0, right = n - 1;
        leftChange = rightChange = true;
        while(left < right){
            if(leftChange){
                alice += arr[left];
                leftChange = false;
            }
            
            if(rightChange){
                bob += arr[right];
                rightChange = false;
            }
            
            if(alice == bob){
                totalCandies = (left + 1) + (n - right);
                left++, right--;
                leftChange = rightChange = true;
            }
            else if(alice < bob){
                left++;
                leftChange = true;
            }
            else{
                right--;
                rightChange = true;
            }
        }
        cout << totalCandies << endl;
    }
    return 0;
}

/*
 * Logic:
 * Take in the array, Use a left and right pointers to indicate which candies have been eaten.
 * Check the current total weights consumed by Alice and Bob. If both are same, then
 * the total number of candies eaten is = (leftIndex + 1) + (length of array - rightindex).
 * If the Alice's total candy weight consumed is higher, then decrement rightIndex. If its Bob's, then 
 * increment leftIndex. If both are same, then increment leftIndex and decrement rightIndex.
 */
