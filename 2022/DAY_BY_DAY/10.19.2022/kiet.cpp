#include <bits/stdc++.h>
#define ll long long
#define foup(i,a,b) for(int i=(a); i<=(b); i++)
#define fown(i,a,b) for(int i=(a); i>=(b); i--)
#define pb push_back
#define pp pop_back
const int K=1000000+3;
using namespace std;
int n, k, ans=-K, a[K];
deque <int> q;

void read()
{
	cin >> n >> k;
	foup(i,1,n) cin >> a[i];
}

void hard()
{
	int cnt =0 ;
	foup(i,1,n)
	{
		while(q.size() && a[q.back()] < a[i]) q.pp();
		
		if(q.size()>=2 && q.front()+k<=i)
		{
			q.pop_front();
		}
		else
			if(i>=2 && a[i]==a[q.front()])
		{
			q.pop_front(); ans=i;
		}
		q.pb(i);
		if(i>=k)
		{
			if(q.front()!=ans)
			{
				cnt++; ans=q.front();
			}
		}
	}
	cout << cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//   	freopen ("MAXK.INP","r",stdin);
//  	freopen ("MAXK.OUT","w",stdout);
	read();
	hard();
	return 0;
}