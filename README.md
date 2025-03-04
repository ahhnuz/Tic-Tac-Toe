Tic Tac Toe is a game in which two players pick X’s or O’s alternately in a matrix cell formed by two vertical and horizontal lines crossing each other. Each player tries to place three of their marks in a horizontal, vertical, or diagonal row. The player who put in this form will succeed in the game.

The program uses a 2D character array to represent the game board, where 'X' and 'O' represent player moves, and ' ' represents empty cells. The program checks for winning conditions (rows, columns, diagonals) and draw conditions (all cells filled). File handling is used to store game data persistently.
Game Logic: The game uses a board[3][3] array to store the state of the Tic-Tac-Toe board. The currentplayer variable tracks whose turn it is. The checkwin() function checks for winning combinations, and checkdraw() checks for a draw.
File Handling: The program uses fopen(), fscanf(), fprintf(), and fclose() to read and write game data to files.
"tic_tac_toe_data.txt" stores the game count and player win counts.
"tic_tac_toe_board.txt" stores the final state of each game board.
Data Persistence: The loadgamedata() function reads data from "tic_tac_toe_data.txt" at the start of the program, and savegamedata() writes updated data to the file when a game ends. The board state is appended to "tic_tac_toe_board.txt" after each game.
