#include <bits/stdc++.h>
using namespace std;
const int N = 256*255;
vector<int> adj[N];
int d[N];
string ret;
void dfs(int x){
	int i,u;
	while(adj[x].size()){
		u= adj[x].back();
		adj[x].pop_back();
		dfs(u);
	}
	ret+=char(x%256);
	cout<<char(x%256)<<endl;
}
int main(){
    freopen("i.txt","r",stdin);
    freopen("o.txt","w",stdout);
    int n,i,pr,sf;string s;
	cin>>n;
	for(i=0;i<n;++i){
		cin>>s;
		pr= s[0]*256+ s[1];
		sf= s[1]*256+ s[2];
		cout<<char(pr%256)<<" " <<char(sf%256)<<endl;
		d[pr]++,d[sf]--;
		adj[pr].push_back(sf);
	}
	int st=0,cc=0;
	for(i=0;i<N;++i)
		if(d[i]>=1)st=i,++cc;
	if(d[st]>=2 || cc>=2){
		printf("NO\n");return 0;
	}
	if(st==0)
		for(i=0;i<N;++i)if(adj[i].size()>0){st=i;break;}
	dfs(st);
	reverse(ret.begin(),ret.end());
	ret= char(st/256)+ ret;
	if(ret.size()!=n+2)printf("NO\n");// AAA AAA AAA BBB BBB BBB  --> in this case, u can't make password
	else
		printf("YES\n"),cout<<ret<<endl;
}
