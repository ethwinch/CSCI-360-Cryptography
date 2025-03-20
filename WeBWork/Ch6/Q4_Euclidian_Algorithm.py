# Euclidian Algorithm for GCD
a = 826482848
b = 125641089

r = 1

if(a>b):
  while(r != 0):
    r = a%b
    
    a = b
    print(b)
    b = r
else:
  print("ERROR: a is NOT greater than b.")
