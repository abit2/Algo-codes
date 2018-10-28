def countNoOfDecodings(a):
    if len(a) in [0, 1]:
        return 1
    elif a[0]==1 and a[1]!=0:
        return countNoOfDecodings(a[2:]) + countNoOfDecodings(a[1:])
    elif a[0]==1:
        return countNoOfDecodings(a[2:])
    elif a[0]==2 and a[1] not in [0, 7, 8, 9]:
        return countNoOfDecodings(a[2:]) + countNoOfDecodings(a[1:])
    elif a[0]==2:
        return countNoOfDecodings(a[2:])
    else:
        return countNoOfDecodings(a[1:])

print countNoOfDecodings([1,1,1])
print countNoOfDecodings([1,0,2,4])
print countNoOfDecodings([2,1,6])
