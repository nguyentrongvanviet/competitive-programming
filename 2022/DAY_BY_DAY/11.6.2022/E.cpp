#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;
 
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	vector<int> a(1);
	int sum=0;
	for(int i=0;i<n;i++){
		if(s[i]=='(')sum++;
		else sum--;
		a.push_back(sum);
	}
	sort(a.begin(),a.end());
	int res=0,ns=0;
	for(int i=0;i<=n;i++){
   		res+=i*a[i]-ns;
		ns+=a[i];
	}
	for(int i=1;i<=n;i++)
		res+=i*(n-i+1);
	res/=2; 
	stack<int> sss;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			sss.push(i);
		}else{
			if(sss.empty())continue;
			res-=(sss.top()+1)*(n-i);
			sss.pop(); 
		}
	}
	cout<<res<<endl;
}
 
main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}