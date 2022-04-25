#include<bits/stdc++.h>
using namespace std;
vector<int>grafo[100];
bool vis[100];
vector<int>ts;
void dfs(int u){
    vis[u]=true;
    for(int i=0;i<grafo[u].size();i++){
        int v=grafo[u][i];
        if(!vis[v]){
            dfs(v);
        }
    }
    ts.push_back(u); //Importante
}
void DAG(){
    for(int i=(int)ts.size()-1;i>=0;i--){
        cout<<ts[i]<<" ";
    }
}

void init(){
memset(vis,false,sizeof(vis));
for(int i=0;i<100;i++){
    grafo[i].clear();
}
}
int main(){
init();
grafo[0].push_back(1);
grafo[0].push_back(2);

grafo[1].push_back(3);
grafo[1].push_back(2);


grafo[2].push_back(5);
grafo[2].push_back(3);

grafo[3].push_back(4);

//grafo[4].push_back(1);

grafo[6].push_back(7);

for(int i=0;i<8;i++){
    if(!vis[i]){
        dfs(i);
    }
}
DAG();
return 0;
}
