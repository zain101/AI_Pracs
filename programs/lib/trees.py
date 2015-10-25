class Trees(object):
    def __init__(self, data=None):
        self.data = data
        self.left = None
        self.right = None
        self.center = None
        self.operation = None
    def __str__(self):
        return str(self.__dict__)


if __name__ == "__main__":
    pass
