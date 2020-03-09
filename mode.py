N=input()
array=input()

numbers=array.split()
for i in range (0,len(numbers)):
  numbers[i]=int(numbers[i])
  
numbers=sorted(numbers)

norepetition=list()
toprepeated=list()
countermap=dict()
count =0
maxcount=0
maplength=0

for i in range (0,len(numbers)):
  if(numbers[i] not in norepetition):
    norepetition.append(numbers[i])

for i in range(0,len(norepetition)):
  count= 0
  for x in range(0,len(numbers)):
    if ( norepetition[i]==numbers[x]):
      count=count+1
      
  if(count>=maxcount):
    maxcount=count
    countermap[norepetition[i]]=count
    toprepeated.append(norepetition[i])
    maplength=maplength+1


print(toprepeated[maplength-1])
  




  
  

