#include <bits/stdc++.h>
using namespace std;

long N=0;
bool bits[100000001];

void seive(){
    long size= sizeof(bits)/ sizeof(bits[0]);
    fill(bits+0, bits+size, true);
    bits[0]=bits[1]=false;
    for(int i=4; i<size; i+=2){
        bits[i]=false;
    }

    for(int i=3; i<=sqrt(size); i+=2){
        if(bits[i]){
            for(int j=i*i; j<size; j+=2*i){
                bits[j]=false;
            }
        }
    }
}

int main() {
    seive();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>N && N>0){

        for(long i=2; i<=sqrt(N);){
            if(N<i){
                break;
            }
            else if(bits[i] && N%i==0){
                N=N/i;
                cout<< "    "<< i << endl;
            }
            else{
                if(i>2){
                    i+=2;
                }else{
                    i++;
                }
            }
        }
        if(!(N==0 || N==1)){
            cout<< "    " << N << endl;
        }
        cout<< endl;
    }
    return 0;
}
