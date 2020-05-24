#include <bits/stdc++.h>
using namespace std;

int main() {
    int b, k, g;
    cin>>b>>k>>g;
    cout<< (b-1)/(k/g) + (((b-1)%(k/g))?1:0) << endl;
    return 0;
}

/*Logic:
 * The troll used to live in 1 of the bridges, so we can rule out
 * 1 of the bridges in the beginning. Then the number of groups that
 * can be formed will check that many bridges in one day.
 */
