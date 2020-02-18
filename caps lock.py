word = input()
flag1=0
flag=0
wordformated=''

if (word[0].islower()):       
  for i in range (1,len(word)):
     if(word[i].isupper()):
           flag1 =1
     if (word[i].islower()):
              flag1=0
              break

         
if (flag1==1):
    wordformated += word[0].upper()
    for j in range (1,len(word)):
                wordformated += word[j].lower()
                
if(len(word)==1):
    if (word[0].islower()):       
       wordformated += word[0].upper()
    if (word[0].isupper()):       
       wordformated += word[0].lower()

for i in range (0,len(word)):        
   if (word[i].isupper() and len(word)>1):
        flag=1
   if (word[i].islower() and len(word)>1):
        flag=0
        break


if (flag==1):         
   for j in range (0,len(word)):
        wordformated += word[j].lower()
           
               
if (wordformated):
 print (wordformated)
else:
 print(word)
