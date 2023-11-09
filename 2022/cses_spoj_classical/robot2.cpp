#include <bits/stdc++.h>
#define ll int 
#define foup(i,a,b) for(int i=(a); i<=(b); i++)
#define fown(i,a,b) for(int i=(a); i>=(b); i--)
const int vol=100000+3;
using namespace std;
ll n, m, a[vol];

void read()
{
	cin >> n >> m;
	foup(i,1,m) cin >> a[i];
}

int check(ll k)
{
	ll dem=0,d;
	foup(i,1,m)
	{
		d=a[i];
		while(d>k)
		{
			d=d-k;
			dem++;
			if (n<dem) return 0;
		}
		if (d<=k) 
		{
			dem++;
			if (n<dem) return 0;
		}
	}
	return 1;
}

void xuly()
{
	sort(a+1,a+m+1);
	ll res=0;
	ll le=1, ri=a[m];
	while (le<=ri)
	{
		ll mid=(le+ri)/2;
		if (check(mid))
		{
			res = mid;
			ri = mid-1;
		}
		else le = mid+1;
	}
	cout << res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
  	freopen ("ROBOT2.INP","r",stdin);
 	freopen ("ROBOT2.OUT","w",stdout);
	read();
	xuly();
	return 0;
}