# tictactoe.py
def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("-" * 9)

def check_winner(board):
    # Check rows
    for row in board:
        if row[0] == row[1] == row[2] != " ":
            return row[0]

    # Check columns
    for col in range(3):
        if board[0][col] == board[1][col] == board[2][col] != " ":
            return board[0][col]

    # Check diagonals
    if board[0][0] == board[1][1] == board[2][2] != " ":
        return board[0][0]
    if board[0][2] == board[1][1] == board[2][0] != " ":
        return board[0][2]

    return None

def is_board_full(board):
    for row in board:
        if " " in row:
            return False
    return True

def tictactoe():
    board = [[" " for _ in range(3)] for _ in range(3)]
    current_player = "X"

    print("Welcome to Tic-Tac-Toe!")
    print("Enter row and column numbers (0-2) separated by space")

    while True:
        print_board(board)
        print(f"Player {current_player}'s turn")

        try:
            row, col = map(int, input("Enter your move: ").split())
            if row not in range(3) or col not in range(3):
                print("Invalid input! Row and column must be 0, 1, or 2")
                continue

            if board[row][col] != " ":
                print("That position is already taken!")
                continue

            board[row][col] = current_player

            winner = check_winner(board)
            if winner:
                print_board(board)
                print(f"Player {winner} wins!")
                break

            if is_board_full(board):
                print_board(board)
                print("It's a tie!")
                break

            current_player = "O" if current_player == "X" else "X"

        except ValueError:
            print("Invalid input! Please enter two numbers separated by space")

if __name__ == "__main__":
    tictactoe()