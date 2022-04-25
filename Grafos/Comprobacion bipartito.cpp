#include<bits/stdc++.h>
using namespace std;

const int MAX=100;
vector<vector<int>>g(MAX);
int vis[MAX];

bool bipartito(int u){
    queue<int>q;
    q.push(u);
    vis[u]=1;
    while(q.size()){
    u=q.front();
    q.pop();
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]==0){
            q.push(v);
            if(vis[u]==1){
                vis[v]=2;
            }else if(vis[u]==2){
                vis[v]=1;
            }
        }else if(vis[v]==vis[u]){
          return false;
        }
      }
    }

    return true;
}

int main() {
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

int nodos,aristas,u,v;
cin>>nodos>>aristas;

for(int i=0;i<nodos;i++){
     g[i].clear();
     vis[i]=0;
}
for(int i=0;i<aristas;i++){
    cin>>u>>v;
    g[u].push_back(v);
}

if(bipartito(0)){
    cout<<"Es bipartito\n";
}else{
    cout<<"No es bipartito\n";
}

return 0;
}

