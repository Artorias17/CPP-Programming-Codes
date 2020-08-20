#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
    string text;
    cin>>text;
    unordered_set<char> us;
    for(int i=0; i<text.size(); i++){
        us.insert(text[i]);
    }
    cout << ((us.size()==2) ? "Yes" : "No") << endl;
    return 0;
}
