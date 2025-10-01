# C(n-1,n+5-1)*C(n-1,n+3-1);
def C(k , n) : 
	if k > n : return 0 
	res = 1 
	for i in range(n-k+1,n+1) : 
		res*=i 
	for i in range(k+1) : 
		res/=i
	return res 
n = int(input())
print(C(n-1,n+5-1)*C(n-1,n+3-1))
# print(1) 
