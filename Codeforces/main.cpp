#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin>>n>>m;
    n++;
    cin.ignore();
    map<int, set<string>> mp;
    string s;
    for(int i=0; i<m; i++){
        cin>>s;
        s+=" ";
        mp[s.size()].insert(s);
    }
    int c=0;
    for(auto i=mp.begin(); i!=mp.end(); i++){
        int words=min(n/(int)i->first, (int)i->second.size());
        c+=words;
        n-=words*(int)i->first;
    }
    cout << c << endl;
}
/*Logic:
 * Used a map with key as string length and value as
 * set of unique words of that length. For all unique
 * word 1 extra space is added at the end as spaces will
 * consume character space. Thus, the given n is increased by 1
 * for making the code easier to write as last word won't require space.
 */