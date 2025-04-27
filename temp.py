# def f_to_c(f):
#     c = (f-32)* 5/9    
#     return c

# def c_to_f(c):
#     f = (c*9/5) + 32
#     return f

# print("Temprature Converter : ")
# print("Choose your choice : ")
# print("1) Convert Farenhiet to Celsius : ")
# print("2) Convert Celsius to Farenhiet : ")

# ch = int(input("Your choice : "))

# if ch == 1:
#     f = float(input("Enter the temperature in farenheit : "))
#     print("The Temperature in Celsius is : ", f_to_c(f))
# elif ch == 2:
#     c = float(input("Enter the temperature in celsius : "))
#     print("The Temperature in Farenhiet is : ",c_to_f(c))
# else:
#     print("Invalid input. Enter only 1 and 2")
#     exit()

def ctf(c):
    return (c * 9/5) + 32
def ftc(f):
    return (f-32) * 5/9

print("Temprature Converter : ")
print("Choose your choice : ")
print("1) Convert Farenhiet to Celsius : ")
print("2) Convert Celsius to Farenhiet : ")

ch = int(input("Enter your choice : "))

if ch == 1 :
    f = float(input("Enter the temperature in farenhiet : "))
    print("Your temperature in celsius : ", ftc(f))
elif ch == 2 :
    c = float(input("Enter the temperature in celsius : "))
    print("Your temperature in farenhiet : ", ctf(c))
else:
    print("Invalid input.")
    exit()
