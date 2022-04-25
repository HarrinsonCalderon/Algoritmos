#include<bits/stdc++.h>
using namespace std;
vector<int>dfs_low,dfs_num,s;
bool vis[100];
vector<int>grafo[100];
int dfsCont=0,N;

void tarjanSCC(int u){
dfs_low[u]=dfs_num[u]=dfsCont++;
s.push_back(u);
vis[u]=true;
for(int i=0;i<grafo[u].size();i++){
    int v=grafo[u][i];
    if(dfs_num[v]==-1){
        tarjanSCC(v);
    }
    if(vis[v]){
        dfs_low[u]=min(dfs_low[u],dfs_low[v]);
    }
}
if(dfs_low[u]==dfs_num[u]){
    cout<<"Componentes:\n";
    while(true){
        int v=s.back();
        s.pop_back();
        cout<<v<<"\n";
        vis[v]=false;
        if(v==u){
            break;
        }
    }
}
}

void solve(){
   dfs_num.assign(N+1,-1);
   dfs_low.assign(N+1,0);
   memset(vis,0,sizeof(vis));
   dfsCont=0;
   for(int i=0;i<N;i++){
        if(dfs_num[i]==-1){
            tarjanSCC(i);
        }
   }
}

int main(){

    N=7;
    for(int i=0;i<N;i++){
        grafo[i].clear();
    }
    grafo[0].push_back(1);
    grafo[1].push_back(3);
    grafo[3].push_back(2);
    grafo[2].push_back(1);
    grafo[3].push_back(4);
    grafo[4].push_back(5);
    grafo[5].push_back(7);
    grafo[7].push_back(6);
    grafo[6].push_back(4);
    solve();
return 0;
}


