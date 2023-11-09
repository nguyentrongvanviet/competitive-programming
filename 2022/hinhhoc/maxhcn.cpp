#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =1e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
#define int long long 
int n ; 
int a[N] ;
int l[N],r[N]; 
void inp()
{
    for(int i =1 ;i<=n;i++)
    {
        cin>>a[i] ; 
    }
    stack<int>st ; 
    for(int i= 1;i<=n;i++)
    {
        while(!st.empty()&&a[st.top()]>=a[i])
        {
            st.pop() ; 
        }
        if(st.empty())
        {
            l[i]=1; 
        }
        else 
        {
            l[i] = st.top()+1;
        }
        st.push(i);
    }
    while(!st.empty())
    {
        st.pop() ; 
    }
    for(int i= n;i>=1;i--)
    {
        while(!st.empty()&&a[st.top()]>=a[i])
        {
            st.pop();  
        }
        if(st.empty())
        {
            r[i] = n ;  
        }
        else 
        {
            r[i] = st.top()-1 ; 
        }
        st.push(i) ; 
    }
    int res= -oo ; 
    for(int i=1 ;i<=n;i++)
    {
        res=max(res,a[i]*(r[i]-l[i]+1)) ;
    }
    cout<<res<<"\n" ; 
}

signed  main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    while(1)
    {
        cin>> n ; 
        if(n==0)break ; 
        inp();
    }
    return 0;
}