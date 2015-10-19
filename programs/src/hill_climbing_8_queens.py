import random, copy
from os import sys, path
'''
The program follow the algorithm and example from A.I. Modern Approach
It assumes that there will be no two queens in same column
It follow Hill_climbing with optimisation of random restart.

For a single time the program stucks in a local minimum,
But when repeated several times it comes closer to solution
'''
def hill_chess(board):
    '''This will store the currrent succsessors state and heuristics value'''
    moves = {}
    for col in range(len(board)):
        best_move = board[col]
        for row in range(len(board)):
            if board[col] == row:
            """
            Here we monitor already existing comdition of queen,
            Therefore not operation is performed
            """
                continue

            board_copy = list(board)
            #Move the queen to the new row
            board_copy[col] = row
            moves[(col,row)] = get_heuristics_for_8_queen(board_copy) '''Generating Hurestics for child nodes'''
    print  "len of states ", len(moves)
    best_moves = []
    h_to_beat = get_heuristics_for_8_queen(board) '''Calculating heuristics for parent'''
    '''This loop finds minimum value from the list'''
    for k,v in moves.iteritems():
        if v < h_to_beat:
            h_to_beat = v
    '''This loop monitior the same minimum values and stores it'''
    for k,v in moves.iteritems():
        if v == h_to_beat:
            best_moves.append(k)
    print best_moves

    '''Pick a random best move if there are multiple moves.'''
    if len(best_moves) > 0:
        pick = random.randint(0,len(best_moves) - 1)
        col = best_moves[pick][0]
        row = best_moves[pick][1]
        board[col] = row

    return board

if __name__ == "__main__" and __package__ is None:
    sys.path.append(path.dirname(path.dirname(path.abspath(__file__))))
    from lib.queens_heuristics import *
    a = [3, 2, 1, 4, 3, 2, 1, 2]
    b = []
    print "Initial Hurestics of start state ",get_heuristics_for_8_queen(a)
    #[7, 5, 3, 1, 6, 4, 2, 0] [3, 2, 1, 4, 3, 2, 1, 2]
    while True:
        a = hill_chess(a)
        #raw_input()
        if a == b:
            break
        print a,b
        b = copy.deepcopy(a)
    print "Final goal state Hurestics ", get_heuristics_for_8_queen(a)
