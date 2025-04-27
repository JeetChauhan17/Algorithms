# n = int(input("Enter a number you want the factorial of : "))
# factorial = 1
# for i in range(1, n+1):
#     print(factorial, end=" * ")
#     factorial *= i
# print("factorial of the number is : ", factorial)

n = int(input("Enter the number you want to get factorial of : "))

fact = 1 

for i in range(1, n+1):
    fact *= i
print("factorial : ", fact)