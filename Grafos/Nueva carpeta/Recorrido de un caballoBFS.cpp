#include<bits/stdc++.h>
using namespace std;
#define MAX 502
bool m[MAX][MAX];
int n,c,p,q,xi,yi,xf,yf;

struct solve{
int x,y,d;
 solve(int x1,int y1,int d1):x(x1),y(y1),d(d1){}
};
int bfs(){
int dx[]={-p,-p,-q,q,p,p,q,-q};
int dy[]={-q,q,p,p,q,-q,-p,-p};
solve in(xi,yi,0);//inicial
queue<solve>cola;
cola.push(in);
while(!cola.empty()){
solve now=cola.front();
cola.pop();
if(now.x==xf && now.y==yf){
    return now.d;
}
if(m[now.x][now.y]){//ya lo visite omita y pase el siguiente
  continue;
}
m[now.x][now.y]=true;
for(int i=0;i<8;i++){
 int x=now.x+dx[i];
 int y=now.y+dy[i];
 if(x>0 && x<=c && y>0 && y<=n){
    solve r(x,y,now.d+1);
    cola.push(r);
 }
}
}
return -1;
}
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>c;//fila columnas
cin>>xi>>yi>>xf>>yf;
cin>>p>>q;//movimientos
cout<<bfs()<<"\n";



return 0;
}
