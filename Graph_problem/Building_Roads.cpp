#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];

void dfs(int u){
    visited[u] = true;

    for(int v:adj[u]){
        if(visited[v]) continue;
        dfs(v);
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

    int c = 0;
    vector<int> ans;
    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        dfs(i);
        ans.push_back(i);
        c++;
    }
    if(c==1){
        cout<<c-1<<endl;
    }
    else{
        cout<<c-1<<endl;
        for(int i=1; i<ans.size(); i++){
            cout<<ans[i-1]<<" "<<ans[i]<<endl;;
        }
        
    }
    
}