#include<bits/stdc++.h>
using namespace std ;


#define TASK "suffix_atomation"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define vi vector<int> 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
void IOS()
{
    fast 
    srand(time(0)) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}
struct state {
    int len, link;
    map<char, int> next;
};
const int MAXLEN = 100000;
state st[MAXLEN * 2];
int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz= 0 ; 
    last = 0;
}

void sa_extend(char c) {
	int cur = ++sz; 
	st[cur].len = st[last].len + 1;
	int p = last;
	while (p != -1 && !st[p].next.count(c)) {
	    st[p].next[c] = cur;
	    cout<<p<<" "<<cur<<endl; 
	    p = st[p].link;
	}
	if (p == -1) {
	    st[cur].link = 0;
	} 
	else 
	{
	    int q = st[p].next[c];
	   	
	    if (st[p].len + 1 == st[q].len) 
	    {
	        st[cur].link = q;
	    } 
	    else 
	    {
	        int clone =++sz; 
	        st[clone].len = st[p].len + 1;


	        st[clone].next = st[q].next;
	        st[clone].link = st[q].link;

	        while (p != -1 && st[p].next[c] == q) {
	            st[p].next[c] = clone;
	            cout<<p<<" "<<clone<<endl; 
	            p = st[p].link;
	        }
	        st[q].link = st[cur].link = clone;
	    }
	}
	last = cur;
}
int main()
{
	IOS();
	sa_init() ;
	string s;   
	cin>>s; 
	int n = s.size();
	FOR(i,1,n)
	{
		sa_extend(s[i-1]) ; 
		cout<<endl;
	} 
	return 0 ; 
}