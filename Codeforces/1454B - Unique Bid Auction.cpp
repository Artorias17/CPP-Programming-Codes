#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    int x, sz, temp, ans;
    map<int, vector<int>> bidIndex;
    cin>>x;
    while(x--) {
        cin >> sz;
        for(int i=0; i< sz; ++i){
            cin>> temp;
            bidIndex[temp].push_back(i);
        }
        ans = -1;
        for(auto i : bidIndex){
            if(i.second.size()==1){
                ans = i.second[0]+1;
                break;
            }
        }
        cout << ans << endl;
        bidIndex.clear();
    }
    return 0;
}
