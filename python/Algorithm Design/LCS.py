import numpy as np

str1=[]
str2=[]
str1=input("Enter 1st String: ")
str2=input("Enter 2nd String: ")

l1=len(str1)
l2=len(str2)
lcs = np.zeros((l1+1, l2+1))

# print(lcs[7][5])
# for i in range(1, len(str1) + 1):
#     for j in range(1, len(str2) + 1):
#         print(str(i)+str(j))

for i in range(1, l1 + 1):
    for j in range(1, l2 + 1):
        if(str1[i-1]==str2[j-1]):
            lcs[i][j]=1+lcs[i-1][j-1]
        else:
            lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1])

print("Length of Longest Commom SubSeq: "+str(int(lcs[l1][l2])))
result=""
temp=lcs[l1][l2]
while(temp != 0):
    if(temp==lcs[l1-1][l2]):
        l1=l1-1
    elif(temp==lcs[l1][l2-1]):
        l2=l2-1
    else:
        result=result+str1[l1-1]
        l1=l1-1
        l2=l2-1

    temp=lcs[l1][l2]

result=result[::-1]
print("The Longest Common SubSeq is: "+result)
        

