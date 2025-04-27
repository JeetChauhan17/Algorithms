print("Enter the marks for three subjects : ")
m1 = float(input("Enter the marks for 1st subject : "))
m2 = float(input("Enter the marks for 2nd subject : "))
m3 = float(input("Enter the marks for 3rd subject : "))

total = m1+m2+m3
percent = total/3

if percent >=80 :
    print("You recieved Grade : A")
    
elif percent >=70 and percent < 80:
    print("You recieved Grade : B")

elif percent >=60 and percent < 70:
    print("You recieved Grade : C")

elif percent >=40 and percent < 60:
    print("You recieved Grade : D")

elif percent < 40:
    print("You recieved Grade : E")
else:
    print("Invalid input")

print("Total marks : ", total)
print("Percentage % : ", percent)