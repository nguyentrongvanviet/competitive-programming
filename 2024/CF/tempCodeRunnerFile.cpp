#include<iostream>
#include<vector>
using namespace std;


signed main()
{	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	int test; cin >> test;
	while (test--)
	{
		int n, m, q; cin >> n >> m >> q;
		vector<int>a(n + 1); 
		for (int i = 1; i <= n; i++)cin >> a[i];
		vector<int>b(n + 1); 
		for(int i=1;i<=m;i++)
		{
			cin >> b[i]; 
		}
        vector<int>dd(n+1,0) ; 
        int ok = 0 ; 
        for(int i=1;i<=m;i++)
        {
            if(dd[a[i]])continue ;
            if(a[i]!=b[i])
            {
                cout<<"TIDAK"<<endl;
                ok = 1 ;
                break;
            } 
            dd[a[i]] = 1;  
        }
        if(ok==0)cout<<"YA"<<endl;
	}
}