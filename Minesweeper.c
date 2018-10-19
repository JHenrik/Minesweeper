// 10x10 minesweeper game in console
// Created by Juuso Hynynen
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define gridy 5 //Size of grid in the X direction
#define gridx 5 //Size of grid in the Y direction
#define BOMBS 2 //Amount of bombs in the field

int Game();



int main(void) {
	Game();



	return 0;
}

int Game() {

	char bombgrid[gridy][gridx]; // Grid for the Underlayer with bombs and indicators
	char playergrid[gridy][gridx]; // Grid for the player to see with just plabk tiles 
	char temp = 'H'; // Temp to keep the previous tile in memory
	// Movement input on the grid
	int inputx = 0; 
	int inputy = 0; 
	// Two sets of parameters for printing grids
	int i;
	int j;
	int h;
	int k;

	int squareval; // o add to the tiles around bombs 
	int bombcount = 0; // Count of the bobm amount to be able to beat the game

	int exit = 1; // To exit the game when finished 
	srand(time(NULL));




	// Fill the grid
	for (i = 0; i < gridy; i++) {
		for (j = 0; j < gridx; j++) { 

			bombgrid[i][j] = '0';
		}
	}

	// Fill the grid with bombs randomly generated
	for (k = 0; k <= BOMBS; k++) {
		bombgrid[rand() % 9 + 1][rand() % 9 + 1] = '*';
	}



	// Find the cordinates of the bombs 
	for (h = 0; h < gridy; h++) {
		for (k = 0; k < gridx; k++) {
			if (bombgrid[h][k] == '*') // If the square is a bomb 
			{	// Always check that the square is not a bomb if not it will add 1 to the tile
				if (bombgrid[h + 1][k] != '*') { // From the bomb 1 up 
					bombgrid[h + 1][k] ++;		 
				}							 
				if (bombgrid[h - 1][k] != '*') { // From the bomb 1 down
					bombgrid[h - 1][k] ++;
				}
				if (bombgrid[h][k + 1] != '*') { // From the bomb 1 right
					bombgrid[h][k + 1] ++;
				}
				if (bombgrid[h][k - 1] != '*') { // From the bomb 1 left
					bombgrid[h][k - 1]++;
				}
				if (bombgrid[h + 1][k + 1] != '*') { // From the bomb 1 up 1 right
					bombgrid[h + 1][k + 1]++;
				}
				if (bombgrid[h + 1][k - 1] != '*') { // From the bomb 1 up 1 left
					bombgrid[h + 1][k - 1]++;
				}
				if (bombgrid[h - 1][k + 1] != '*') { // From the bomb 1 down 1 right
					bombgrid[h - 1][k + 1]++;
				}
				if (bombgrid[h - 1][k - 1] != '*') { // From the bomb 1 down 1 left
					bombgrid[h - 1][k - 1]++;
				}
			}
		}
	}

	for (i = 0; i < gridy; i++) {
		for (j = 0; j < gridx; j++) {

			playergrid[i][j] = 'H';
		}
	}




	while (bombcount < BOMBS) {

		
		for (h = 0; h < gridy; h++) {
			for (k = 0; k < gridx; k++){ 
				
			}	
			
		}
		

		printf("use W,A,S,D to move, F to flag the spot and O to open it \n");
		// Prints the player grid 
		for (h = 0; h < gridy; h++) {
			for (k = 0; k < gridx; k++) {
				printf("%c  ", playergrid[h][k]);
			}
			printf("\n");

		}

		// The navigation system uses getc as a listener for the keypressed
		char c;
		c = getc(stdin);

		switch (c)
		{

		case 'w':
			playergrid[inputy][inputx] = temp; // Take starting grid and store the value
			if ((inputy - 1) < 0)	// If it goes outside of the grid it goes to other side
			{
				inputy = gridy - 1;
			}
			else
			{
				inputy--; // Otherwise it just moves one space
			}
			temp = playergrid[inputy][inputx]; // After move set temp to be the new position
			playergrid[inputy][inputx] = ' '; // This is the cursor that shows the space that is selected
			break;
		case 'a':
			playergrid[inputy][inputx] = temp;
			if ((inputx - 1) < 0)
			{
				inputx = gridx - 1;
			}
			else
			{
				inputx--;
			}
			temp = playergrid[inputy][inputx];
			playergrid[inputy][inputx] = ' ';
			break;
		case 's':
			playergrid[inputy][inputx] = temp;
			if ((inputy + 1) == gridy)
			{
				inputy = 0;
			}
			else
			{
				inputy++;
			}
			temp = playergrid[inputy][inputx];
			playergrid[inputy][inputx] = ' ';
			break;
		case 'd':
			playergrid[inputy][inputx] = temp;
			if ((inputx + 1) == gridx)
			{
				inputx = 0;
			}
			else
			{
				inputx++;
			}
			temp = playergrid[inputy][inputx];
			playergrid[inputy][inputx] = ' ';
			break;


		case 'f':

			if (bombgrid[inputy][inputx] == '*' && (bombgrid[inputy][inputx] != 'F')) // If flag is placed on a bomb and is not a flag
			{
				bombcount++; // Add one to bombcount to know how many bombs are found
			}
			playergrid[inputy][inputx] = 'F'; // Prints an F to the grid
			temp = playergrid[inputy][inputx]; 
			break;

		case 'o':
			if (bombgrid[inputy][inputx] != '*') // If you open a cell and it is not a bomb
			{
				playergrid[inputy][inputx] = bombgrid[inputy][inputx]; // Replace the cell from the grid that has the values
				temp = playergrid[inputy][inputx]; 
			}
			else // If the place is a bomb than end the game and print game over
			{
				printf("game over\n");
				return 0;
			}
			break;

		default:
			printf("Use lowercase letters!\n\n");
			break;
		}


	}

}