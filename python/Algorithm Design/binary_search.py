
import numpy as np

def binary_Search_ite(array, x):
	(left, right) = (0, len(array) - 1)

	while left <= right:

		mid = (left + right) // 2

		if x == array[mid]:
			return mid

		elif x < array[mid]:
			right = mid - 1

		else:
			left = mid + 1

	return -1

def binary_Search_rec (arr, l, r, x): 
    if r >= l: 
  
        mid = l + (r - l) // 2 
        if arr[mid] == x: 
            return mid 
        
        elif arr[mid] > x: 
            return binary_Search_rec(arr, l, mid-1, x) 
        else: 
            return binary_Search_rec(arr, mid + 1, r, x) 
  
    else: 
        return -1


array = np.array([ 2, 3, 4, 10, 40, 52, -7, 31, 8, 20, 41, 36, 8, 7, 0 ]) 
key = 7
array.sort()

print("Original Array: ", array)

i = binary_Search_ite(array, key)
j = binary_Search_rec(array,0,len(array)-1, key)

print("Iterative Way: ")
if i != -1:
    print(str(key)+" found at index", i)
else:
    print(str(key)+" found not in the list")

print("Recursive Way: ")
if j != -1:
    print(str(key)+" found at index", j)
else:
    print(str(key)+" found not in the list")
