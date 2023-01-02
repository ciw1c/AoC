# llegir de text
s1 = 
s2 = 
s3 = 

inter = ""
for i in s1:
    if i in s2 and i in s3 and not i in inter:
        inter += i
total = 0
for s in inter:
    if i >= 'a' and i <= 'z':
        total += s - 'a' + 1
    else:
        total += s - 'A' + 27