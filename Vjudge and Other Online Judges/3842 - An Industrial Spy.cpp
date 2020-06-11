#include <cstdio>
#include <bitset>
#include <cmath>
#include <vector>

using namespace std;
const unsigned int sz=(unsigned int)1e7;
bitset<sz> prime;
bitset<sz> flag;

void seive(){
    prime.set();
    int sq=sqrt(sz);
    prime[0]=prime[1]=false;
    for(int i=4; i<sz; i+=2){
        prime[i]=false;
    }
    for(int i=3; i<=sq; i+=2){
        if(prime[i]){
            for(int j=i*i; j<sz; j+=i+i){
                prime[j]=false;
            }
        }
    }
}


void DFS(int s, string num, vector<bool> &vis, int mul=10){
    if(prime[s]) flag.set(s, true);
    for(int i=0; i<num.size(); i++){
        if(!vis[i]){
            vis[i]=true;
            DFS(s + (num[i] - '0') * mul, num, vis, mul*10);
            vis[i]=false;
        }
    }
}


int main() {
    seive();
    bitset<10> last;
    int t;
    char text[10];
    scanf("%d%c", &t, &text[0]);
    while(t--){
        scanf("%s", text);
        string num=text;
        vector<bool> vis(num.size(), false);
        last.reset();
        last[0]=last[4]=last[6]=last[8]=true;
        flag.reset();
        for(int i=0; i<num.size(); i++){
            if(!last[num[i]-'0']){
                if(num[i]-'0'==2 || num[i]-'0'==5){
                    flag.set(num[i]-'0', true);
                }else{
                    vis[i]=true;
                    DFS(num[i]-'0', num, vis);
                    vis[i]=false;
                }
                last[num[i]-'0']=true;
            }
        }
        printf("%d\n", (int)flag.count());
    }
    return 0;
}

/*Logic:
 * Brute forced this problem.
 * Used one bitset to store primes and another to mark numbers
 * which are found using DFS.
 * Primes often end with a 1 or a 5 or a 7 or a 9.
 * So used that to reduce generation cost.
 * 2 and 5 are externally marked if they exist in the string.
 *
 * Misc:
 * The compiler for this problem seems to be old or missing some
 * header files, as it doesn't recognize unordered_set and auto keyword.
 * 10^7 seems to give AC while 10^8 gives TLE when used for seive.
 * Using set to store the numbers found and then checking their primality
 * gives TLE.
 */
