#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int number;
        int sum=1;
        scanf("%d", &number);
        for(int i=2; i<=sqrt(number); i++){
            if(number%i==0){
                sum=sum+i;
                if(number/i!=i){
                    sum=sum+ (number/i);
                }
            }
        }
        if(number==1){
            sum=0;
        }
        printf("%d\n", sum);
    }
    return 0;
}
