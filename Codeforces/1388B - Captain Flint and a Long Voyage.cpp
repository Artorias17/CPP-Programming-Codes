#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
int main() {
    int t;
    int n;
    std::cin>>t;
    std::vector<short> digits;
    while(t--){
        digits.clear();
        std::cin>>n;
        digits.resize(n);
        for(int i=0; i<n; i++){
            digits[i]=9;
        }
        int blocks= ceil(n/4.0);
        for(int i=n-1, c=0; c<blocks; i--, c++){
            digits[i]=8;
        }
        for(int i=0; i<digits.size(); i+=1){
            std::cout << digits[i];
        }
        std::cout << std::endl;
    }
    return 0;
}

/*Logic
 * The problem state that there was a number x with n digits.
 * Those digits were first converted to binary and then concataned
 * WITHOUT LEADING 0, to form a binary number k.
 * Next, n binary numbers were removed.
 * This binary number is r.
 * Suppose, x=729, then n is 3, k=111 10 1001
 * Now if 3 binary digits are removed then r=111 10 1___ 
 * Now there exists x which is smaller than what the original x was
 * and still produces the same r.
 * So for the above example, new k = 111 10 1000, thus x= 728.
 * 
 * Now we will be given n, we have to write the MINIMUM x from
 * which r is MAXIMIZED.
 * So for r to be maximized, every n digits should be 9 which
 * in binary is a 4-bit number represented as 1001.
 * After removing n binary numbers, we are left with r.
 * Since, we are taking 4-bit binary number for digits the least
 * 4-bit binary number is 1000 which is 8 in decimal.
 * So for every block from which binary numbers were removed,
 * those will be replaced by 8.
 * 
 * For example, suppose n=5,
 * Then the old x=99999
 * Then k=1001 1001 1001 1001 1001
 * Removing n=4 binary numbers,
 * So, r=1001 1001 1001 100_ ____
 * Converting effected blocks as binary representation of 8 which is 1000
 * So, new k= 1001 1001 1001 1000 1000
 * From this, new x=99988
 */
