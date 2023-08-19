#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];
int level[N];
int parent[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    parent[s] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v:adj[u]){
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;

            level[v] = level[u] + 1;
            parent[v] = u;
        }

    }
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);
    if(level[n] == 0){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<level[n]+1<<endl;
        vector<int> ans;
        int curr = n;

        while(curr != -1){
            ans.push_back(curr);
            curr = parent[curr];
        }

        reverse(ans.begin(), ans.end());

        for(int i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }

}