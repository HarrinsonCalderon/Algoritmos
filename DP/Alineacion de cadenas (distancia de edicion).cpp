#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int peso=1;

int main() {
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

string a= "AGTCTGACGC", b = "AGTAAGTAGGC";
int n=a.length();
int m=b.length();
for(int i=0;i<=n;i++)//f
    dp[i][0]=i;
for(int i=0;i<=m;i++)//c
    dp[0][i]=i;

for(int i=1;i<=n;i++){
 for(int j=1;j<=m;j++){
     if(a[i-1]==b[j-1]){
        dp[i][j]=dp[i-1][j-1]; //No tiene peso
     }else{
        dp[i][j]=min(dp[i-1][j]+peso,dp[i][j-1]+peso); //de la fila y columna anterior
        dp[i][j]=min(dp[i][j],dp[i-1][j-1]+peso); //con peso
     }
 }

}

for(int i=0;i<=n;i++){
 for(int j=0;j<=m;j++){
    cout<<dp[i][j]<<" ";
 }
 cout<<"\n";
}
cout<<"Distancia "<<dp[n][m]<<"\n";
return 0;
}


