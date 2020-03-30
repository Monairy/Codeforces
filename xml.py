lines=input()


stack=[]
lastclose=0
for i in range (0,int(lines)):
           line=input()

           if(len(line)>1):
              if (('<' in line) and (line[-1]=='>') and ('/' not in line) ):
                      start=line.find('<')+1
                      stack.append(line[start:-1])
                      lastclose=0
                      continue
                     

              if(('<' in line) and (line[-1]=='>') and ('/' in line)):
                 start=line.find('/')+1
                 if(len(stack)==0):
                            stack.append("unexpected closing tag")
                            continue
                 if(line[start:-1]==stack[-1]):
                    stack.pop()
                    lastclose=1
                    continue
                 else:
                    stack.append("unexpected closing tag")
                    continue
           if(len(stack)==0 or lastclose==1 ):
                  stack.append("string")    

           
if(len(stack)==0):
           print("YES")
           
if  (len(stack)>0):
           print("NO")

