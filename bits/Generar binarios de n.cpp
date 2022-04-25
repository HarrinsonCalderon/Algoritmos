#include<bits/stdc++.h>
using namespace std;
int main()
{
 int a,b;
 cin>>a;
 for(int i=0;i<(1<<a);i++){
  for(int j=a-1;j>=0;j--){
    cout<<(i & (1<<j));
  }
  cout<<"\n";
 }
 return 0;
}
/*
3

000=0
001=1
010=2
011=3
100=4
101=5
110=6
111=7


000=0
001=1
020=2
021=3
400=4
401=5
420=6
421=7

*/
