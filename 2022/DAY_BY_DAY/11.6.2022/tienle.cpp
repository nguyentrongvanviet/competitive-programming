#include<bits/stdc++.h>
using namespace std;
long long Q,n,m;
long long a[1005],b[1005],f[200][200];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>Q>>n>>m;
    for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		a[i]=x;b[i]=x;
	}
	for(int i=1;i<=m;i++){
		long long x;
		cin>>x;
		a[n+i]=x;b[n+i]=x-1;
	}
	n=n+m;
	long long res=-1e18;
	for(int i=1;i<=n;i++) for(int j=1;j<=Q;j++)
	{
		f[i][j]=f[i-1][j];
		if(a[i]<=j)
		{
			f[i][j]=max(f[i][j],b[i]+f[i-1][j-a[i]]);
		}
		res=max(res,f[i][j]);	
	}
	cout<<res;
}