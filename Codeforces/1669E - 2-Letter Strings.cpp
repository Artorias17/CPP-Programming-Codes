#include <iostream>
#include <unordered_map>

#define key(itr) itr->first
#define value(itr) itr->second

typedef unsigned long long int u_long;
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    int t, n;
    u_long counter;
    cin >> t;
    unordered_map<string, u_long> mp;
    string temp;
    bool firstChar, secondChar;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> temp;
            if(mp.count(temp)){
                mp[temp]++;
            }else{
                mp[temp] = 1;
            }
        }

        counter = 0;
        for(auto i= mp.begin(); i!= mp.end(); i++){
            for(auto j = next(i, 1); j!=mp.end(); j++){
                firstChar = key(i)[0] == key(j)[0];
                secondChar = key(i)[1] == key(j)[1];
                if (firstChar ^ secondChar)
                    counter += value(i) * value(j);
            }
        }

        cout << counter << endl;
        mp.clear();
    }
    return 0;
}

/*
 * Logic:
 * Using an unordered map, store the string and their corresponding frequencies.
 * Then for each pair of string keys where they differ at 1 character, multiply
 * each other's frequencies and add it to the existing counter.
 * This is done so because, for each position in one key, all positions in other
 * key can form a pair.
 */
