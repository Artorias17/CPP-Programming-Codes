#include <bits/stdc++.h>
using namespace std;

vector<int>price(200000);
vector<long long int>maxPriceForEdgeCount(200001);
vector<int> A, B, C;

void BFS(int source, vector<int> &dis, vector<vector<int>> &connection){
    queue<int> q;
    q.push(source);
    dis[source]=0;
    while(!q.empty()){
        int working=q.front();
        q.pop();
        for(int i=0; i<connection[working].size(); i++){
            int vertex=connection[working][i];
            if(dis[vertex] > dis[working] + 1){
                dis[vertex]=dis[working]+1;
                q.push(vertex);
            }
        }
    }
}

int main() {
    int t, n, m, a, b, c;
    long long int answer;
    cin>>t;
    while(t--){
        cin>>n>>m>>a>>b>>c;
        a--, b--, c--;
        A.resize(n), B.resize(n), C.resize(n);
        vector<vector<int>> matrix(n);
        for(int i=0; i<n; i++){
            A[i]=B[i]=C[i]=INT_MAX;
        }
        for(int i=0; i<m; i++){
            cin>>price[i];
        }
        sort(price.begin(), price.begin()+m);
        for(int i=1; i<=m; i++){
            maxPriceForEdgeCount[i]= maxPriceForEdgeCount[i - 1] + price[i - 1];
        }
        for(int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            matrix[u-1].push_back(v-1);
            matrix[v-1].push_back(u-1);
        }
        BFS(a, A, matrix);
        BFS(b, B, matrix);
        BFS(c, C, matrix);
        answer=LLONG_MAX;
        for(int intermediate=0; intermediate<n; intermediate++){
            if(A[intermediate]+B[intermediate]+C[intermediate]<=m){
                long long int costTwiceTraversed= maxPriceForEdgeCount[B[intermediate]] * 2;
                long long int costOnceTraversed=maxPriceForEdgeCount[A[intermediate] + C[intermediate] + B[intermediate]];
                costOnceTraversed-=maxPriceForEdgeCount[B[intermediate]];
                answer=min(answer, costOnceTraversed+costTwiceTraversed);
            }
        }
        cout<< answer << endl;
    }
    return 0;
}

/*Logic:
 * The problem requires to find the smallest cost of travelling from A->B->C.
 * Same paths can be traversed more than once.
 * So, in order to lower the cost of travelling, we have to traverse same path
 * twice. For example, if 3 paths are used, w, x, y, z are costs and w>x>y>z
 * then w+w+x will always be less than w+x+y or w+x+z. Also lowering the number
 * of paths taken will also lower the cost.
 *
 * Now, the path, we need to go from A->B->C.
 * There may be a case where C comes before B in the path. In that case, we need to
 * traverse A->C->B->C.
 *
 * This along with lowering the cost by traversing the same path and reducing the paths
 * used hints to the fact we  need to lower the number of paths, so we need to find the
 * shortest paths. As we don't know how to distribute the costs, all paths initially will
 * cost 1. Thus, Dikjstra changes to BFS.
 *
 * Next, as we need to re use the same path, we need to know which nodes to revisit.
 * Assume, A->X-B->X->C, where X is some intermediate node. We can see that, A->X,
 * X->C will always be traversed once. B->X == X->B. So this path will be traversed twice.
 * Assigning the lowest cost to B->X is ideal. Then, assign the next lowest costs to A->X
 * and X->C.Since, we don't know the intermediate node, we will run 3 seperate
 * BFS with source A, B and C store the distance or paths used in 3 arrays.
 *
 * Now, since we don't know how many unique paths will be used, we need to use prefix sum
 * to generate the maximum lowest costs for number of unique paths. We need to sort the
 * prices in ascending order. Then, prefix[i]= prefix[i-1]+price[j], where i= number of edges,
 * j=the next smallest price.
 *
 * Now, we need to check for every intermediate nodes, what the cost.
 * Note that, the number of nodes unique paths used will never exceed the number of
 * paths given. So for am intermediate node X, pathUsed(A, X)+pathUsed(B, X)+pathUsed(C, X)<=paths given.
 *
 * Now, we will used prefix sum array to get the cost for the path with intermediate node X.
 * (prefix[pathUsed(B, X)]*2)+((prefix[pathUsed(A, X)+pathUsed(B, X)+pathUsed(C, X)])-prefix[pathUsed(B, X)])
 * The minimum of all the intermediate nodes is the answer.
 */
