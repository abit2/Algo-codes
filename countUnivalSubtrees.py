def countUnivalSubtrees(root):
    print '------'
    print root.n
    if root.left:
        print root.left.n
    if root.right:
        print root.right.n
    if not root.left and not root.right:
        return 1
    elif root.left and not root.right and root.v!=root.left.v:
        return 0
    elif not root.left and root.right and root.v!=root.right.v:
        return 0
    elif root.left and root.right and not root.left.left and not root.left.right and not root.right.left and not root.right.right\
        and all(root.v==x.v for x in [root.left, root.right]):
        return 1 + countUnivalSubtrees(root.left) + countUnivalSubtrees(root.right)
    else:
        return countUnivalSubtrees(root.left) + countUnivalSubtrees(root.right)

class Node():
    def __init__(self, name, val=0, left=None, right=None):
        self.n = name
        self.v = val
        self.left = left
        self.right = right

r = Node('r', 0)
a = Node('a', 1)
b = Node('b', 0)
c = Node('c', 1)
d = Node('d', 0)
e = Node('e', 1)
f = Node('f', 1)
r.left = a
r.right = b
b.left = c
b.right = d
c.left = e
c.right = f

print countUnivalSubtrees(r)
