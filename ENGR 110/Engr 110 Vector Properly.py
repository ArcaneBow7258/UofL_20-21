#This version of the code includes functions to that Group 13 can indeed define
#and use functions in Python. The original variation of the code did not use
#functions since it was simply not need, as there was no two operations that
#were done twice. In normal programming philosphy, these functions are not necessary
import math
response = input("""Input vector in following format:
X Y Z where X is 1 or 2 (Cartesian or Polar Respectively)
Y is x coordinate or radius
Z is y or angle (in degrees)\n""")
Finished = False
resultX = 0
resultY = 0
#Functions
def PtC(radius, angle):
    #x, y
    return [float(radius)*math.cos(float(angle)/ 360 * 2 *math.pi), float(radius)*math.sin(float(angle)/ 360 * 2 *math.pi )]
def CtP(x, y):
    #radius, angle in rad, angle in degrees
    return [math.sqrt(y**2 + x**2), math.atan(y/x), math.atan(y/x)/ 2 / math.pi * 360]
    
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
            cords = PtC(parse[1], parse[2])
            resultX += cords[0]
            resultY += cords[1]
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
        cords = CtP(resultX, resultY)
        print("Resultant: R:{:.3f}, Angle:{:.3f} rad or {:.3f} degrees".format(cords[0], cords[1], cords[2]))
    else:
        print("Please try again")
        response = input("Do you want your result in polar (1) or cartesian (2) \n")
    
