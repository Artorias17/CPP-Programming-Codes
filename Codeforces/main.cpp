#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        long long n, m, x, y;
        cin>>n>>m>>x>>y;
        if(x<=y) cout << m << endl; //If restoration exceeds, spell cost
                                    //then, spell can be cast every second.
        else{
            n+=(m-1)*y; //For each second, mana is restored regardless spell cast.
                        // Thus, add all restoration mana beforehand.
                        //Note that, mana is restored in the last second, but that
                        //restored mana is never used. Thus, m-1 times mana is restored.

            n/=x; //This gives us how many of total mana can be used for casting.

            cout << min(n, m) << endl;
            /*Some cases, where initial mana was high
             * and added on that the total restoration mana,
             * the total number of castings would exceed
             * the number of seconds. As castings and restoration
             * or only restoration takes 1 second, the maximum
             * castings that can be done m times. Thus, here minimum of
             * number of casting found vs m is printed.
             */

        }
    }
}
