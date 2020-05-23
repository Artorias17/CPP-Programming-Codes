#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int maxDigitSum=81;
    cin >> n;
    vector<int> numbers;
    for(int i=maxDigitSum; i>0; i--){
        if(n-i>0){
            int number=n-i;
            int div=n-i;
            int individualSum=0;
            while(div!=0){
                individualSum+=div%10;
                div/=10;
            }
            if(individualSum==i){
                numbers.push_back(number);
            }
        }
    }
    cout<< numbers.size() << endl;
    if(numbers.size()>0){
        sort(numbers.begin(), numbers.end());
        for(int i=0; i<numbers.size()-1; i++){
            cout<< numbers[i] << " ";
        }
        cout<< numbers[numbers.size()-1] << " ";
    }
    return 0;
}
/*Logic:
 * Writing down all the number + sum of its digits reveal to us that,
 * the sum digits most of the time goes round. However, there is a max limit
 * to the individual sum. Constraint was given to be 10^9. So, summation of
 * digits for 999999999 is 81. As this sum will never exceed, all we have to
 * do is for 1 to 81 call it i, subtract i from n. check whether number found
 * gives same digit summation as i. If it does, then store n-i.
 */
