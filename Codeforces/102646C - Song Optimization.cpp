#include <iostream>
#include <vector>
using namespace std;

struct edge{
    int u, v, w;
};

int main() {
    int k, n;
    cin>>n>>k;
    vector<vector<long long int>> path(k, vector<long long int>(k));
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            cin>>path[i][j];
        }
    }

    for(int i=0; i<k; i++){
        for(int s=0; s<k; s++){
            for(int d=0; d<k; d++){
                if(path[s][i]+path[i][d]< path[s][d]){
                    path[s][d]=path[s][i]+path[i][d];
                }
            }
        }
    }
    long long int sum=0;
    vector<edge> e(n-1);
    for(int i=0; i<n-1; i++){
        if(i==0){
            cin>>e[i].u;
            cin>>e[i].v;
            e[i].u--;
        }else{
            e[i].u=e[i-1].v;
            cin>>e[i].v;
        }
        e[i].v--;
        e[i].w=path[e[i].u][e[i].v];
        sum+=e[i].w;
    }

    long long int newSumCost=sum;
    for(int i=0; i<e.size(); i++){
        if(i==0 || i==e.size()-1){
            newSumCost=min(newSumCost, sum-e[i].w);
        }else{
            newSumCost=min(min(newSumCost, sum-e[i].w-e[i+1].w+path[e[i].u][e[i+1].v]), sum-e[i].w-e[i-1].w+path[e[i-1].u][e[i].v]);
        }
    }
    cout << newSumCost << endl;
    return 0;
}

/*Logic:
 * This problem states that there is a time delay for moving from
 * one chord to the next and that information is given. We are required
 * to find the minimum time to complete the given pattern by changing
 * at most 1 chord in the pattern. Another thing, we can have intermediate 
 * chord between 2 chord patterns.
 * So, 
 * given a pattern
 * 1 2 3 4 5
 * It can go something like 1 3 5 2 3 5 4 5
 * 
 * To solve this, we will run a shortest path algorithm where the chords are
 * vertices and the time delay is weight of edge. Floyd Warshall seems
 * reasonable. This way we will have all path shortest path. Next,
 * a struct was created to simulate edge. From the pattern, the 2 adjacent chords
 * become vertices and from the Floyd Warshall algorithm we can find the weight.
 * Do this for the pattern. Store summation of time in a variable.
 * 
 * Here comes the part where I was getting WA.
 * Since chord changing to itself is instantaneous, the time is 0.
 * Since we are required to find the minimum time and can change a chord
 * to any chord, ->>> it is ideal to switch the chord to any of its adjacent chord <<<-
 * 
 * Suppose
 * 1---2----3-----4
 * If the edge 2---3 costs way too high, then
 * 1----3----3-----4
 * 1----2----2-----4
 * are the 2 options we have.
 *
 * What I was doing wrong---------
 * Here if a chord is changed, I was only manupulating 1 edge.
 * That is is 2---3 is changed, I was doing something like this
 * 1---2    3---4       OR     1---2    3---4
 *     |________|              |________|
 * As there's an extra edge not taken care of I was getting WA.
 * 
 * What I did to get AC-------
 * Taken care of that loose edge and chose the minimum from checking all edges
 * Suppose
 * 1---2----3-----4
 * If 2-----3 link is broken
 * Then 1---3---3---4. So erased the cost for 2---3 and 1---2 edges
 * and added 1---3 edge.
 * OR
 * Then 1---2---2---4. So erased the cost for 2---3 and 3---4 edges
 * and added 2---4 edge.
 * 
 * Special Case-------
 * If the troubling edge is the 1st or the last one, we can simply delete them
 * without any extra step.
 */
