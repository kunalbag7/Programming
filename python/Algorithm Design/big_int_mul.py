import math

def GetIntegerSlice(i, n, m):
    # l = math.floor(math.log10(i)) + 1
    # return int(i / int(pow(10, l - m)) % int(pow(10, m - n + 1)))

    num = [int(x) for x in str(i)]
    temp=m-n
    k=0
    for j in range(n-1,m):
        k=k+num[j]*pow(10,temp)
        temp=temp-1

    return k
  
num1=1111
num2=1111

def bigIntMul(a,b):
    l1= int(math.log10(a))+1

    if(l1<3):
        return a*b

    # l2= int(math.log10(num2))+1
    a0=GetIntegerSlice(a,math.floor(l1/2)+1,l1)
    a1=GetIntegerSlice(a,1,math.floor(l1/2))

    b0=GetIntegerSlice(b,math.floor(l1/2)+1,l1)
    b1=GetIntegerSlice(b,1,math.floor(l1/2))

    c2=bigIntMul(a1,b1)
    c0=bigIntMul(a0,b0)
    # c1=bigIntMul(a1,b0)+bigIntMul(a0,b1)
    c1=bigIntMul(a1+a0,b1+b0)-c0-c2
    m=math.ceil(l1/2)
    c=c0+ c1*pow(10,m)+ c2*pow(10,(2*m))

    return c
print("Multiplication of",num1,"and",num2,':',bigIntMul(num1,num2))



