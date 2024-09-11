int st[4*N];
void build(int id, int l, int r)
{
	if(l==r)
	{
	    st[id] = a[l] ;
	    return ; 
	} 
	int mid=(l+r)>>1; 
	build(id<<1,l,mid); 
	build(id<<1|1,mid+1,r) ; 
	st[id] = min(st[id<<1],st[id<<1|1]) ; 
}
void up(int id, int l ,int r ,int  pos , int val)
{
    if(l==r&&l==pos)
    {
	    st[id] = val; 
	    return ; 
    }    
    if(r<pos||pos<l)return ; 
    int mid = (l+r)>>1 ;
    up(id<<1,l,mid,pos,val) ; 
    up(id<<1|1,mid+1,r,pos,val);
    st[id] = min(st[id<<1],st[id<<1|1]) ;  
}
int get(int id, int l, int r ,int t, int p)
{
    if(t<=l&&r<=p)return st[id] ;
    if(r<t||p<l)return oo ; 
    int mid = (l+r)>>1 ;
    return min(get(id<<1,l,mid,t,p),get(id<<1+1,mid+1,r,t,p)) ;
} 
 