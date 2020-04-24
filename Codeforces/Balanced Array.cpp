#include <bits/stdc++.h>
using namespace std;

map<long, bool> odd;
int look;
void oddMaker(long sum){
    long lim=sum/2;
    for(long i=look; i<lim; i+=2){
        if(look==i) look+=2;
        if(odd.find(i) == odd.find(sum - i)){
            odd[sum-i]=true;
            odd[i]=true;
            return;
        }
    }
}
void evenMaker(long k, long send=1){
    for(int i=1; i<=k; i+=2){
        cout<< 2*i << " " << 2*(i+1) <<" ";
        oddMaker((2*i)+(2*(i+1)));
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if((n/2)%2==0) {
            look=1;
            cout<< "YES" << endl;
            evenMaker(n/2);
            for(auto i=odd.begin();true;){
                cout<< i->first;
                if(++i==odd.end()){
                    cout<< endl;
                    break;
                }else{
                    cout<< " ";
                }
            }
            odd.clear();
        }else{
            cout<< "NO" << endl;
        }
    }
}
