//Encontrar la subcadena mas grande o larga entre dos string
#include<bits/stdc++.h>
using namespace std;
int LCS(string a,string b){
    int l1,l2,maxx=0;
    l1=a.length();
    l2=b.length();
    int memo[l1+1][l2+1];

    memset(memo,0,sizeof(memo));
    for(int i=0;i<l1;i++){
        for(int j=0;j<l2;j++){
            if(a[i]==b[j]){

            if(i==0 || j==0){
                memo[i][j]=1;
            }else {
                memo[i][j]=memo[i-1][j-1]+1;
            }
            maxx=max(maxx,memo[i][j]);

            }
        }
    }
     /* for(int i=0;i<l1;i++){
        for(int j=0;j<l2;j++){
          cout<<memo[i][j]<<" ";
        }
        cout<<"\n";
    }*/
   return maxx;
}
int main(){
string a,b;
a="alsdfkjfjkdsal";
b="fdjskalajfkdsla";
cout<<LCS(a,b)<<" Es la longitud de la subcadena mas grande";

return 0;
}
