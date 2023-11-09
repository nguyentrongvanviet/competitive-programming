#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "C2XOR"
int n;
map<int,int >mp,tt;
map<int,int> :: iterator it;
int a[100005],Xorr[100005];
int tmp[100005],dem = 0;


vector<int > v[100005];
void doc(){
	cin>>n;	
	for(int i=1;i<=n;i++) cin>>a[i];
	Xorr[0] = 0;
	Xorr[1] = a[1];
	for(int i=2;i<=n;i++) Xorr[i] = Xorr[i-1]^a[i];
	for(int i=0;i<=n;i++) mp[Xorr[i]]++; 
	for(it=mp.begin();it!=mp.end();it++){
		int f = it->first,s = it->second;
		// cout<<f<<" "<<s<<endl;
		if(s<=1) mp[f] = 0;
	}
	for(it=mp.begin();it!=mp.end();it++){
		int f = it->first,s = it->second;
		if(s>1) tt[f] = ++dem;
	}
	for(int i=0;i<=n;i++){
		if(mp[Xorr[i]]>1) v[tt[Xorr[i]]].push_back(i); 
	}
	ll res =0 ;
	for(int i=1;i<=dem;i++){
		// cout<<i<<endl;
		ll sum = *v[i].rbegin()-*v[i].begin()+1-v[i].size();
		res+=sum*(v[i].size()-1);
		// cout<<endl; 
	}
	cout<<res;
}

int main(){
	freopen(TASK".INP","r",stdin);
    freopen(TASK".ANS","w",stdout);	
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// int test;
	// cin>>test;
	// while(test--)
	doc();
}