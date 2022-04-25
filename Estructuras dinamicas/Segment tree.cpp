#include<bits/stdc++.h>
using namespace std;

struct st{ ///info de cada nodo
  st *left,*right;
  int sum,l,r,m;
  st(int l,int r):l(l),r(r),sum(0){ //intervalos men,may
       if(l!=r){
        m=(l+r)/2;
        left=new st(l,m);
        right=new st(m+1,r);

       }
  }
  //cambie el valor de la posicion de pos por el valor v
  void update(int pos,int v){
    if(l==r){
        sum=v;
    }else{
        if(pos<=m){
           left->update(pos,v);
        }else{
           right->update(pos,v);
        }
        sum=left->sum+right->sum;
    }
  }
  //suma en el intervalo a,b O l,r
  int get(int a,int b){
     if(a>r || b<l)
        return 0;
     if(a<=l && r<=b)
        return sum;
     return left->get(a,b)+right->get(a,b);
  }
};

int main(){

  st tree(0,8);
  for(int i=0;i<8;i++){
    int x;
    cin>>x;
    tree.update(i,x);
  }
  cout<<tree.get(1,3);
return 0;
}
