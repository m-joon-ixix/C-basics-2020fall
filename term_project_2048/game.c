/*
Programming Practice Term Project - 2048 game
made by Minjoon Choi (2019-14500)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

int board[4][4]; // game board
int score = 0;

typedef struct{
	int i;
	int j;
} index_pair;

index_pair randomUnoccupiedIndex(){ // done
	// random index that is unoccupied (entry = 0)
	srand(time(NULL));
	index_pair idx;
	int row, column;
	do{
		row = rand() % 4;
		column = rand() % 4;
	} while(board[row][column] != 0);
	idx.i = row;
	idx.j = column;
	return idx;
}

void resetGame(){ // done
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			board[i][j] = 0;
		}
	}
	// choose two random spots, and put 2 into those cells
	index_pair unoccupied_idx = randomUnoccupiedIndex();
	board[unoccupied_idx.i][unoccupied_idx.j] = 2;

	unoccupied_idx = randomUnoccupiedIndex();
	board[unoccupied_idx.i][unoccupied_idx.j] = 2;

	score = 0;
}

void printBoard(){ // done
	printf("\033[2J\033[H\033[?25l"); // clear screen, cursor to upper-left

	printf("< 2048 Game > - made by Minjoon Choi\tScore: %d\n\n", score);
	printf("Keys to Press: ↑ or 'W', ↓ or 'S', ← or 'A', → or 'D', 'Q' to QUIT, 'R' to RESTART\n\n\n");

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(board[i][j] == 0) printf("        -");
			else printf("%9d", board[i][j]);
		}
		printf("\n\n\n");
	}
}

void rotateBoard(){ // done
	// counter-clockwise rotation of the board array
	int newBoard[4][4];
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			newBoard[i][j] = board[j][3 - i];
		}
	}

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			board[i][j] = newBoard[i][j];
		}
	}
}

bool isLeftOccupied(int* row, int j){ // done
	// checks if the left of row[j] is occupied
	if(j == 0) return true;

	if(row[j-1] == 0) return false;
	else return true;
}

bool shiftRowLeft(int i){ // done
	// shift board[i] (a single row) to the left
	bool changed = false; // did the row status change?
	bool blockWasMerged[4] = {false, false, false, false};
	int* row = board[i]; // row[j] == board[i][j]
	// modifying row[j] changes board status
	for(int j = 1; j < 4; j++){
		if(row[j] == 0) continue;
		int k = j;
		while(!isLeftOccupied(row, k)){
			row[k-1] = row[k];
			row[k] = 0;
			k--;
			changed = true;
		}
		// if row[k-1] and row[k] is same, and row[k-1] was never merged, merge them
		if(k == 0) continue; // nothing to merge on left
		if(row[k-1] == row[k] && blockWasMerged[k-1] == false){
			// merge indexes k-1, k
			row[k-1] = row[k-1] + row[k];
			row[k] = 0;
			score += row[k-1];
			blockWasMerged[k-1] = true;
			changed = true;
		}
	}
	return changed;
}

bool moveLeft(){ // done
	bool changed = false;
	for(int i = 0; i < 4; i++){
		changed |= shiftRowLeft(i);
	}
	return changed;
}

bool moveUp(){ // done
	// rotate multiple times, and use moveLeft (don't forget to rotate the board back!)
	rotateBoard();
	bool changed = moveLeft();
	rotateBoard();
	rotateBoard();
	rotateBoard();
	return changed;
}

bool moveRight(){ // done
	// rotate multiple times, and use moveLeft
	rotateBoard();
	rotateBoard();
	bool changed = moveLeft();
	rotateBoard();
	rotateBoard();
	return changed;
}

bool moveDown(){ // done
	// rotate multiple times, and use moveLeft
	rotateBoard();
	rotateBoard();
	rotateBoard();
	bool changed = moveLeft();
	rotateBoard();
	return changed;
}

bool sameBlockExistsNext(int i, int j){
	// does a same number exist on adjacent blocks?
	bool exists = false;
	int thisBlock = board[i][j];
	if(i != 0){
		if(board[i-1][j] == thisBlock) exists = true;
	}
	if(j != 0){
		if(board[i][j-1] == thisBlock) exists = true;
	}
	if(i != 3){
		if(board[i+1][j] == thisBlock) exists = true;
	}
	if(j != 3){
		if(board[i][j+1] == thisBlock) exists = true;
	}
	return exists;
}

bool isGameOver(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(board[i][j] == 0 || sameBlockExistsNext(i, j)) return false;
		}
	}
	return true;
}

void setBufferedInput(bool enable) {
	static bool enabled = true;
	static struct termios old;
	struct termios new;

	if (enable && !enabled) {
		// restore the former settings
		tcsetattr(STDIN_FILENO,TCSANOW,&old);
		// set the new state
		enabled = true;
	} else if (!enable && enabled) {
		// get the terminal settings for standard input
		tcgetattr(STDIN_FILENO,&new);
		// we want to keep the old setting to restore them at the end
		old = new;
		// disable canonical mode (buffered i/o) and local echo
		new.c_lflag &=(~ICANON & ~ECHO);
		// set the new settings immediately
		tcsetattr(STDIN_FILENO,TCSANOW,&new);
		// set the new state
		enabled = false;
	}
}

int main(){
	char input; // keyboard input
	bool changed; // did the board status change by moving?
	int powerOf2[] = {2, 2, 2, 2, 2, 2, 4, 4, 4, 8};
	srand(time(NULL));

	printf("\033[?25l\033[2J"); // remove curser, clear terminal screen

	setBufferedInput(false); // get char without \n
	resetGame();
	printBoard();

	while(true){
		input = getchar();
		switch(input){
			case 'w':
			case 65:
				changed = moveUp();
				break;
			case 's':
			case 66:
				changed = moveDown();
				break;
			case 'a':
			case 68:
				changed = moveLeft();
				break;
			case 'd':
			case 67:
				changed = moveRight();
				break;
			default:
				changed = false;
		}
		
		if(changed){
			index_pair randomIdx = randomUnoccupiedIndex();
			board[randomIdx.i][randomIdx.j] = powerOf2[rand() % 10];
			printBoard();
		}

		if(isGameOver()) break;

		if(input == 'q'){
			printf("Do you want to QUIT? (y/n)\n");
			if(getchar() == 'y') break;
			else printBoard();
		}

		if(input == 'r'){
			printf("Do you want to RESTART? (y/n)\n");
			if(getchar() == 'y') resetGame();
			printBoard();
		}
	}

	setBufferedInput(true); // back to normal state
	printf("\033[?25h\033[m");
	printf("\n-------- Game Over --------\n\n");
	printf("Your Final Score: %d\n\n", score);
    return 0;
}
