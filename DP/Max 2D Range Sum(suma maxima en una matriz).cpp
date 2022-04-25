//Nos devuelve la suma maxima de todas las submatrices
#include<bits/stdc++.h>
using namespace std;
int n, matriz[101][101], maxSuma, subSuma;
int main() {
  cin>>n;
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    cin>>matriz[i][j];
    if (i>0) matriz[i][j]+=matriz[i-1][j];
    if (j>0) matriz[i][j]+=matriz[i][j-1];
    if (i>0 && j>0) matriz[i][j]-=matriz[i-1][j-1];
  }
  maxSuma=-127*100*100;
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    for (int k = i; k < n; k++) for (int l = j; l < n; l++) {
      subSuma = matriz[k][l];
      if (i > 0) subSuma -= matriz[i - 1][l];
      if (j > 0) subSuma -= matriz[k][j - 1];
      if (i > 0 && j > 0) subSuma += matriz[i - 1][j - 1];
      maxSuma = max(maxSuma, subSuma); }
 cout<<maxSuma<<"\n";
  return 0;
}

