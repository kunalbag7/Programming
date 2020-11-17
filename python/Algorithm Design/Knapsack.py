pri = [] 
wei = []
n=int(input("Enter number of element: "))
for i in range(0,n):
    m=int(input("Enter the value of "+str(i+1)+"th element: "))
    pri.append(m)
    k=int(input("Enter the weight of "+str(i+1)+"th element: "))
    wei.append(k)
 
total=int(input("Enter total weight of Knapsack: "))
 
cal_arr = [[-1 for i in range(total + 1)] for j in range(n + 1)]
  
def knapsack(wei, pri, W, n):

    if n == 0 or W == 0:
        return 0
    if cal_arr[n][W] != -1:
        return cal_arr[n][W]

    if wei[n-1] <= W: 
        cal_arr[n][W] = max( pri[n-1] + knapsack( wei, pri, W-wei[n-1], n-1), knapsack(wei, pri, W, n-1))
        return cal_arr[n][W]
    elif wei[n-1] > W: 
        cal_arr[n][W] = knapsack(wei, pri, W, n-1)
        return cal_arr[n][W]

    
  
ans=knapsack(wei, pri, total, n)
print("Maximum value: "+str(ans))

while ans>0 :
    flag=0
    for i in range(total+1):
        if cal_arr[n][i] == ans :
            flag=1
    
    if flag==0:
        if n+1 ==1:
            print("1st element is taken.")
        elif n+1==2:
            print("2nd element is taken.")
        elif n+1==3:
            print("3rd element is taken.")
        else:
            print(str(n+1)+"th element is taken.")

        
        ans=ans-pri[n]

    else:
        n=n-1
