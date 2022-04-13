# 
# Logic:
# Since the all the values of the friend array is a value that is subtracted from a constant value
# which is the last value of the main array. We only need to check if the main array is in ascending order
# or not. If it is in ascending order then its friend array will be in descending order.
# 
# Time complexity = O(n)
# 

n = int(input())
arr = list(map(int, input().split()))
isSorted = True
for idx in range(1, len(arr)):
	if arr[idx - 1] > arr[idx]:
		isSorted = False;
		break;

if(isSorted):
	print("Yes");
else:
	print("No");
