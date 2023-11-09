#include<bits/stdc++.h>
using namespace std;

#define TASK "NKLEXIC"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =32,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;
#define MAX "99999999999"
string To_string(int s)
{
    string ans=""; 
    while(s)
    {   
        int c=  s%10;
        ans=(char)(c+'0')+ans;
        s/=10;
    }
    return ans;
}
string cong(string a , string b )
{
    string ans="";
    while(a.size()<b.size())a='0'+a; 
    while(b.size()<a.size())b='0'+b; 
    int du = 0  ;  
    for(int i= b.size()-1;i>=0;i--)
    {
        int tmp = a[i]-'0'+b[i]-'0'+du ;
        int c= tmp%10 ; 
        du =tmp/10 ; 
        ans=(char)(c+'0')+ans;  
    }
    if(du)
    {
        ans=(char)(du+'0')+ans;
    }
    return ans ;
}
string mul(string a , int b)
{
    string ans="";
    int du =0  ;
    for(int i= a.size()-1;i>=0;i--)
    {
        int tmp =(a[i]-'0')*b+du ;
        du=tmp/10 ;
        int c= tmp%10;
        ans=(char)(c+'0')+ans;
    }
    if(du)
    {
        ans=(char)(du+'0')+ans;
    }
    return ans ;
}
string nhan(string a ,  string b)
{
    string ans=""; 
    string zero=""; 
    for(int i=b.size()-1;i>=0;i--)
    {
        string tmp = mul(a,b[i]-'0');
        tmp+=zero;
        ans=cong(ans,tmp) ;
        zero+='0';
    } 
    return ans;
}
string tru(string a,  string b)
{
    string ans="";
    while(b.size()<a.size())
    {
        b='0'+b; 
    }
    int thieu = 0 ;
    for(int i= a.size()-1;i>=0;i--)
    {
        int tmp = a[i]-b[i]-thieu ;
        if(tmp<0)
        {
            tmp+=10;
            thieu = 1; 
        }
        else 
        {
            thieu =0  ;
        }
        int c= tmp%10; 
        ans=(char)(c+'0')+ans;
    }
    while(ans.size()>1&&ans[0]=='0')
    {
        ans.erase(0,1);
    }
    return ans ; 
}
bool ss(string a,  string b)
{
    if(a.size()<b.size())return 1; 
    if(a.size()>b.size())return 0 ;
    return a<=b;
}
string A[N][N];

int n , m;   

void doc()
{
    cin>>n>>m ; 
    char x; 
    cin>>x ; 
    if(x=='P')
    {
        string s ; 
        cin>>s;
        vector<int>dd(n+1,0);
        if(m!=s.size())
        {
            cout<<"Incorrect data\n";
            return;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>'a'+n-1||dd[s[i]-'a'+1]==1||s[i]<'a'||s[i]>'z')
            {
                cout<<"Incorrect data"<<"\n";
                return ; 
            }
            dd[s[i]-'a'+1]=1;
        }
        dd=vector<int>(n+1,0) ;
        s='!'+s;
        string res="";
        for(int i=1;i<=m;i++)
        {
            int cnt=  0 ; 
            for(int j=1;j<s[i]-'a'+1;j++)
            {
                if(dd[j]==0)cnt++;
            }
            res=cong(res,nhan(A[n-i][m-i],To_string(cnt)));
            dd[s[i]-'a'+1]=1;
        }
        cout<<cong(res,"1")<<"\n";
    }
    else 
    {
        string x ; cin>>x ;
        if(!ss(x,A[n][m]))
        {
            cout<<"Incorrect data\n";
            return ; 
        }
        if(x=="0")
        {
            cout<<"Incorrect data\n";
            return ;
        }
        x=tru(x,"1");
        vector<int>dd(n+1,0);
        for(int i=1 ;i<=m;i++)
        {
            for(int j= 1;j<=n;j++)
            {
                if(dd[j]==0)
                {
                    if(ss(A[n-i][m-i],x))
                    {
                        x=tru(x,A[n-i][m-i]);
                    }
                    else 
                    {
                        cout<<(char)(j+'a'-1); 
                        dd[j]=1; 
                        break; 
                    }
                }
            }
        }
        cout<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    A[0][0]="1";
    for(int i= 1 ;i<=26;i++)
    {
        A[i][0] ="1";
        for(int j= 1 ; j<=i;j++)
        {
            int u = i-j+1;
            string tmp  =To_string(u);
            A[i][j] =nhan(A[i][j-1],tmp);
        }
    }
    int t ; 
    t=1;
    cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}