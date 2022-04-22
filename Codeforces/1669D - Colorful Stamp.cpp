#include <iostream>
#include <vector>
using namespace std;

vector<string> getBlock(const string &s) {
    vector<string> substring;
    substring.emplace_back("");
    int blockIndex = 0;

    for(const char &i : s){
        if(i == 'W'){
            substring.emplace_back("");
            blockIndex++;
        }else{
            substring[blockIndex] += i;
        }
    }
    return substring;
}

int main(){
    int t, n;
    bool canMakePattern;
    string s;
    cin>> t;
    while(t--){
        cin >> n;
        cin >> s;
        canMakePattern = true;
        vector<string> blocks = getBlock(s);

        for(auto &block : blocks){
            if(!canMakePattern) break;
            switch (block.length()) {
                case 0: continue;
                case 1:
                    canMakePattern = false;
                    break;
                default:
                    canMakePattern = false;
                    for (int i = 0; i < block.size() - 1; i++) {
                        if (block[i] != block[i + 1]) {
                            canMakePattern = true;
                            break;
                        }
                    }
            }
        }
        if(canMakePattern) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

/*
 * Logic:
 * Split the given string into blocks where the delimiter for splitting is 'W'.
 * For each block size, if it is 0, then move on to the next block.
 * If it is 1, then we cannot make the pattern with the stamp.
 * If it is 2 or more, then there needs to be at least 1 of the other colour to make the pattern possible.
 */
