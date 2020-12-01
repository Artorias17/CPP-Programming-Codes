#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int x, sz, temp, minMoves, moves;
    cin>>x;
    while(x--){
        cin>> sz;
        unordered_map<int, int> ignoreIndex;
        unordered_map<int, vector<int>> index;
        for(int i=0; i<sz; ++i){
            cin >> temp;
            if(index[temp].empty()){
                ignoreIndex[temp]=0;
            }
            index[temp].push_back(i);
            if(index[temp].size() > 1 && (i - index[temp][index[temp].size()-2]) == 1){
                ignoreIndex[temp]+=1;
            }
        }
        minMoves = INT32_MAX;
        for(auto i : index){
            moves=0;
            if(i.second[0]!=0) moves++;
            if(i.second[i.second.size()-1] != sz-1) moves++;
            moves+= int(i.second.size())-ignoreIndex[i.first]-1;
            minMoves = min(minMoves, moves);
        }
        cout << minMoves << endl;
    }
    return 0;
}