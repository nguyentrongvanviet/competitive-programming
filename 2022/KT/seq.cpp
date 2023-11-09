#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

struct bg
{
    int val  ; 
    int len ; 
    bool operator<(bg x )
    {
        return val<x.val ; 
    }
};
int n  , q; 
bg a[N] ; 
int ma[N] ; 
int l[N] , r[N] ; 
int res(int val )
{   
    int ans =0 ; 
    int l = 1; 
    int r=  n ; 
    while(l<=r)
    {
        int mid =(l+r)/2; 
        if(a[mid].val<=val)
        {
            l=mid+1; 
            ans=ma[mid] ; 
        }
        else
        {
            r=mid-1; 
        }
    }
    return ans ; 
}
void inp()
{
    cin>> n>>q; 
    for(int i= 1 ;i<=n;i++)
    {
        cin>>a[i].val ; 
    }
    stack<int>st;  
    for(int i= 1; i<=n;i++)
    {
        while(!st.empty()&&a[st.top()].val<=a[i].val)
        {
            st.pop() ; 
        }
        if(st.empty())
        {
            l[i]= 1; 
        }
        else
        {
            l[i]= st.top()+1;  
        }
        st.push(i) ; 
    }
    while(!st.empty())
    {
        st.pop();
    }
    for(int i = n; i>=1;i--)
    {
         while(!st.empty()&&a[st.top()].val<=a[i].val)
        {
            st.pop() ; 
        }
        if(st.empty())
        {
            r[i]=n;
        }
        else
        {
            r[i]= st.top()-1;  
        }
        st.push(i) ; 
    }
    for(int i= 1;i<=n;i++)
    {
        a[i].len=r[i]-l[i]+1;
        // cout<<a[i].len<<" "; 
    }
    cout<<endl;
    sort(a+1,a+n+1);  
    for(int i= 1; i<=n;i++)
    {
        ma[i] =max(a[i].len,ma[i-1]);
    }
    for(int i= 1 ;i<=q;i++)
    {
        int val ; 
        cin>>val ; 
        cout<<res(val)<<"\n"; 
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}