#include <bits/stdc++.h>
#define MOD 1000000007
#define NumOfPrime 62 //Number of primes from 1 to 300
using namespace std;

struct NODE{
    int v;
    bitset<NumOfPrime> p;
};

int n, q, l, r, x;
char g[10];
vector<int> prime;
vector<int> inversePrime;
vector<NODE> segmentTree;
vector<NODE> updateTree;

//This function is used to multiply two numbers and then mod it by 1e9+7 with the help of long long
int mul(int z, int y){
    return (1LL*z*y)%MOD;
}
//This function is used to find power of a number mod 1e9+7
//If power is even then, z=z*z and half the power, else y= y*z. Reduce power by 1
//Continue this till power reaches 0.
int power(int z, int p){
    int y=1;
    while(true){
        if(p%2!=0){
            y=mul(y, z);
            p--;
        }
        if(p==0) break;
        z=mul(z, z);
        p/=2;
    }
    return y%MOD;
}

//Basic seive
void seive(){
    bitset<301> flag;
    flag.set();
    for(int i=2; i<301; i+=2){
        if(flag[i]){
            prime.push_back(i);
            for(int j=i*i; j<301; j+=i+i){
                flag[j]=false;
            }
        }
        if(i==2) i--;
    }
}

//Modular multiplicative Inverse
void inversePrimeMaker(){
    inversePrime.resize(NumOfPrime);
    for(int i=0; i<NumOfPrime; i++){
        inversePrime[i]=power(prime[i], MOD-2); //SEE Below why MOD-2.
    }
}
//Fills the nodes of segment tree, the product of childres is set to parent
//and the prime bitsets of both children are OR-ed and then stored into parent's bitset
NODE setSegmentTree(vector<int> &a, int node, int left, int right){
    if(left==right){
        segmentTree[node].v=a[left];
        for(int i=0; i < NumOfPrime; i++){
            if(a[left]%prime[i]==0){
                segmentTree[node].p[i]=true;
            }
        }
    }else{
        NODE x=setSegmentTree(a, 2*node+1, left, (left+right)/2);
        NODE y=setSegmentTree(a, 2*node+2, ((left+right)/2)+1, right);

        segmentTree[node].v=(int)((1LL*x.v*y.v)%MOD);
        segmentTree[node].p= x.p | y.p;
    }
    return segmentTree[node];
}

//Creates vectors for segment tree and an update tree for lazy propagation
//Size of tree = 2*pow(2, ceil(log(Number of elements in array)/log(2))) -1
void createTree(vector<int> &arr){
    int sz=ceil(log(n)/log(2));
    sz=2*pow(2, sz)-1;
    segmentTree.resize(sz);
    updateTree.resize(sz);
    for(int i=0; i<sz; i++){
        updateTree[i].v=1;
        updateTree[i].p.reset();
    }
    setSegmentTree(arr, 0, 0, n-1);
}

//This function is used to check if updateTree has any value waiting
//to be multiplied. This also stores any wailting bitset of primes
//It first multiplies the pending number to node.
//Then does OR operation on the bitset.
//Next it pushes the multiplier to its children node in the updateTree along with the bitset
//After that resets this node in the updateTree signalling that node is up to date
//Caution: Since each node has certain range, this means that multiplication of some value
//has to be powered first to the number of leaf node under that node.
void checkUpdate(int node, int arrLeft, int arrRight){
    if(updateTree[node].v!=1){
        int nodePower=arrRight-arrLeft+1;
        segmentTree[node].v=mul(segmentTree[node].v, power(updateTree[node].v, nodePower));
        segmentTree[node].p|=updateTree[node].p;
        //UpdateTree.size() shouldn't be used as there might be some empty leaves
        if(arrLeft!=arrRight){
            updateTree[2*node+1].v = mul(updateTree[2*node+1].v, updateTree[node].v);
            updateTree[2*node+1].p |= updateTree[node].p;
            updateTree[2*node+2].v = mul(updateTree[2*node+2].v, updateTree[node].v);
            updateTree[2*node+2].p |= updateTree[node].p;
        }
        updateTree[node].v=1;
        updateTree[node].p.reset();
    }
}
//This function is used to multiply x.
//If l and r fully overlaps a range represented by a node, then multiply that x
// to the corresponding node of the updateTree and return back while updating the parents.
//If there is a partial overlap then it goes to both its children, make changes and returns
//back to it and makes changes.
//Updating the parents while returning back---
//If a fully overlapped node was found, then multiply all its parent and their parents ... till root
//with then number of leaf nodes to be multiplied by x. This is found by arrRight-arrLeft+1
//There are 3 types of partial overlap.
//1| when l and r are inside arrLeft and arrRight
//2| when l is outside of arrLeft and arrRight
//3| when r is outside of arrLeft and arrRight
//In order to do multiply x, first we need the number of leaf nodes under that node
//This is found by max(arrLeft, l) and min(arrRight, r). X to the power this, then
//multiplying to the node is done.
//Bitsets of that node's children from both trees are OR-ed and stored in that node.
//If there's no overlap then it simply returns to the calling function without any changes.
void multiplyX(bitset<NumOfPrime> &xPrime, int node, int arrLeft, int arrRight){
    //NO OVERLAP
    if(r<arrLeft || l>arrRight) {
        return;
    }
    checkUpdate(node, arrLeft, arrRight);
    //FULL OVERLAP
    if(l<=arrLeft && r>=arrRight){
        updateTree[node].v=x; //Putting it in the update tree for later update
        updateTree[node].p|=xPrime; //Same here
        return;
    }
    //PARTIAL OVERLAP
    else{
        multiplyX(xPrime, 2 * node + 1, arrLeft, (arrLeft + arrRight) / 2);
        multiplyX(xPrime, 2 * node + 2, (arrLeft + arrRight) / 2 + 1, arrRight);

        int xPower=min(arrRight, r)-max(arrLeft, l)+1;
        segmentTree[node].v=mul(segmentTree[node].v, power(x, xPower));
        segmentTree[node].p=segmentTree[2*node+1].p|segmentTree[2*node+2].p; //Gets new children primes
        segmentTree[node].p|=updateTree[2*node+1].p|updateTree[2*node+2].p; //Since child updates are in the update tree, parent should also have its children's new primes.
        return;
    }
}

//If l and r fully overlaps the range represented by a node, it return that node
//to the calling function.
//If l and r partially overlaps then it goes to both its children for queries and then returns to it
//It creates a new node outside of trees which it fills
//with product of its children and OR-ed bitset from children bitsets
//If there's no overlap then it returns an empty node.
NODE getNode(int node, int arrLeft, int arrRight){
    //NO OVERLAP
    if(r<arrLeft || l>arrRight){
        NODE garbage;
        garbage.v=1, garbage.p.reset();
        return garbage;
    }
    checkUpdate(node, arrLeft, arrRight);
    //FULL OVERLAP
    if(l<=arrLeft && r>=arrRight){
        return segmentTree[node];
    }
    //PARTIAL OVERLAP
    else{
        NODE x= getNode(2*node+1, arrLeft, (arrLeft+arrRight)/2);
        NODE y= getNode(2*node+2, (arrLeft+arrRight)/2 + 1, arrRight);
        NODE z;
        z.v= mul(x.v, y.v);
        z.p= x.p | y.p;
        return z;
    }
}

int main(){
    seive();
    inversePrimeMaker();

    scanf("%d%d%c", &n, &q, &g[0]);
    vector<int> arr(n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    scanf("%c", &g[0]);
    createTree(arr);
    bitset<NumOfPrime> xPrime;
    while(q--){
        scanf("%s%d%d", g, &l, &r);
        l--, r--;
        if(g[0]=='M'){
            scanf("%d%c", &x, &g[0]);
            xPrime.reset();
            for(int i=0; i<NumOfPrime; i++){
                if(x%prime[i]==0) xPrime[i]=true;
            }
            multiplyX(xPrime, 0, 0, n - 1);
        }else{
            NODE ansNode=getNode(0, 0, n-1);
            for(int i=0; i<NumOfPrime; i++){
                if(ansNode.p[i]){
                    ansNode.v=mul(ansNode.v, prime[i]-1);
                    ansNode.v=mul(ansNode.v, inversePrime[i]);
                }
            }
            printf("%d\n", ansNode.v);
        }
    }
    return 0;
}

/*Logic:
 * This problem is really hard especially if you have no idea about Euler totient function,
 * Modular multiplicative inverse and segment tree with lazy propagation.
 *
 * Euler totient function phi(n)= n* product of (1-(1/pi)), where pi is ith prime factor of n.
 * This function is multiplicaive in nature. Meaning phi(n)=phi(a)*phi(b).
 * Also, phi(prime^k)=prime^k(1-(1/prime))= (prime^k)((prime-1)/prime) =(prime^k-1)(prime-1)
 *
 * Modular multiplicative inverse for an integer a is an integer x for which a*x is equivalent to 1%M
 * Euler's theorem for this states that a^phi(M) is equivalent to 1%M.
 * In both of this cases, a and M must be coprimes.
 *
 * Read or search about segmet tree and lazy propagation
 *
 * MISC:
 * Initialy, there was a problem with multiplyX function for which I was getting WA.
 * I was multiplying x for a node which is a product of a certain range.
 * So multiple of xs reside. But I was multiplying single x.
 *
 * Double may have been giving wrong answer
 * Euler totient function states that phi(num)=num * product of all (1-(1/pi)) where pi is  ith prime
 * Need to learn and use modular multiplicative inverse
 * So this is what I came up with after reading about modular multiplicative inverse
 * num is already stored in the segment tree in the form num%MOD
 * Only thing to tackle are products of (1-(1/pi))
 * Consider this,
 * 1-(1/p) can be written as (p-1)/p.
 * Take p as a, Now modular multiplicative inverse states that a*x is equivalent to 1%M
 * So x is 1/a which is 1/p. Also this is only true if and only if a and m are coprimes.
 * Euler's theorem states that  pow(a, phi(M)) is equivalent to 1%M where phi(M) is Euler totient of M
 * This also holds true if and only if a and M are coprimes.
 * From this, to get (1/a)%M multiply both sides with it
 * This results in pow(a, phi(M)-1) is equivalent to (1/a)%M
 * And thus, this solves the problem of dividing when modulo is involved.
 * Now, M=1e+7, Euler totient of M is 1e+6 as M is prime. Then phi(M)-1 is 1e+5.
 */
