text=[]
pattern=[]
text=input("Enter Text: ")
pattern=input("Enter Pattern: ")

len=len(pattern)

pattern_val=0
for i in range(len):
    pattern_val=pattern_val+(ord(pattern[i])-64) * pow(53,(len-i-1))

for i in range(len):
    