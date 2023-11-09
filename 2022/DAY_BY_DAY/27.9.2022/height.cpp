#include <bits/stdc++.h>
#define ll long long
#define foup(i,a,b) for(int i=(a); i<=(b); i++)
#define fown(i,a,b) for(int i=(a); i>=(b); i--)
const int vol=100000+3;
using namespace std;
int n;

struct table{
	int tall;
	int id;
	int sh;
};
table x[vol],b[vol];

bool cmp(table x, table y)
{
	return x.tall<y.tall;
}

bool pdk(table x, table y)
{
	return x.id < y.id;
}

void read()
{
	cin >> n;
	foup(i,1,n) cin >> x[i].tall, x[i].id=i ;
}

void xuly()
{
	int cnt=0, dem=0;
	sort(x+1,x+n+1,cmp);
	x[1].sh=cnt; 
	foup(i,2,n)
	{
		if(x[i].tall==x[i-1].tall)
		{
            x[i].sh=x[i-1].sh ; 
		}
		else
		{
			x[i].sh=i-1;  
		}
	}
	sort(x+1,x+n+1,pdk);
	foup(i,1,n) cout <<         x[i].sh << " ";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
 	freopen ("i.txt","r",stdin);
	freopen ("o.txt","w",stdout);
	read();
	xuly();
	return 0;
}