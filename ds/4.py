from typing import List

class Item:
	def __init__(self, val: int, index: int):
		self.val = val
		self.index = index

def count_large(a: List[int]) -> List[int]:
	# Length of the array
	length = len(a)

	# Stores the index-value pairs
	items = [Item(a[i], i) for i in range(length)]

	# Stores the count of greater elements on right
	count = [0] * length

	# Perform MergeSort operation
	merge_sort(items, 0, length - 1, count)

	res = count.copy()

	return res

def merge_sort(items: List[Item], low: int, high: int, count: List[int]) -> None:
	# Base Case
	if low >= high:
		return

	# Find Mid
	mid = low + (high - low) // 2

	merge_sort(items, low, mid, count)
	merge_sort(items, mid + 1, high, count)

	# Merging step
	merge(items, low, mid, mid + 1, high, count)

def merge(items: List[Item], low: int, low_end: int, high: int, high_end: int, count: List[int]) -> None:
	m = high_end - low + 1 # mid

	sorted_items = [None] * m

	right_counter = 0
	low_ind = low
	high_ind = high
	index = 0

	# Loop to store the count of larger elements on right side
	# when both array have elements
	while low_ind <= low_end and high_ind <= high_end:
		if items[low_ind].val < items[high_ind].val:
			right_counter += 1
			sorted_items[index] = items[high_ind]
			index += 1
			high_ind += 1
		else:
			count[items[low_ind].index] += right_counter
			sorted_items[index] = items[low_ind]
			index += 1
			low_ind += 1

	# Loop to store the count of larger elements in right side
	# when only left array have elements
	while low_ind <= low_end:
		count[items[low_ind].index] += right_counter
		sorted_items[index] = items[low_ind]
		index += 1
		low_ind += 1

	# Loop to store the count of larger elements in right side
	# when only right array have elements
	while high_ind <= high_end:
		sorted_items[index] = items[high_ind]
		index += 1
		high_ind += 1

	items[low:low + m] = sorted_items


if __name__ == '__main__':
	n = int(input())

	requests = []
	for i in range(n):
		requests.append(int(input()))

	finaly = []
	for i in range(len(requests)-1 , -1 , -1):
		finaly.append(requests[i])


	count_list = count_large(finaly)
	sum = 0
	for i in count_list:
		sum += i
	print(sum%100000)
