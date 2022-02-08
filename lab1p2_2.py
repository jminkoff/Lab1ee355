#open a file to read from
file_object = open("in4.txt","r")

#save whole file to a list
file_content=file_object.read()


file_content = file_content.split(" ")

#define special characters
special = "@_!#$%^&*()<>,.?/|\|{}~`:;[]-\n`"

#apply a filter to remove
clean_list = [''.join(filter(lambda i:i not in special,string))for string in file_content]

pal1 = "".join(clean_list)#turn into a string

pal1 = pal1.lower() #make sure it isn't case sensitive

pal2 = pal1[::-1]

flag = 0

if pal1==pal2:
    print("Yes")
    flag=1
else:
    #itterate
    for i in range(len(pal1)):
        #use string splicing
        new = pal1[:i]+ pal1[i+1:]
        if new ==new[::-1]:
            flag=1
            print("Yes, delete",pal1[i],"at position",i+1)
            break
if flag==0:
    print("No")
