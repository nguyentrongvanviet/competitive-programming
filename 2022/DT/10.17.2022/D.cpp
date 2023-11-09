#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =10+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
string s;  
void input()
{
   	cin>> n;  
   	cin>> s;
   	int len = 0 ;
   	for(int i= 0 ;i<s.size();i++)
   	{
   		if(s[i]=='0')
   		{
   			len=n-i; 
   			break;
   		}
   	}
   	bitset<N>a(s);
   	bitset<N>b(s.substr(0,len));
   	res=max(a&b);
   	for(int i=0;i<n-len+1;i++)
   	{

   	}
}
void output()
{
    
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}