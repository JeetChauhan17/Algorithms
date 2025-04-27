# n = int(input("Enter the number of digits you want in fivonacci sequence : "))
# a,b = 0,1
# count = 0
# print("Fibonacci sequence : " )
# while count<n:
#     print(a, end=" ")
#     a,b = b, a+b
#     count += 1
    

n = int(input("Enter the number of digits you want the fibonacci sequence to goto : "))
a,b = 0,1
count = 0

while count<n:
    print(a, end=" ")
    a,b = b, a+b
    count += 1
    