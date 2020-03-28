#include <bits/stdc++.h>
using namespace std;

static bool arr[1000001];
void seive(){
    fill(arr+0, arr+1000001, true);
    arr[0]=arr[1]=false;
    for(int s=4; s<1000001; s+=2){
        arr[s]=false;
    }
    for(int t=3; t<=sqrt(1000001); t+=2){
        if(arr[t]){
            for(int u=t*t; u<1000001; u+=2*t){
                arr[u]=false;
            }
        }
    }
}
int main() {
    seive();
    int n, count;
    while(scanf("%d", &n) && n!=0){
        printf("%d : ", n);
        count=0;
        bool same=false;
        double rootn=sqrt(n);
        for(int i=2; i<=rootn;){
            if(arr[i] && n%i==0){
                if(!same) count++;
                n/=i;
                same=true;
            } else{
                if(i==2){
                    i++;
                }else{
                    i+=2;
                }
                same=false;
            }
        }
        if(floor(rootn)!=ceil(rootn) && n!=1) count++;
        printf("%d\n", count);
    }
}

/*Logic
 * Use seive to find the prime numbers.
 * Then use prime factorization to get the prime numbers present in the number.
 * Count the different prime numbers
 */
