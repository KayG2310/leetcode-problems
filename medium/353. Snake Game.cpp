class SnakeGame {
private:
    int boardHeight;                           // Height of the game board
    int boardWidth;                            // Width of the game board
    vector<vector<int>> foodPositions;         // List of food positions
    int currentScore;                           // Current game score
    int nextFoodIndex;                          // Index of next food to eat
    deque<int> snakeBody;                       // Snake body positions (head at front)
    unordered_set<int> occupiedCells;          // Set of cells occupied by snake
    int encodePosition(int row, int col) {
        return row * boardWidth + col;
    }
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        boardHeight = height;
        boardWidth = width;
        this->foodPositions = food;
        currentScore = 0;
        nextFoodIndex = 0;
        snakeBody.push_back(0);
        occupiedCells.insert(0);
    }
    int move(string direction) {
        int headPosition = snakeBody.front();
        int currentRow = headPosition / boardWidth;
        int currentCol = headPosition % boardWidth;
        int newRow = currentRow;
        int newCol = currentCol;

        if (direction == "U") newRow--;
        else if (direction == "D") newRow++;
        else if (direction == "L") newCol--;
        else newCol++;
        // Check if snake hits the wall
        if (newRow < 0 || newRow >= boardHeight || newCol < 0 || newCol >= boardWidth) return -1;
        if (nextFoodIndex < foodPositions.size() && newRow == foodPositions[nextFoodIndex][0] && newCol == foodPositions[nextFoodIndex][1]){
            // Snake grows - increase score and move to next food
            currentScore++;
            nextFoodIndex++;
        } 
        else {
            // Snake moves without growing - remove tail
            int tailPosition = snakeBody.back();
            snakeBody.pop_back();
            occupiedCells.erase(tailPosition);
        }
        int newHeadPosition = encodePosition(newRow, newCol);
        // Check if snake hits itself
        if (occupiedCells.count(newHeadPosition)) return -1;
        snakeBody.push_front(newHeadPosition);
        occupiedCells.insert(newHeadPosition);
        return currentScore;
    }
};
