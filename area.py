import math 

def a_rec(l,b):
    return l*b

def a_cir(r):
    return math.pi*r*r

def a_sqr(s):
    return s*s

def a_tri(b,h):
    return 0.5*b*h

print("Calculate area of shapes :")
print("1) rectangle :")
print("2) circle :")
print("3) square :")
print("4) triangle :")

ch = int(input("Enter your choice : "))

if ch == 1:
    l = float(input("Enter the length of rectangle : "))
    b = float(input("Enter the breadth of rectangle : "))
    print("Area of rectangle : ", a_rec(l,b))
elif ch == 2:
    r = float(input("Enter the radius of the circle : "))
    print("Area of circle : ", a_cir(r))
elif ch == 3:
    s = float(input("Enter the side of the square : "))
    print("Area of square : ", a_sqr(s))
elif ch == 4:
    b = float(input("Enter the base of the triangle : "))
    h = float(input("Enter the height of the triangle : "))
    print("Area of triangle : ", a_tri(b,h))
else:
    print("invalid input.")