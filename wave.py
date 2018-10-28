def wave(a):
    a.sort()
    for i in range(0, len(a)-1, 2):
        if a[i] < a[i+1]:
            t = a[i+1]
            a[i+1] = a[i]
            a[i] = t
    for i in range(1, len(a)-1, 2):
        if a[i] > a[i+1]:
            t = a[i+1]
            a[i+1] = a[i]
            a[i] = t
    return a

print wave([1, 2, 3, 4])
print wave([])
print wave([1])
print wave([ 5, 1, 3, 2, 4 ])
