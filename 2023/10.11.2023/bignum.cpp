str cong(str a , str b )
{
	while(a.size()<b.size())a='0'+a; 
	while(b.size()<a.size())b='0'+b;
	string ans= "";  
	int nho  =0 ; 
	for(int i= b.size()-1;i>=0;i--)
	{
		int tmp = nho+ a[i]-'0'+b[i]-'0' ; 
		int c= tmp%10 ; V
		nho = tmp/10 ; 
		ans=(char)(c+'0')+ans; 
	}
	if(nho)ans='1'+ans;		 
	return ans; 
}
str tru(str a , str b)
{
	while(b.size()<a.size())b='0'+b;
	str ans="" ; 
	int thieu =0 ;
	FORD(i,b.size()-1,0)
	{
		int tmp = a[i]-b[i]-thieu ; 
		if(tmp<0)thieu = 1 , tmp+=10; 
		else thieu = 0 ;
		int c= tmp%10;
		ans=(char)(c+'0')+ans; 
	}
	while(ans.size()>1&&ans[0]=='0')ans.erase(0,1);
	return ans ; 
}
str mul(str a , int b)
{
	str ans="";
	int nho = 0 ;
	FORD(i,a.size()-1,0)
	{
		int tmp = (a[i]-'0')*b+nho ; 
		nho=tmp/10;  
		int c= tmp%10;
		ans=(char)(c+'0')+ans;  
	}
	if(nho)ans=(char)(nho+'0')+ans;
	return ans;  
}
str nhan(str a, str b)
{
	str ans=""; 
	str zero = "" ;
	FORD(i,b.size()-1,0)
	{
		str tmp = mul(a,b[i]-'0');
		tmp+=zero;  
		ans=cong(ans,tmp);
		zero+="0"; 
	}
	return ans; 
}