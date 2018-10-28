class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
def serialize(node):
    s, h2 = dfs(node, '', 0)
    return s

def dfs(node, s, h):
    s += node.val
    h2 = h
    if node.left:
        s += '<'
        s, h2 = dfs(node.left, s, h+1)
    if node.right:
        s += '>'*(h2-h)
        s, h2 = dfs(node.right, s, h+1)
    return s, h2

node = Node('root', Node('left', Node('left.left'), Node('left.right')), Node('right'))
s = serialize(node)
print s

def deserialize(s):
    nodes = []
    cur_val = ''
    c = -1
    flag = False
    for i in s:
        if i=='<':
            nodes.append([cur_val, c])
            c=-1
            cur_val = ''
        elif i=='>' and not flag:
            nodes.append([cur_val, c])
            flag = True
            cur_val = ''
            c=1
        elif i=='>' and flag:
            c+=1
        else:
            flag = False
            cur_val += i
    nodes.append([cur_val, c])
    
    root = Node(nodes[0][0])
    stack = [root]
    for node in nodes[1:]:
        if node[1]==-1:
            new_node = Node(node[0])
            stack[-1].left = new_node
            stack.append(new_node)
        else:
            for i in range(node[1]):
                stack.pop()
            new_node = Node(node[0])
            stack[-1].right = new_node
            stack.append(new_node)
    return root

assert deserialize(serialize(node)).left.left.val == 'left.left'
