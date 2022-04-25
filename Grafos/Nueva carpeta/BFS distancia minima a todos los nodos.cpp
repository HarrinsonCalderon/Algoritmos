#include<bits/stdc++.h>
using namespace std;

int main(){
int n,nodo,aristas,x,caminos;
cin>>n;
vector<int>g[n];
cin>>caminos;
for(int i=0;i<caminos;i++){
    cin>>nodo>>aristas;
    while(aristas--){
        cin>>x;
        g[nodo].push_back(x);
    }
}
cout<<"grafo\n";
for(int i=0;i<n;i++){
    cout<<i<<"<-\n";
    for(int j=0;j<g[i].size();j++){
        cout<<g[i][j]<<" ";
    }
    cout<<"\n";
}
vector<int>dis(n,-1);
queue<int>p;
p.push(1);
dis[1]=0;
while(p.size()){
 int u=p.front();
 p.pop();
 for(int i=0;i<g[u].size();i++){
    int v=g[u][i];
    if(dis[v]==-1){
        p.push(v);
        dis[v]=dis[u]+1;
    }
 }
}
cout<<"distancias\n";
for(int i=0;i<n;i++){
    cout<<i<<" "<<dis[i]<<"\n";
}
return 0;
}
/*
7
6
1 2 3 2
2 2 3 4
3 1 5
4 1 6
5 1 6
6 1 0
*/

