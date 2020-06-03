#include <bits/stdc++.h>
using namespace std;

double dijkstra(vector<vector<pair<int, double>>> &adjMat){
    priority_queue<pair<double, int>> pq;
    vector<double> prob(adjMat.size(), 0);
    vector<int> parent(adjMat.size(), INT_MAX);
    vector<bool> visited(adjMat.size(), false);
    prob[0]=100;
    parent[0]=-1;
    pq.push({100.0, 0});
    int u, v;
    while(!pq.empty()){
        u=pq.top().second;
        pq.pop();
        if(!visited[u]){
            visited[u]=true;
            for(int i=0; i<adjMat[u].size(); i++){
                v = adjMat[u][i].first;
                double probability = adjMat[u][i].second;
                if(!visited[v] && prob[v] < probability*prob[u]){
                    prob[v]= probability*prob[u];
                    parent[v]=u;
                    pq.push({prob[v], v});
                }
            }
        }
    }
    u=(int)adjMat.size()-1;

    return prob[u];
}

int main(){
    int n, m, u, v;
    double p;
    while(cin>>n && n!=0){
        cin>>m;
        vector<vector<pair<int, double>>> adjMat(n);
        for(int i=0; i<m; i++){
            cin>>u>>v>>p;
            u--;
            v--;
            p=p/100;
            adjMat[u].push_back({v, p});
            adjMat[v].push_back({u, p});
        }
        printf("%.6lf percent\n", dijkstra(adjMat));
    }
    return 0;
}

/*Logic:
 * This problem requires the usage of dijkstra bt with slight modification.
 * We are required to find the greatest probability of independent cases.
 * So, P(A and B) = P(A) * P(B).
 * Now, if we check only the immediate probability instead of overall probability
 * we will get WA. Because, in one node we may choose the path of greatest probability
 * from that node. However, that path may not produce the overall greatest probability.
 * That is why, for any node v from node u, we need to choose
 * max(AlreadySetOverallProbability[v], probabilityTill[u]*probability[u][v]).
 * Misc:
 * Had issue with segmented seive, don't know why, switching to vector solved it.
 * Faced MLE when matrix was used.
 * Faed TLE without priority_queue.
 * priority_queue of pair will create max heap based on first of the pair.
 */
