#include <bits/stdc++.h>
using namespace std;

double rope=1;
int cuts=0;
string command;
int i, n, moves;
void recursiveCut(double sec){
    if(i == n) return;
    if(command[i++] == '1'){
        moves++;
        double left=sec/2;
        double right=sec-left;
        if(rope>left){
            rope=left;
            cuts=moves;
        }else if(rope>right){
            rope=right;
            cuts=moves;
        }
        recursiveCut(left);
        recursiveCut(right);
    }
}


int main() {
    int t=10;
    while(t--){
        cin>>n;
        cin.ignore();
        cin>>command;
        rope=1;
        i=0;
        cuts=0;
        moves=0;
        recursiveCut(1.0);
        cout<< cuts << endl;
    }
}

/*Logic:
 * The problem statement seemed poorly written
 * as most of the people didn't understand it.
 * We will be given a unknown length rope and
 * a series of commands in 1s and 0s. 1 means
 * we have to cut the rope in half. 0 means
 * do nothing.
 * Process of cutting
 * 110011000, and a rope of length 1 unit.
 *                  1
 *      0.5                      0.5
 *  0.25  0.25            0.25         0.25
 *                   0.125     0.125
 *                   
 * When first 1 is found 1 is split into two 0.5 unt segments.
 * Then we choose the left segment and find another 1. So
 * split that segment to two 0.25s. Next choose the left 0.25.
 * Found 0. Leave it. Choose the right 0.25. Found 0. Leave it.
 * 
 * Go back and choose the right 0.5 segment. Found 1. 
 * Split it to two 0.25s. Choose the left 0.25 unit segment. 
 * Found 1. Split it to two 0.125s. Choose the left 0.125. Found
 * 0. Leave it. Choose the right 0.125. Found 0. Leave it.
 * 
 * Go back and choose the right 0.25. Found 0. Leave it. The number
 * of cuts madde to reach 0.125 segment is the answer. Or in terms of
 * binary tree, do preorder tree and find the greatest depth.
 */
