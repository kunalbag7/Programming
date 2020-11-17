def no_of_one(array):
    n= len(array)
    if(n==1 and array[0]==1):
            return 1

    count=0
    left=0
    right=0
    left_arr=[]
    right_arr=[]
    for i in range(0,(n//2)):
        left_arr[i]=array[i]
    for i in range((n//2)+1,n):
        right_arr[i]=array[i]
    left=left+no_of_one(left_arr)
    right=right+no_of_one(right_arr)
    count=left+right+count
    
    return count

array=[0,1,1,0,1,0,0,0,1,0,1]

print(no_of_one(array))