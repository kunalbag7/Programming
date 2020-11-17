# A Dynamic Programming based Python 
# Program for 0-1 Knapsack problem 
# Returns the maximum value that can 
# be put in a knapsack of capacity W 

val = [11, 21, 31, 33] 
wt = [2, 11, 22, 15] 
W = 40
n = len(val)
K = [[0 for x in range(W + 1)] for x in range(n + 1)] 

def knapSack(W, wt, val, n,K): 

	# Build table K[][] in bottom up manner 
	for i in range(n + 1): 
		for w in range(W + 1): 
			if i == 0 or w == 0: 
				K[i][w] = 0
			elif wt[i-1] <= w: 
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]) 
			else: 
				K[i][w] = K[i-1][w] 


# Driver program to test above function 
 
knapSack(W, wt, val, n,K) 
for i in range(n+1):
    for j in range(W+1):
        print(K[i][j])

    # print()

# This code is contributed by Bhavya Jain 
