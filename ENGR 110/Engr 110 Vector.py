#5:44 -  1403 feet
#6:12 - 1580
#6:23 - 1524
#2:47 - 690
#2:12 - 594
#23:31 - 5791
#246 ft per minute
#4.07 ft per second

#This version of types everything out explictictly, and doesn't use functions
#as using function actually lengthens the code.
#Under regular design hilosphy, there is no need for a function as no 2 operations
#are repeated.
import math
response = input("""Input vector in following format:
X Y Z where X is 1 or 2 (Cartesian or Polar Respectively)
Y is x coordinate or radius
Z is y or angle (in degrees)\n""")
Finished = False
resultX = 0
resultY = 0

while(Finished == False):
    parse = response.split(" ")
    if (response == "end"):
        Finished = True
        continue
    elif (len(parse) != 3):
        print("Please enter a valid input")
    else:
        if(parse[0] == "1" ):
            #If we are getting cartesian
            resultX += float(parse[1])
            resultY += float(parse[2])
        elif(parse[0] == "2"):
            #If we are getting polar coordinates.
            resultX += float(parse[1])*math.cos(float(parse[2])/ 360 * 2 *math.pi )
            resultY += float(parse[1])*math.sin(float(parse[2])/ 360 * 2 *math.pi )
        else:
             print("Please enter a valid input")
    response = input("Input another vector (or \"end\"): \n")
    
Going = True
response = input("Do you want your result in cartesian (1) or polar (2) \n")
while(Going):
    if (response == "1"):
        #Cartesian
        Going = False
        print("Resultant: X:{:.3f}, Y:{:.3f}".format(resultX, resultY))
    elif(response == "2"):
        #Polar
        Going = False
        print("Resultant: R:{:.3f}, Angle:{:.3f} rad or {:.3f} degrees".format(math.sqrt(resultY**2 + resultX**2), math.atan(resultY/resultX), math.atan(resultY/resultX)/ 2 / math.pi * 360))
    else:
        print("Please try again")
        response = input("Do you want your result in polar (1) or cartesian (2) \n")
