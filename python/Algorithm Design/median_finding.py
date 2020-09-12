import math

def median_finding(arr,k):
    if(len(arr)<6):
        arr.sort()
        mid=int(len(arr)/2)
        return arr[mid]

    median_arr=[]
    temp_arr=[]
    for i in range(len(arr)):
        temp_arr.append(arr[i])

        if(len(temp_arr)==5):
            median_arr.append(median_finding(temp_arr,0))
            temp_arr.clear()

    if(len(temp_arr)!=0):
        median_arr.append(median_finding(temp_arr,0))
        temp_arr.clear()

    pivot=median_finding(median_arr,int(len(median_arr)/2))

    # print(median_arr)

    # return pivot

    s1=[]
    s2=[]
    
    for i in range(len(arr)):
        if arr[i] < pivot:
            s1.append(arr[i])

        else:
            s2.append(arr[i])

    if len(s1)>=k:
        return median_finding(s1,k)

    else:
        return median_finding(s2,k-len(s1))

arr=[4,8,2,3,1,5,4,7,4,7,9,8,1,3,3,2,4,1,4,10,5,1,4,3,6,6,6,9,10,4,10,6,7,9,8]
n=len(arr)
print(n/2)
print(median_finding(arr,int(n/2)))

    