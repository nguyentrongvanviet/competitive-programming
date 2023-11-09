#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define TASK "sum0"
#define X first
#define Y second
const int N =4e3+5, oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
int n ; 
int a[N][N]  ; 
vector<int>q; 
int x[4001*4001] ; 
void inp()
{
     scanf("%d",&n) ;
     char  u ; 
     cin>>u  ; 
     while(1)
     {
          cin>>u; 
          cout<<u;  
     }
     // for(int i= 1; i<=n;i++)
     // {
     //      for(int j =1;j<=4;j++)
     //      {
     //           char x; 
     //           bool am =0  ;
     //           cin>>x ; 
     //           ll val= 0 ; 
     //           if(x=='-')am=1 ; 
     //           else val=x-'0';
     //           while(1);
     //           {
     //                if(x==' ')break;
     //                val*=10; 
     //                val+=x-'0'; 
     //           }
     //           a[i][j] = val;      
     //           if(am)
     //           {
     //                a[i][j] =-a[i][j];
     //           }
     //           cout<<a[i][j]<<" ";
     //           // scanf("%d",&a[i][j]); 
     //      }cout<<endl;
     // }
     int m = 0  ; 
     for(int i=1;i<=n;i++)
     {
          for(int j = 1 ;j<=n;j++)
          {
               x[++m]=  a[i][1]+a[j][2]; 
          }
     }
     sort(x+1,x+m+1) ; 
     int res =0 ;  
     for(int i= 1 ;i<=n;i++)
     {
          for(int j =1;j<=n;j++)
          {
               res+=upper_bound(x+1,x+m+1,-a[i][3]-a[j][4])-lower_bound(x+1,x+m+1,-a[i][3]-a[j][4]);
          }
     }
     printf("%d",res);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    inp();
    return 0;
}