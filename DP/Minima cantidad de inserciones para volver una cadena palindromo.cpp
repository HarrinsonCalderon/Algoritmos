// A Dynamic Programming based program to find
// minimum number insertions needed to make a
// string palindrome
#include<bits/stdc++.h>
using namespace std;

    /*int min(int a, int b){
    return a < b ? a : b;
    }*/

int findMinInsertionsDP(string cad, int n){

    int memo[n][n], h;
    memset(memo, 0, sizeof(memo));

    for (int i = 1; i < n; ++i){
        for (int j = 0, h = i; h < n; ++j, ++h){
            if(cad[j]==cad[h]){
                memo[j][h]=memo[j+1][h-1];
            }else{
                memo[j][h]=(min(memo[j][h-1],memo[j+1][h]))+1;
            }
       }
   }
    // Return minimum number of insertions for

       return memo[0][n-1];
}

int main()
{
    //char str[] = "AACECAAAA";
    string cad="AACECAAAA";
    int n=findMinInsertionsDP(cad, cad.length());
    cout<<n;
    return 0;
}
