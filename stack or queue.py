stack=[]
queue=[]


num=input()



for i in range (0,int(num)):
           currentin=input()
           if(currentin.split()[0]=="PUSH"):
                      stack.append(currentin.split()[1])
                      queue.append(currentin.split()[1])
           if (currentin=="POP"):
                      stack.pop()
                      queue.pop(0)


top=input()

flag=0
if(queue[0]!=stack[-1]):
   if(queue[0]==top):
           print("QUEUE")
           flag=1
           
   if(stack[-1]==top):
           print("STACK")
           flag=1
   
if(queue[0]==stack[-1] and queue[0]==top or flag==0 ):
           print("UNKNOWN")
           
