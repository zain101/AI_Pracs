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
        self.visited = None

    def __str__(self):
        for i in self.__dict__:
            print i, " = ", self.__dict__[i]
        return ""

if __name__ == "__main__":
    t = Trees(data=10)
    print t
