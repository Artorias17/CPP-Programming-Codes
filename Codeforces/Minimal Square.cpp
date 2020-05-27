#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        int len=min(a, b)*2;
        int up=2*max(a, b);
        int down=max(a, b);
        if(len<=up && len>=down){
            cout<< len*len << endl;
        }else{
            cout<< max(a, b)*max(a, b) << endl;
        }
    }
}
