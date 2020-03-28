#include <bits/stdc++.h>
using namespace std;

double ln[1000001];
int main() {
    ln[0]=ln[1]=0;
    for(int i=2; i<1000001; i++){
        ln[i]=ln[i-1]+ log(i);
    }
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        int n, b;
        scanf("%d %d", &n, &b);
        printf("Case %d: %d\n", i, (int)floor(ln[n]/log(b))+1);
    }
}

/*Logic
 * ln(ab)= ln(a)+ln(b)
 * Then,
 * ln(n!)=ln(1)+ln(2)+ln(3)+...+ln(n)
 * Now, for the number of digits in n
 * The formula becomes
 * floor(ln(n!))+1
 * => floor(ln(1)+ln(2)+ln(3)+...+ln(n))+1
 * And for different base divide by ln[base]
 * floor(ln(n!)/ln[base])+1= floor((ln(1)+ln(2)+ln(3)+...+ln(n))/ln[base])+1
 */
