#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        long long int x, y, a, b;
        long long int Only_a=0, First_a_then_b=0;
        cin>>x>>y>>a>>b;
        if(x==0 && y==0){
            cout<< 0 << endl;
        }else{
            First_a_then_b+= (max(x, y) - min(x, y)) * a;
            First_a_then_b+= min(x, y) * b;

            Only_a+= (x + y) * a;
            cout << min(Only_a, First_a_then_b) << endl;
        }
    }
    return 0;
}

/*Logic:
 * There are 2 ways to reach to zero.
 * Either pay only a to reduce (x+y)
 * or pay a till x and y becomes equal
 * and then pay b to reduce x and y together.
 */
