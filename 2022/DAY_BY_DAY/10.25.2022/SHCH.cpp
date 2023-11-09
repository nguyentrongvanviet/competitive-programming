#include<bits/stdc++.h>
#define fi "CH.INP"
#define fo "CH.OUT"
#define ll long long
#define pb push_back
#define FOR( i , a , b ) for( int i = a ; i <= b ; i ++ )
#define FORN( i , a , b ) for( int i = a ; i < b ; i ++ )
#define FORG( i , a , b ) for( int i = a ; i >= b ; i-- )
using namespace std;
const ll oo = 1e18;
const int N= 200+5;

int n , k , a[N] , dd[N];
string s , f[N];
string add(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int carry=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tmp=a[i]-48 + b[i]-48 + carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(carry>0) res="1"+res;
    return res;
}
string mul(string a , int b )
{
	string res="" ; 
	int nho = 0 ; 
	for(int  i= a.size()-1;ix>=0;i--)
	{
		int tmp = (a[i]-'0')*b+nho;
		int x = tmp%10 ; 
		nho = tmp/10 ; 
		res=(char)(x+'0')+res;
	}
	if(nho>0)
	{
		res=(char)(nho+'0')+res;
	}
	return res ;
}
string nhan(string a , string b)
{
	string res="";
	string so="";
	for(int i= b.size()-1 ; i>=0;i--)
	{
		string tmp= mul(a,b[i]-'0');
		tmp +=so;
		res=add(res,tmp);
		so+='0';
	}
	return res;
}
string sub(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    bool neg=false;
    if(a<b)
    {
        swap(a,b);
        neg=true;
    }
    int borrow=0;
    for(int i=a.length()-1; i>=0;i--)
    {
        int tmp=a[i]-b[i]-borrow;
        if(tmp<0)
        {
            tmp+=10;
            borrow=1;
        }
        else borrow=0;
        res=(char)(tmp%10 + 48) + res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    if(neg) res="-"+res;
    return res;
}
int sosanh( string a, string b )
{
	if ( a.size() < b.size() ) return 1;
	if ( a.size() > b.size() ) return 0;
	return a < b;
}
void doc(){
	cin >> n >> k;
	cin >> s;
	FOR ( i , 1 , k ) cin >> a[i];
}
void xuly()
{
	f[0] = "1";
	FOR ( i , 1 , n )
	{
		int x = n - k + i;
		string st ="";
		while ( x > 0 )
		{
			int y = x % 10;
			st = char( '0' + y ) + st;
			x = x / 10;
		}
		f[i] = nhan( f[ i - 1 ] , st );
	}
	FOR ( i , 1 , k )
	{
		FOR( j , 1 , n )
		{
			if ( dd[j] == 0 )
			{
				if ( sosanh( f[ k - i ] , s ) )
				{
					s = sub ( s , f[ k - i ] );
				}
				else
				{
					cout<< j <<" ";
					dd[j] = 1;
					break;
				}
			}
		}
	}
	cout<<endl;
	FOR( i , 1 , n ) dd[i] = 0;
	string res = "0" ;
	FOR( i , 1 , k )
	{
		int cnt = 0 ;
		FOR ( j , 1 , a[i] - 1 ) if ( dd[j] == 0 ) cnt ++;
		int x = cnt;
		string st ="";
		while ( x > 0 )
		{
			int y = x % 10;
			st = char( '0' + y ) + st;
			x = x / 10;
		}
		res = add ( res ,nhan( st , f[ k - i ] ) );
		dd[ a[i] ] = 1;
	}
	res = add( res , "1" );
	cout<< res <<'\n';
}
int main()
{
	freopen( fi, "r" , stdin );
	freopen( fo, "w" , stdout );

	ios_base:: sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int t;
	// cin>>t;
	t = 1;
	while(t--)
	{
		doc();
		xuly();
	}

	return 0;
}