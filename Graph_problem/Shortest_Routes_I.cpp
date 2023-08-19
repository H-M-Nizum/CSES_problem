#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<long long int,int> pli;

const int N = 1e5+7;
const long long int INF = 1e18+7;

vector<pii> adj[N];
vector<long long int> dist(N,INF);
vector<bool> visited(N,false);

void dijkstra(int s){
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[s] = 0;
    pq.push({dist[s], s});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u]) continue;;
        visited[u] = true;

        for(pii vpair: adj[u]){
            if(visited[vpair.first]) continue;

            if(dist[vpair.first] > dist[u] + vpair.second){
                dist[vpair.first] = dist[u] + vpair.second;
                pq.push({dist[vpair.first], vpair.first});
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;

        adj[u].push_back({v, w});

    }
    dijkstra(1);
    for(int i=1; i<=n; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}