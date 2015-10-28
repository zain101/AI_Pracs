flag = 1
a = set()


class Trees(object):

    def __init__(self, data=None):
        self.data = data
        self.left = None
        self.right = None
        self.center = None
        self.operation = None
        self.value = None
        self.alpha = None
        self.beta = None

    def __str__(self):
        for i in self.__dict__:
            print i, " = ", self.__dict__[i]
        return ""


def decesion_tree(t, predessor=None):
    global g, a
    if t is None:
        return None
    decesion_tree(t.left)
    if t.left is None and t.right is None and predessor is None:
        t.value = t.data
        a.add(t.value)
    elif t.left is None and t.right is None and predessor is not None:
        if predessor.operation == "max":
            if t.data > predessor.alpha:
                predessor.value = predessor.data = t.data
        else:
            if t.data < predessor.beta:
                predessor.value = predessor.data = t.data
        a.add(t.data)
    else:
        t.value = t.left.value
        if(t.operation == "max"):
            t.alpha = t.value
            if predessor is not None:
                if t.value > predessor.beta:
                    print "..................prune @ ", t.value
                    return
            a.add(t.value)
        else:
            t.beta = t.value
            if predessor is not None:
                if t.value < predessor.alpha:
                    print "..................prune @ ", t.value
                    return
            a.add(t.value)
        try:
            decesion_tree(t.center, t)
        except:
            print "No center"
        decesion_tree(t.right, t)


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
                    tree.value = float('-infinity')
                    tree.alpha = float('-infinity')
                    tree.beta = float('+infinity')
                else:
                    tree.operation = "min"
                    tree.value = float('+infinity')
                    tree.alpha = float('-infinity')
                    tree.beta = float('+infinity')
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
                    tree.value = float('-infinity')
                    tree.alpha = float('-infinity')
                    tree.beta = float('+infinity')
                else:
                    tree.operation = "min"
                    tree.value = float('+infinity')
                    tree.alpha = float('-infinity')
                    tree.beta = float('+infinity')
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
    print "\nVisited Nodes: ", a


if __name__ == "__main__" and __package__ is None:
    create_tree()
