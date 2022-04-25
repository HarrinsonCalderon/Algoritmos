#include<bits/stdc++.h>
using namespace std;

int bs(int A[],int a,int b, int x){//vector,intervalo inferior,intervalo superior, a buscar
 while(a <= b){
 int m = (a + b) / 2;
 if(x == A[m])
    return m;
 else if(x > A[m])
 a = m + 1;
 else if(x < A[m])
 b = m - 1;
 }
 return -1;
}


int main(){
int v[]={1,2,3,4,5,6,7};
cout<<bs(v,0,7,1);
return 0;
}
