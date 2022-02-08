
#import a module to remove all special characters
import re

#open a file to read from
file_object = open("in4.txt","r")

#save whole file to a list
file_content=file_object.read()


file_content =file_content.split(" ")

#define special characters
special = "@_!#$%^&*()<>,.?/|\|{}~`:;[]-\n`"

#apply a filter to remove
clean_list = [''.join(filter(lambda i:i not in special,string))for string in file_content]

pal1 = "".join(clean_list)#turn into a string

pal1 = pal1.lower() #make sure it isn't case sensitive

pal2 = pal1[::-1]

if pal1==pal2:
    print("Yes")
else:
    print("No")
