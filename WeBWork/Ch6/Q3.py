import math

p = 1613
g = 9
r = 860

e = 1

#plug in values for e until g^(e%p) == r
for e in range(1, p):
  ge = pow(g, e)
  
  if((ge%p) == r):
    print(e)

# r = g^e mod p
