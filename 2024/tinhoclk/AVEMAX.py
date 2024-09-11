n = int(input())
a = []
for i in range(n) : 
    a.append(int(input()))
print(max(a))
# s = [0]*(n+1)  
# for i in range(n) :  
#     if i :
#         s[i] = s[i-1] 
#     s[i]+=a[i] 
# res = int(-1e9)  
# for i in range(n) : 
#     for j in range(i,n) :
#         if i : 
#             res = max(res,(s[j]-s[i-1])//(j-i+1))
#         else : 
#             res=max(res,s[j]//(j+1))
# print(res)  