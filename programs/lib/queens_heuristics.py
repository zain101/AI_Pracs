def get_heuristics_for_8_queen(board):
    h = 0
    #Check for every row
    for i in range(len(board)):
        #Check for every column
        for j in range(i + 1,len(board)):
            #print i,j
            #Queens are in the same row
            if board[i] == board[j]:
                h += 1
                #print "got in row"
            #Get the difference between the current column and the check column
            offset = j - i
            #print "offset", offset
            '''
            To be a diagonal, the check column value has to be equal
            to the current column value +/- the offset
            Adding or subracting helps us to normalize the "CHECK CLOUMN QUEEN"
            if narmalization results in the same column as current queen
            then
                queens are diagonal to eachother
            '+' ---> for below normalization
            '-' ---> for above normalization
            '''
            if board[i] == board[j] - offset or board[i] == board[j] + offset:
                h += 1
    return h




if __name__ == "__main__":
    print get_heuristics_for_8_queen([7, 5, 3, 1, 6, 4, 2, 0])
