/*
Rat in a Maze: algorithm for backtracking, function evaluates all possible paths that connect the top-left corner of a grid to the bottom-right corner.
Cells marked with 1 may be travelled through, while cells marked 0 are blocked. The rat must avoid blocked cells and cannot revisit cells.
Function finds ALL possible paths that the rat can take to reach the end of the maze.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Global Variables
vector<vector<int>> Maze;
vector<vector<int>> visitedCells;
vector<string> allPaths;
int mazeSize;

void backtrackMaze(int x, int y, string path) {
    //Base Case: Rat reaches the end of the Maze (mazeSize-1, mazeSize-1)
    if (x == mazeSize-1 && y == mazeSize-1) {
        allPaths.push_back(path);
        return;
    }

    //Directions: Down, Left, Right, Up
    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};
    char dir[] = {'D', 'L', 'R', 'U'};

    //Mark the current cell as visited
    visitedCells[x][y] = 1;

    //Check each direction
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        //Check new cell is in bounds and has not been visited yet
        if (newX >= 0 && newY >= 0 && newX < mazeSize && newY < mazeSize &&
            Maze[newX][newY] == 1 && !visitedCells[newX][newY]) {
            backtrackMaze(newX, newY, path + dir[i]);
            }
    }

    //Explore alternative paths by backtracking
    visitedCells[x][y] = 0;
}


int main() {
    Maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    mazeSize = Maze.size();
    visitedCells.assign(mazeSize, vector<int>(mazeSize, 0));

    if (Maze[0][0] == 1) {
        backtrackMaze(0, 0, "");
    }

    if (allPaths.empty()) {
        cout << "The rat cannot complete the maze :(" << endl;
    } else {
        cout << "All possible paths through the maze:" << endl;
        for (auto &p : allPaths) cout << p << endl;
    }

    return 0;
}