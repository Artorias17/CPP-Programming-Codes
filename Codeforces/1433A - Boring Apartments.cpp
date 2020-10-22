#include <iostream>
using namespace std;

int main() {
    int t;
    cin>> t;
    cin.ignore();
    while(t--){
        string y;
        cin>>y;
        int ans=(y[0]-'0'-1)*10;
        for(int i=1; i<=y.size(); i++){
            ans+=i;
        }
        cout << to_string(ans)+"\n";
    }
    return 0;
}
