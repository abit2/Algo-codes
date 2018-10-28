def maxNonAdjacentSum(a):
    if not a:
        return 0
    elif len(a)==1:
        return a[0]
    elif len(a)==2:
        return max(a[0], a[1])
    else:
        return max(a[0] + maxNonAdjacentSum(a[2:]), maxNonAdjacentSum(a[1:]))

print maxNonAdjacentSum([2,4,6,2,5])
print maxNonAdjacentSum([5,1,1,5])
