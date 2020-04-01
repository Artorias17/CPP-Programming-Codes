#include <bits/stdc++.h>
using namespace std;

/*
 * Logic:
 * The diagonals have the sequece
 *    1,  3,  7,   13,   21
 *      2    4   6     8
 *         2   2    2
 * It's a second degree polynomial sequence
 * A(n^2)+Bn+C
 * Here, A, B, C are constants and n=0, 1, 2, ....
 * Results are A=1, B=1, C=1
 * Thus, the sequence formula is (n+1)th term=n^2+ n+ 1
 */

int main() {
    long t, s, sec=1, n=-1, x, y, upper, lower;
    scanf("%ld", &t);
    for(long i=1; i<=t; i++){
        scanf("%ld", &s);

        double check[2];
        check[0]=floor((-1+(sqrt(1-(4*(1-s)))))/2);
        check[1]=ceil((-1+(sqrt(1-(4*(1-s)))))/2);
        n=(long)check[0];
        sec=(long)pow(n, 2)+ n +1;
        upper= sec + n, lower= sec - n;
        if(!(s<=upper && s>=lower)){
            n=(long)check[1];
            sec=(long)pow(n, 2)+ n +1;
            upper= sec + n, lower= sec - n;
        }

        if(s<=sec && s>= lower){
            if(n % 2 == 0){
                x= n + 1;
                y=s-lower+1;
            }else{
                y= n + 1;
                x=s-lower+1;
            }
        }else if(s>=sec && s<= upper){
            if(n % 2 == 0){
                y= n + 1;
                x=upper-s+1;
            }else{
                x= n + 1;
                y=upper-s+1;
            }
        }
        printf("Case %d: %d %d\n", i, x, y);
    }
}
