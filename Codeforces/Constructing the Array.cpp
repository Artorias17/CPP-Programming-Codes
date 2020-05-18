#include <bits/stdc++.h>
using namespace std;

//Class block contains the left and right indices and number of zeros
class block{
public:
    int l, r, zeros;
    block(int l, int r, int zeros) : l(l), r(r), zeros(zeros){}
};

//Operator oveloading (< operator can be overloaded for priority queue)
bool operator<(const block &a, const block &b){
    if(a.zeros<b.zeros){
        return true;
    }else if(a.zeros==b.zeros){
        return a.l>b.l;
    }else{
        return false;
    }
}
int main() {
    map<int, string> storage;
    int arr[2000001];
    priority_queue<block> b;
    int t, n, counter, mid;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        if(storage.find(n)==storage.end()){
            memset(arr, 0, sizeof(arr));
            b.push(*new block(0, n-1, n-1-0+1));
            counter=1;
            while(!b.empty()){
                if(b.top().zeros%2==0){
                    mid=(b.top().l+b.top().r-1)/2;
                }else{
                    mid=(b.top().l+b.top().r)/2;
                }
                arr[mid]=counter++;
                if(mid-1>=0 && arr[mid-1]==0){
                    b.push(*new block(b.top().l, mid-1, (mid-1)-b.top().l+1));
                }
                if(mid+1<n && arr[mid+1]==0){
                    b.push(*new block(mid+1, b.top().r, b.top().r-(mid+1)+1));
                }
                b.pop();
            }
            storage[n]="";
            for(int i=0; i<n-1; i++){
                storage[n]+= to_string(arr[i]) + " ";
            }
            storage[n]+= to_string(arr[n-1]) + "\n";
        }
        cout << storage[n];
    }
    return 0;
}

/*Logic:
 * Created a class called block which contains left index, right index and the number of zeros for
 * that block. Created a priority queue with an overloaded operator < , as custom rules for
 * priority queue requires operator to be overloaded. The new rules for < are as follows:
 * If block a has less zeros than block b, then block a precedes than block b.
 * If block a and b has the same amount of zeros, then
 * block a precedes block b if block a's left index is greater than block b's left index.
 *
 * A map with relation to n and the string of answer was required to prevent re-evaluation for already
 * processed n.
 *
 * Misc:
 * Less than operator "<" was required for priority queue. Need to look more into operator overloading in cpp
 */
