#include <bits/stdc++.h>
using namespace std;
bool p[1420];
map<int, vector<int>> val;
void seive(){
    int len=sizeof(p)/sizeof(p[0]);
    double sq=sqrt(len);
    memset(p, true, sizeof(p));
    p[0]=p[1]=false;
    for(int i=4; i<len; i+=2){
        p[i]=false;
    }
    for(int i=3; i<=sq; i+=2){
        if(p[i]){
            for(int j=i*i; j<len; j+=i+i){
                p[j]=false;
            }
        }
    }
}

int main() {
    seive();
    val[1].push_back(1);
    for(int i=2; i<2000001; i++){
        if(i<sizeof(p)/sizeof(p[0]) && p[i]){
            val[1].push_back(i);
        }else{
            int factors=0;
            int v=i;
            for(int j=2; j<=sqrt(v); j+=2){
                if(p[j] && v%j==0){
                    int power=0;
                    while(v%(int)pow(j, power+1)==0) power++;
                    factors+=power;
                    v/=(int)pow(j, power);
                }
                if(j==2) j--;
            }
            if(v!=1) factors++;
            val[factors].push_back(i);
        }
    }
    int place;
    int TestCase=1;
    while(cin>>place && place!=0){
        for(auto i=val.begin(); i!=val.end(); i++){
            vector<int> list=i->second;
            if(list.size()<place){
                place-=list.size();
            }else{
                printf("Case %d: %d\n", TestCase, list[place-1]);
                TestCase++;
                break;
            }
        }
    }
    return 0;
}

/*Logic:
 * Used seive and prime factorization to calculate the number of factors
 * for a number and used that with map to auto sort the numbers.
 */
