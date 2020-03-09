N=input()
array=input()

numbers=array.split()

for i in range (0,len(numbers)): 
  numbers[i]=int(numbers[i])
  
numbers=sorted(numbers)

count =0
maxcount=0
maxnum=0

for i in range(1,len(numbers)):
  if (numbers[i]==numbers[i-1]):
    count=count+1
  else:
    count=0
       
  if(count>maxcount):
     maxnum=int(numbers[i])
     maxcount=count

  if (count==maxcount):  
     if (int(numbers[i])>maxnum):
       maxnum=int(numbers[i])
       maxcount=count


if (int(N)==1):
  print (array)
else:
 print(maxnum)
  




  
  

