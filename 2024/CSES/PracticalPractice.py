from scipy import integrate
import numpy as np
import matplotlib.pyplot as plt
pwf = 2800 
rw = 0.3 
k = 65 
h = 15 
T = 600 
pr = 4400 
re = 1000 
Z = 0.775 

def m(p, mu=1.0, Z=1.0):
    """Analytical solution: m(p) = p²/(μZ)"""
    return p**2 / (mu * Z)
qg = k*h*(m(pr,mu=0.2831,Z=0.896)-m(pwf,mu=0.02170,Z=0.775))/(1424*T*(np.log(0.472*re/rw))) 
print(qg) 

p_psig = np.array([0.0, 400.0, 800.0, 1200.0, 1600.0, 2000.0, 2400.0, 2800.0, 3200.0, 3600.0, 4000.0, 4400.0])
mu_cp = np.array([0.01270, 0.01286, 0.01390, 0.01530, 0.01680, 0.01840, 0.02010, 0.02170, 0.02340, 0.02500, 0.02660, 0.02831])
Z = np.array([1.000, 0.937, 0.882, 0.832, 0.794, 0.770, 0.763, 0.775, 0.797, 0.827, 0.860, 0.896])



m_p = m(p_psig, mu=mu_cp, Z=Z)

# Create the plot with only p and m(p)
plt.figure(figsize=(10, 6))
plt.plot(p_psig, m_p, 'bo-', linewidth=2, markersize=6)
plt.xlabel('p (psig)')
plt.ylabel('m(p)')
plt.grid(True, alpha=0.3)
plt.show()