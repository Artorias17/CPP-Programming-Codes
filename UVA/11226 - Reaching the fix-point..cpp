#include <bits/stdc++.h>
using namespace std;
int sum[500001];
bool p[500001];
void seive(){
    int sz= sizeof(sum)/ sizeof(sum[0]);
    memset(p, true, sizeof(p));
    p[0]=p[1]=false;
    for(int i=4; i<sz; i+=2){
        p[i]=false;
    }
    for(int i=3; i<sqrt(sz); i+=2){
        if(p[i]){
            for(int j=i*i; j<sz; j+=i+i){
                p[j]=false;
            }
        }
    }
}
void preCalc(){
    seive();
    memset(sum, 0, sizeof(sum));
    sum[2]=2;
    sum[3]=3;
    for(int i=4; i< sizeof(sum)/ sizeof(sum[0]); i++){
        int s=0, v=i;
        for(int j=2; j<=sqrt(v); j+=2){
            if(p[j] && v%j==0){
                int power=0;
                while(v%(int)pow(j, ++power)==0);
                power--;
                s+=j*power;
                v/=(int)pow(j, power);
            }
            if(j==2) j--;
        }
        if(v!=1){
            s+=v;
        }
        sum[i]=s;
    }
}
int main() {
    preCalc();
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        cout<< "Case #"<< i << ":\n";
        int n, m, maximum=0;
        cin>>n>>m;
        for(int j=min(n,m); j<=max(n,m); j++){
            int count=1;
            int index=j;
            while(sum[index]!=index){
                count++;
                index=sum[index];
            }
            maximum=max(count, maximum);
        }
        cout << maximum << endl;
    }
    return 0;
}

/* Logic:
 * Used seive to find prime numbers.
 * Then added the (power of prime * prime number)
 * that are factors of N.
 * Divided N by (power of prime * prime number) over each 
 * iteration to shorten the prime search.
 */
