struct modint
{
	int val; 
	modint operator+(modint a)
	{
		val+=a; 
		if(val>=sm)a-=sm ; 
	}
	modint operator+=(modint a)
	{
		this->val+=a;  
		if(val>=sm)a-=sm; 
	}
}