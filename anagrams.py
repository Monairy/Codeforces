Sa=input()
Sb=input()
a=list(Sa)
b=list(Sb)

flag = 0

for i in range (0,len(a)):
    a[i]=a[i].lower()
a.sort()
                
for i in range (0,len(b)):
    b[i]=b[i].lower()
b.sort()


if(len(a)==len(b)):
 for i in range (0,len(a)):
    if (a[i]==b[i]):
       flag=1
    else:
       flag=0
       break

if(len(a)!=len(b)):
   flag=0

if (flag==1):
  print("yes")
  
if (flag==0):
  print("no")
