postfix=input()


def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        return False      

stack=[]

postfix=postfix.split()
emptystack=0
for i in postfix:

  if (is_number(i)):
             stack.append(i)
             
  if (i in ['+','-','*','/','^']):
      if(len(stack)==0):
            emptystack=1
            break
      operand2=stack.pop()
      if(len(stack)==0):
            emptystack=1
            break
      operand1=stack.pop()
      stack.append("("+operand1+i+operand2+")")

  if (i in ["tan"]):         
       operand=stack.pop()
       stack.append("("+"tan("+operand+"))")
       
if(emptystack==0):
   print(stack[0])
else:
   print("NO")
