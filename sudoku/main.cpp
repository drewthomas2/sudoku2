//  main.cpp
//  sudoku
//
//  Created by Drew Thomas on 8/31/18.
//  Copyright © 2018 Drew Thomas. All rights reserved.
//
#include <iostream>

using namespace std;

#define UNASSIGNED 0
#define N 9

bool FindUnassignedLocation(int grid[N][N], int &row, int &col);

bool isSafe(int grid[N][N], int row, int col, int num);

bool SolveSudoku(int grid[N][N]){
	int row, col;
	if (!FindUnassignedLocation(grid, row, col)){
		return true;
	}
	
	for (int num = 1; num <= 9; num++){
		if (isSafe(grid, row, col, num)){
			grid[row][col] = num;
			if (SolveSudoku(grid)){
				return true;
			}
			grid[row][col] = UNASSIGNED;
		}
	}
	return false;
}

bool FindUnassignedLocation(int grid[N][N], int &row, int &col){
	for (row = 0; row < N; row++){
		for (col = 0; col < N; col++){
			if (grid[row][col] == UNASSIGNED){
				return true;
			}
		}
	}
	return false;
}

bool UsedInRow(int grid[N][N], int row, int num){
	for (int col = 0; col < N; col++){
		if (grid[row][col] == num){
			return true;
		}
	}
	return false;
}

bool UsedInCol(int grid[N][N], int col, int num){
	for (int row = 0; row < N; row++){
		if (grid[row][col] == num){
			return true;
		}
	}
	return false;
}

bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num){
	for (int row = 0; row < 3; row++){
		for (int col = 0; col < 3; col++){
			if (grid[row + boxStartRow][col + boxStartCol] == num){
				return true;
			}
		}
	}
	return false;
}

bool isSafe(int grid[N][N], int row, int col, int num){
	return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row % 3, col - col % 3, num) && grid[row][col] == UNASSIGNED;
}

void printGrid(int grid[N][N]){
	for (int row = 0; row < 3; row++){
		for (int col = 0; col < 3; col++){
			cout << "|" << grid[row][col];
		}
		cout << "| ";
		for (int col = 0; col < 3; col++){
			cout << "|" << grid[row][col];
		}
		cout << "| ";
		for (int col = 0; col < 3; col++){
			cout << "|" << grid[row][col];
		}
		cout << "|" << endl;
	}
	cout << endl;
	for (int row = 0; row < 3; row++){
		for (int col = 0; col < 3; col++){
			cout << "|" << grid[row][col];
		}
		cout << "| ";
		for (int col = 0; col < 3; col++){
			cout << "|" << grid[row][col];
		}
		cout << "| ";
		for (int col = 0; col < 3; col++){
			cout << "|" << grid[row][col];
		}
		cout << "|" << endl;
	}
	cout << endl;
	for (int row = 0; row < 3; row++){
		for (int col = 0; col < 3; col++){
			cout << "|" << grid[row][col];
		}
		cout << "| ";
		for (int col = 0; col < 3; col++){
			cout << "|" << grid[row][col];
		}
		cout << "| ";
		for (int col = 0; col < 3; col++){
			cout << "|" << grid[row][col];
		}
		cout << "|" << endl;
	}
}

int main(){
	int grid[N][N] = {{0, 0, 0,   0, 0, 0,   0, 0, 0},
		{0, 0, 0,   0, 0, 0,   0, 0, 0},
		{0, 0, 0,   0, 0, 0,   0, 0, 0},
		
		{0, 0, 0,   0, 0, 0,   0, 0, 0},
		{0, 0, 0,   0, 0, 0,   0, 0, 0},
		{0, 0, 0,   0, 0, 0,   0, 0, 0},
		
		{0, 0, 0,   0, 0, 0,   0, 0, 0},
		{0, 0, 0,   0, 0, 0,   0, 0, 0},
		{0, 0, 0,   0, 0, 0,   0, 0, 0},};
	//    printGrid(grid);
	cout << "enter a couple of numbers" << endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int a;
			cout << "[" << (i+1) << ", " << (j+1) << "] = ";
			cin >> a;
			grid[i][j] = a;
		}
	}
	if (SolveSudoku(grid) == true){
		printGrid(grid);
		cout << "it works" << endl;
	}else{
		cout << "No solution exists";
		return 0;
	}
}
/*    int grid[N][N] = {{0, 0, 0,   0, 0, 0,   0, 0, 0},
 {0, 0, 0,   0, 0, 0,   0, 0, 0},
 {0, 0, 0,   0, 0, 0,   0, 0, 0},
 
 {0, 0, 0,   0, 0, 0,   0, 0, 0},
 {0, 0, 0,   0, 0, 0,   0, 0, 0},
 {0, 0, 0,   0, 0, 0,   0, 0, 0},
 
 {0, 0, 0,   0, 0, 0,   0, 0, 0},
 {0, 0, 0,   0, 0, 0,   0, 0, 0},
 {0, 0, 0,   0, 0, 0,   0, 0, 0},};*/
