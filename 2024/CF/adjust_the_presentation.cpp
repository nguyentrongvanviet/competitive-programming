#include<bits/stdc++.h>
using namespace std;
const int N =2e5+5;  
int n , m ,q ; 
int dd[N], a[N] , b[N] ; 
signed main()
{	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	int test; cin >> test;
	while (test--)
	{
		cin >> n >> m >> q;
		for (int i = 1; i <= n; i++)cin>>a[i];
		for(int i=1;i<=m;i++)cin>>b[i] ; 
        int ok = 0 , cnt = 1 ;  
        for(int i=1;i<=m&&cnt!=n;i++)
        {
            if(dd[b[i]])continue ;
            if(a[cnt]!=b[i])
            {
                cout<<"TIDAK"<<'\n';
                ok = 1 ;
                break;
            } 
            dd[a[cnt++]] = 1;  
        }
        if(ok==0)cout<<"YA"<<'\n';
        for(int i=1;i<=n;i++)dd[i] = 0 ; 
	}
}