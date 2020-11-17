
def merge(arr, temp, frm, mid, to):

	k = frm
	i = frm
	j = mid + 1

	while i <= mid and j <= to:
		if arr[i] < arr[j]:
			temp[k] = arr[i]
			i = i + 1
		else:
			temp[k] = arr[j]
			j = j + 1

		k = k + 1

	while i < len(arr) and i <= mid:
		temp[k] = arr[i]
		k = k + 1
		i = i + 1

	for i in range(frm, to + 1):
		arr[i] = temp[i]


def merge_sort(arr):

	low = 0
	high = len(arr) - 1

	temp = arr.copy()

	m = 1
	while m <= high-low:

		for i in range(low, high, 2 * m):
			frm = i
			mid = i + m - 1
			to = min(i + 2 * m - 1, high)
			merge(arr, temp, frm, mid, to)

		m = 2 * m


arr =  [45,62,0,11,23,-7,9,55,2,34,98,-5,-10,49,77,-8,0,3,6,5,2,4,8,12,-7,4]
print("Original Array: ",arr)
merge_sort(arr)
print("Sorted Array :", arr)
