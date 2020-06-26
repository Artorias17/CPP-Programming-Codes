#include <bits/stdc++.h>
using namespace std;

struct NODE{
    bitset<30> val;
    bool doOR=false;
    NODE(){
        val.reset();
        doOR=false;
    }
};
vector<NODE> tree;

void op(int node) {
    //OR
    if(tree[2 * node + 1].doOR && tree[2 * node + 2].doOR){
        tree[node].val= tree[2 * node + 1].val | tree[2 * node + 2].val;
        tree[node].doOR=false;
    }
    //XOR
    else if((!tree[2 * node + 1].doOR && !tree[2 * node + 2].doOR)){
        tree[node].val= tree[2 * node + 1].val ^ tree[2 * node + 2].val;
        tree[node].doOR=true;
    }
}


void setTree(vector<NODE>&g, int l, int r, int node){
    if(l==r){
        int n;
        cin>>n;
        g[node].val|=n;
        g[node].doOR=true;
    }else{
        setTree(g, l, (l+r)/2, 2*node+1);
        setTree(g, ((l+r)/2)+1, r, 2*node+2);
        op(node);
    }
}


void assignVal(int p, int b, int l, int r, int node){
    //NO OVERLAP
    if(p<l || p>r){
        return;
    }
    //FULL OVERLAP
    if(l==r && l==p){
        tree[node].val=0|b;
    }
    //PARTIAL OVERLAP
    else{
        assignVal(p, b, l, (l+r)/2, 2*node+1);
        assignVal(p, b, ((l+r)/2)+1, r, 2*node+2);
        op(node);
    }
}

int main() {
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, p, b;
    cin>>n>>m;
    n=pow(2, n);
    tree.resize(2*n-1);
    setTree(tree, 0, n-1, 0);
    for(int i=0; i<m; i++){
        cin>>p>>b;
        p--;
        assignVal(p, b, 0, n-1, 0);
        cout<< tree[0].val.to_ulong() << endl;
    }
}

/*Logic:
 * This problem requires the idea segment tree.
 * Used a structure called NODE which contains the bitset for value of size 30
 * and a boolean flag to indicate bitwise operation to do with it.
 * The rest is standard segment tree operation.
 */
