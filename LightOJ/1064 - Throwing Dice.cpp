#include <bits/stdc++.h>
int t, n, x;
long long int dice_Sum[26][151];
long long int search(int diceRemaining, int SumRemaining){
    if(diceRemaining == 0){
        if(SumRemaining <= 0){
            return 1;
        }else{
            return 0;
        }
    }else if(dice_Sum[diceRemaining][SumRemaining] != -1){
        return dice_Sum[diceRemaining][SumRemaining];
    }else{
        long long int numerator=0;
        for(int i=1; i<=6; i++){
           numerator+=search(diceRemaining - 1, SumRemaining - i);
        }
        dice_Sum[diceRemaining][SumRemaining]=numerator;
        return numerator;
    }
}
void reset(){
    for(int i=0; i<26; i++){
        for(int j=0; j<151; j++){
            dice_Sum[i][j]=-1;
        }
    }
}
int main() {
    std::cin>>t;
    for(int i=1; i<=t; i++){
        reset();
        std::cin>>n>>x;
        long long int numerator=search(n, x);
        long long int denominator=pow(6, n);
        long long int gcd=std::__gcd(numerator, denominator);
        numerator/=gcd;
        denominator/=gcd;
        if(numerator==denominator){
            printf("Case %d: %d\n", i, 1);
        }else if(numerator==0){
            printf("Case %d: %d\n", i, 0);
        }else{
            printf("Case %d: %lld/%lld\n", i, numerator, denominator);
        }
    }
}

/*Logic:
 * This problem required the use of dynamic programming.
 * We will basically recursively check whether every dice.
 * If remaining sum is greater than 0 after n dice rolls
 * (meaning it wasn't able to exceed x after all n die),
 * then that combination will not produce n. Else, then that
 * way produces sum greater or equal to x, thus return 1.
 *
 * For every die remaining and sum remaining, we will store
 * all the possible ways in a matrix for future use.
 */
