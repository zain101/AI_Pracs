import heapq
import random, copy
from os import sys, path
visited=[]
class MYPriority_Q(object):
    """docstring for MYPriority_Q"""
    def __init__(self):
        self.heap = []
    def add(self, m):
        if (m.values(), m) not in self.heap:
            heapq.heappush(self.heap, (m.values(), m))
    def get(self):
        while(True):
            if (len(self.heap)):
                z = heapq.heappop(self.heap)
                #print z
            else:
                break
            #print "\n...", self.heap, "\n..."
            if z not in visited:
                break
        visited.append(z)
        return z
'''
The program follow the algorithm and example from A.I. Modern Approach
It assumes that there will be no two queens in same column
It follow Hill_climbing with optimisation of random restart.

For a single time the program stucks in a local minimum,
But when repeated several times it comes closer to solution
'''
def hill_chess(board):
    '''This will store the currrent succsessors state and heuristics value'''
    flag=1
    pq = MYPriority_Q()
    pq.heap.append("10")
    while(pq is not None ):
        if flag == 1:
            flag = 0
            pq.heap = []
        for col in range(len(board)):
            best_move = board[col]
            for row in range(len(board)):
                if board[col] == row:
                    """
                    Here we monitor already existing comdition of queen,
                    Therefore not operation is performed
                    """
                    continue
                moves = {}
                board_copy = list(board)
                #Move the queen to the new row
                board_copy[col] = row
                '''Generating Hurestics for child nodes'''
                moves[tuple(board_copy)] = get_heuristics_for_8_queen(board_copy)
                pq.add(moves)
        #print pq.heap
        #raw_input()
        smallest = pq.get()
        board = list(smallest[1].keys()[0])
        #print smallest
        if not smallest[1].values()[0]:
            break

    return board

if __name__ == "__main__" and __package__ is None:
    sys.path.append(path.dirname(path.dirname(path.abspath(__file__))))
    from lib.queens_heuristics import *
    a =  [3, 2, 1, 4, 3, 2, 1, 2] #[0, 0, 1, 1, 2, 2, 3, 3]#[0, 1, 2, 3, 4, 5, 6, 7] #[7, 5, 3, 1, 6, 4, 2, 0]
    b = []
    print "Initial Hurestics of start state ",get_heuristics_for_8_queen(a)
    a = hill_chess(a)
    print "Final goal state (%s) Hurestics is (%s) "%(a , get_heuristics_for_8_queen(a))
