# code name: square.py
# code by: Davis Farrow

# CPE 420 HW8 problem 4 part c
# this code prints out the cube of the odd number from 0 to 19 and the 
# number themselves if they are even 

for i in range(20):
    if (i%2 == 0):
        print(i)
    else:
        print(i*i*i)
