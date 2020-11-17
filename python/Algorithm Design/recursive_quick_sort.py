def partition(arr, start, end):

    pos=start

    for i in range(start,end):
        if arr[i] < arr[end]:
            arr[i],arr[pos]=arr[pos],arr[i]
            pos+=1


    arr[pos],arr[end]=arr[end],arr[pos]

    return pos

def quick_sort(arr, start, end):

    if start<end :
        pivot=partition(arr, start, end)
        quick_sort(arr, start, pivot-1)
        quick_sort(arr, pivot+1, end)



arr =  [45,62,0,11,23,-7,9,55,2,34,98,-5,-10,49,77,-8,0,3,6,5,2,4,8,12,-7,4]
print("Original Array: ",arr)
quick_sort(arr,0,len(arr)-1)
print("Sorted Array: ",arr)