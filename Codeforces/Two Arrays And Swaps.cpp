#include <bits/stdc++.h>
using namespace std;
int main() {
    priority_queue<int> a;
    priority_queue<int> b;
    int sum, temp, t, sz, k;
    cin>>t;
    while(t--){
        while(!a.empty()) a.pop();
        while(!b.empty()) b.pop();
        sum=0;
        cin>>sz>>k;
        for(int i=0; i<sz; i++){
            cin>>temp;
            sum+=temp;
            a.push((-1)*temp);
        }
        for(int i=0; i<sz; i++){
            cin>>temp;
            b.push(temp);
        }
        for(int i=0; i<k; i++){
            if((-1)*a.top()<b.top()){
                sum-=(-1)*a.top();
                sum+=b.top();
                temp=(-1)*a.top();
                a.pop();
                a.push((-1)*b.top());
                b.pop();
                b.push(temp);
            }else{
                break;
            }
        }
        cout<< sum << endl;
    }
    return 0;
}

/*Logic:
 * Choose the smallest number from a, and swap it with the biggest
 * number from b. Keep doing this till no more swaps are possible
 * or k swaps are made. the summation of the new array a is the answer.
 */
