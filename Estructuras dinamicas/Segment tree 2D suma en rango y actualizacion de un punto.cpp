///Problema de plantilla de matriz bidimensional en forma de árbol, actualización de un solo punto, suma de submatriz.

#include<bits/stdc++.h>
#define MAXN 2005
using namespace std;

typedef long long int ll;
ll n,m;
ll a[MAXN][MAXN],tree[MAXN][MAXN];
ll lowbit(ll x)
{
	return x&-x;
}
//en la posicion f,c, sumar p
void agregar(ll x,ll y,ll p)
{
	for(ll i=x;i<=n;i+=lowbit(i))
		for(ll j=y;j<=m;j+=lowbit(j))
			tree[i][j]+=p;
}
ll sum(ll x,ll y)
{
    ll result=0;
	for(ll i=x;i>0;i-=lowbit(i))
		for(ll j=y;j>0;j-=lowbit(j))
			result+=tree[i][j];
    return result;
}
ll suma(ll x1,ll y1,ll x2,ll y2)//left-top right-low
{
    return sum(x2,y2)+sum(x1-1,y1-1)-sum(x2,y1-1)-sum(x1-1,y2);
}
int main()
{
	cin>>n>>m;
	memset(tree,0,sizeof(tree));
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cin>>a[i][j];
			agregar(i,j,a[i][j]);
		}
	}
	//inferior f,c superior f c
	ll x1,y1,x2,y2;
	 cin>>x1>>y1>>x2>>y2;
	 cout<<suma(x1,y1,x2,y2)<<"\n";
     cin>>x1>>y1>>x2>>y2;
	 cout<<suma(x1,y1,x2,y2)<<"\n";

    //para sumar a una posicion
    suma(2,2,5);
}

/**
3 3
1 2 3
4 5 6
7 8 9
1 1 3 3
2 2 3 3
*/

