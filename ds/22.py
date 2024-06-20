# MergeSort in Python


def mergeSort(array):
    if len(array) > 1:

        #  r is the point where the array is divided into two subarrays
        r = len(array)//2
        L = array[:r]
        M = array[r:]

        # Sort the two halves
        mergeSort(L)
        mergeSort(M)

        i = j = k = 0

        # Until we reach either end of either L or M, pick larger among
        # elements L and M and place them in the correct position at A[p..r]
        while i < len(L) and j < len(M):
            if L[i] < M[j]:
                array[k] = L[i]
                i += 1
            else:
                array[k] = M[j]
                j += 1
            k += 1

        # When we run out of elements in either L or M,
        # pick up the remaining elements and put in A[p..r]
        while i < len(L):
            array[k] = L[i]
            i += 1
            k += 1

        while j < len(M):
            array[k] = M[j]
            j += 1
            k += 1


n , q = input().strip().split(" ")
n = int(n)
q = int(q)

arr1 = input().strip().split(" ")
for i in range(len(arr1)):
   arr1[i] = int(arr1[i])

arr2 = input().strip().split(" ")

requests = []
for i in range(q):
    requests.append(int(input()))


mergeSort(arr1)

for i in requests:
  sum = 0
  for j in range(n-1,n-i-1,-1):
        #print(result[j])
        sum += arr1[j]
  print(sum)