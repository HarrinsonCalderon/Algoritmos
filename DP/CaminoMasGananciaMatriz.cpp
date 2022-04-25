#include<bits/stdc++.h>
using namespace std;
int const n=4,m=3,m2=4;
int dp[n][m];
int dp_top_down(int t[n][m],int i,int j){
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(i==0 && j==0){//base
        return t[i][j];
    }
    if(i==0){//filas
        return dp[0][j]=dp_top_down(t,0,j-1)+t[i][j];
    }
    if(j==0){//columnas
        return dp[i][0]=dp_top_down(t,i-1,0)+t[i][j];
    }
    return dp[i][j]=max(dp_top_down(t,i-1,j),dp_top_down(t,i,j-1))+t[i][j];
}
int dp_buttom_up(int t[n][m]){

 int memo[n][m];

 memset(memo,0,sizeof(memo));

 memo[0][0]=t[0][0];

 for(int i=1;i<n;i++){//filas
    memo[i][0]+=memo[i-1][0]+t[i][0];
 }
 for(int i=1;i<m;i++){//columnas
    memo[0][i]+=memo[0][i-1]+t[0][i];
 }
  for(int i=1;i<n;i++){
     for(int j=1;j<m;j++){
        memo[i][j]=max(memo[i-1][j],memo[i][j-1])+t[i][j];
     }
  }

  return memo[n-1][m-1];
}
int main(){
int t[n][m]={{5,6,4},{3,8,5},{2,11,15},{5,2,17}} ;
/*for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<t[i][j]<<" ";
    }
    cout<<"\n";
}*/
cout<<dp_buttom_up(t)<<"\n";
//
memset(dp,-1,sizeof(dp));
cout<<dp_top_down(t,n-1,m-1)<<"\n";

return 0;
}
//NOTA:las tablas aditivas de ambas maneras son iguales.
