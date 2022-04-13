# 
# Logic
# Take in the array. Sort the array in descending order.
# Since array index starts from 0.
# Then kth number will be found from k-1 index.
# 
# Time complexity = O(n log n)
# 

n, k = list(map(int, input().split()))
arr = list(map(int, input().split()))
arr.sort(reverse=True)
print(arr[k-1])
