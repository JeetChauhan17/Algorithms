import math
n = int(input("Enter the number of terms : "))
sum_series = 0

for i in range(1,n+1):
    term = i/math.factorial(i)
    
    if i%2 == 0:
        sum_series -= term
    else:
        sum_series += term
    
print(f"Sum series for {n} terms is : {sum_series:.4f}")
