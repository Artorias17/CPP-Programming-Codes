#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<unsigned int> pq;
    unsigned int sz, i;
    scanf("%u", &sz);
    for(i=0; i<sz; i++){
        unsigned int temp;
        scanf("%u", &temp);
        pq.push(temp);
        if(i>sz/2){
            pq.pop();
        }
    }
    double ans=0;
    if(sz%2==0){
        ans+=pq.top();
        pq.pop();
        ans+=pq.top();
        ans/=2;
    }else{
        ans+=pq.top();
    }
    printf("%.1f", ans);
    return 0;
}

/*Logic:
 * Priority Queue uses heap sort to bring the largest
 * value to the top.
 * So, the idea is that if we fill (half+1) for even
 * number of numbers in the priority queue, then for
 * the rest, we will first insert and then delete the 
 * top value which is the largest value.
 * After this, answer is found by popping out 2 top
 * numbers from priority queue. For odd number of numbers
 * pop out just 1.
 */
