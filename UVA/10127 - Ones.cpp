#include <bits/stdc++.h>
using namespace std;
static long arr[10001];
int find(int n){
    int number=0;
    int ones=floor(log10(n))+1;
    for(int i=1; i<=ones; i++){
        number=(number*10)+1;
    }
    while(number%n!=0){
        ones++;
        number=((number%n)*10)+1;
    }
    return ones;
}
int main() {
    int n;
    while(cin>>n)
        cout<< find(n) << endl;
    return 0;
}

/* Logic:
 * We know that number of digits can be found by
 * floor(log10(n))+1. Using that to produce the least
 * ones required to start dividing by n.
 * If the division produces remainder, we concat
 * one and keep trying until remainder becomes 0.
 */
