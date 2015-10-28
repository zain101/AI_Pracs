from os import sys, path
flag = 0
g = []


def decesion_tree(t):
    global g
    if t is None:
        return None
    decesion_tree(t.left)
    try:
        decesion_tree(t.center)
    except:
        print "No center"
    decesion_tree(t.right)
    # print t.data, t.operation
    if t.data is None:
        g.append(t.left.data)
        g.append(t.right.data)
        if t.center:
            g.append(t.center.data)
        if None in g:
            g.remove(None)
        if t.operation == "max":
            t.data = max(g)
        else:
            t.data = min(g)
        g = []


def print_tree(t):
    if t is None:
        return None
    print_tree(t.left)
    try:
        print_tree(t.center)
    except:
        print "No center"
    print_tree(t.right)
    print t.data,


def create_tree():
    global flag
    l = input("Enter the depth of tree: ")
    size = input("Enter the size of leaf nodes: ")
    leaf = []
    for i in range(size):
        leaf.append(Trees(input("value is: ")))
    leaf = leaf[::-1]
    print ""
    tmp = []
    for i in range(l):
        if size % 2 == 0:
            while(True):
                if len(leaf) == 0:
                    break
                tree = Trees()
                tree.left = leaf.pop()
                tree.right = leaf.pop()
                if flag == 1:
                    tree.operation = "max"
                else:
                    tree.operation = "min"
                tmp.append(tree)
        else:
            while(True):
                if len(leaf) == 0:
                    break
                tree = Trees()
                tree.left = leaf.pop()
                tree.center = leaf.pop()
                tree.right = leaf.pop()
                if flag == 1:
                    tree.operation = "max"
                else:
                    tree.operation = "min"
                tmp.append(tree)
        if flag == 1:
            flag = 0
        else:
            flag = 1
        size = len(tmp)
        if size == 1:
            break
        leaf = list(tmp[::-1])
        tmp = []
    root = tmp.pop()
    decesion_tree(root)
    print "\nDecesion Tree is {In post-order traversal form}:",
    print_tree(root)


if __name__ == "__main__" and __package__ is None:
    print path.dirname(path.dirname(path.abspath(__file__)))
    sys.path.append(path.dirname(path.dirname(path.abspath(__file__))))
    from lib.trees import Trees
    create_tree()
