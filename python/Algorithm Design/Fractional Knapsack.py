pri = []
wei = []
n = int(input("Enter number of element: "))
for i in range(0, n):
    m = int(input("Enter the value of " + str(i + 1) + "th element: "))
    pri.append(m)
    k = int(input("Enter the weight of " + str(i + 1) + "th element: "))
    wei.append(k)

total = int(input("Enter total weight of Knapsack: "))
frac_pri = []
for i in range(n):
    frac_pri.append(pri[i] / wei[i])

val = -1
tot_pri=0

while val<n and total>0:
	i = frac_pri.index(max(frac_pri))
	if total-wei[i] >=0:
		total=total-wei[i]
		tot_pri=tot_pri+pri[i]
		frac_pri[i]=0
		print(str(i+1)+"th element was taken")
	val=val+1

if total>0:
	i = frac_pri.index(max(frac_pri))
	print(str(total)+" amount of "+str(i+1)+"th element were taken")
	tot_pri=tot_pri+ total*frac_pri[i]

print("The total value is: "+str(tot_pri))
