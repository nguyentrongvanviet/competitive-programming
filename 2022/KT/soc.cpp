#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5+5; 
const int inf = 1e17 ;  
int m,n,k;
long long b[N], s[N];
struct soc{
	int t;
	int p;
};
soc a[N];

bool hkt(int x, int y)
{
	return x>y;
}
void read()
{
	cin >> m >> n >> k;
	for (int i=1; i<=m; i++) cin >> a[i].t;
	for (int i=1; i<=m; i++) cin >> a[i].p;
}

int check(int w)
{
	for (int i=1; i<=m; i++)
	{
		if (w>=a[i].t)
		{
			b[i]=1+((w-a[i].t)/a[i].p);
		}
		else b[i]=0;
	}
	s[0]=0;
	sort (b+1,b+m+1,hkt);
    for(int i = 1; i<=n;i++)
    {
        s[i] = s[i-1]+b[i] ; 
        if(s[i]>=k)
        {
            return 1 ; 
        }
    }
	return 0;
}
void dual()
{
	int res=0; 
    int ent=0,end=inf; 
	while (ent<=end)
	{
		int mid=(ent+end)/2;
		if (check(mid))
		{
			res=mid;
			end = mid-1;
		}
		else ent= mid+1;
	}
	cout<<res; 
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen ("i.txt","r",stdin);
	freopen ("o.txt","w",stdout);
	read();
	dual();
	return 0;
}