import math
import numpy as np

# def mom(arr, i):

#     sub = [arr[j:j+5] for j in range(0, len(arr), 5)]
#     m_array = [sorted(sub)[len(sub)//2] for sub in sub]
#     if len(m_array) <= 5:
#         print(len(m_array))
#         m = sorted(m_array)[len(m_array)//2]
#     else:
#         m = mom(m_array, len(m_array)//2)

#     left = [j for j in arr if j < m]
#     right = [j for j in arr if j > m]
#     k = len(left)
#     if i < k:
#         return mom(left,i)
#     elif i > k:
#         return mom(right,i-k-1)
#     else:
#         return m

def median_finding(arr,k):
    if(len(arr)<6):
        arr.sort()
        # print(arr[k])
        return arr[len(arr)//2]
    
    median_arr=[]
    temp_arr=[]
    for i in range(len(arr)):
        temp_arr.append(arr[i])

        if(len(temp_arr)==5):
            median_arr.append(median_finding(temp_arr,2))
            temp_arr.clear()

    if(len(temp_arr)!=0):
        median_arr.append(median_finding(temp_arr,len(temp_arr)//2))
        temp_arr.clear()

    pivot = median_finding(median_arr,len(median_arr)//2)

    # print(pivot)

    # return pivot

    s1=[]
    s2=[]
    s3=[]

    # print(arr)
    for i in range(len(arr)):
        if arr[i] < pivot:
            s1.append(arr[i])

        elif arr[i] > pivot:
            s2.append(arr[i])

        else:
            s3.append(arr[i])


    if len(s1) > k:
        return median_finding(s1,k)
    elif len(s1) < k:
        return median_finding(s2,k-1-len(s1)-len(s3))

    else:
        return pivot

arr=[4,8,2,3,1,5,4,7,4,7,9,8,1,3,3,2,4,1,4,10,5,1,4,3,6,6,6,9,10,4,10,6,7,9,8,4,50,58,66,14,20,54]
n=len(arr)
print(n)
print("By Divide & Conquer Algo: ",median_finding(arr,n//2))
arr.sort()
# print(arr)
print("By Normal: ",arr[n//2])


# 4,8,2,3,1,5,4,7,4,7,9,8,1,3,3,2,4,1,4,10,5,1,4,3,6,6,6,9,10,4,10,6,7,9,8