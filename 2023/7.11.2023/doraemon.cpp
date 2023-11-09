int st[4*N];
void build(int id, int l, int r)
{
	if(l==r)
	{
	    st[id] = a[l] ;
	    return ; 
	} 
	int mid=(l+r)/2; 
	build(id*2,l,mid); 
	build(id*2+1,mid+1,r) ; 
	st[id] = min(st[id*2],st[id*2+1]) ; 
}
void up(int id, int l ,int r ,int  pos , int val)
{
    if(l==r&&l==pos)
    {
	    st[id] = val; 
	    return ; 
    }    
    if(r<pos||pos<l)return ; 
    int mid = (l+r)/2 ;
    up(id*2,l,mid,pos,val) ; 
    up(id*2+1,mid+1,r,pos,val);
    st[id] = min(st[id*2],st[id*2+1]) ;  
}
int get(int id, int l, int r ,int t, int p)
{
    if(t<=l&&r<=p)return st[id] ;
    if(r<t||p<l)return oo ; 
    int mid = (l+r)/2 ;
    return min(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ;
} 
 