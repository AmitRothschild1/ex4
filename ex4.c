/******************
Name: Amit Rothschild
ID: 322317637
Assignment: EX4
*******************/
#include <stdio.h>
#include <string.h>
#define starter (-1)
#define addOne 1
#define second 2
#define numOfDetails 3
#define pyramidSize 5
#define letterNum 16



/*--------------------------------------------------------------------------------------------------------------------*/
int task1RobotPaths(int col ,int row);
/*--------------------------------------------------------------------------------------------------------------------*/
float task2HumanPyramid(int curCol ,int curRow,float pyramid[pyramidSize][pyramidSize]);
/*--------------------------------------------------------------------------------------------------------------------*/
char getCloser(char opener);
int task3ParenthesisValidator(int block,int square,int circle,int triangle,char opener);
int task3ParenthesisValidator1(int block, int square, int circle, int triangle, char opener);
/*--------------------------------------------------------------------------------------------------------------------*/
void makeItAsterisk(int size,char queensBoard[size][size],int currentRow,int currentCol);
int colorIsOccupied(int size,char arr[size][size],int currentRow,int currentCol ,char queensArr[size][size],
    int xRow,int xCol);
int columnIsOccupied(int size,int currentRow,char queensArr[size][size],int xRow,int xCol);
int isLinkedTo(int size,char queensArr[size][size],int xRow,int xCol);
int properQueenPlace(int size,char arr[size][size],int currentRow,int currentCol ,
char queensArr[size][size],int xRow,int xCol);
int queenColumn(int size,int xRow,int currentCol ,char queensArr[size][size]);
int rowIsEmpty(int size,int xRow,int currentCol,char queensArr[size][size]);
int task4QueensBattle(int size,char arr[size][size],int currentRow,int currentCol ,char queensArr[size][size]);
/*--------------------------------------------------------------------------------------------------------------------*/
void enterDetails(int numOfSlots, int slotDetails[numOfDetails][numOfSlots], char directions[numOfSlots]);
void initializeGrid(int gridSize, char grid[gridSize][gridSize]);
void initializeWordSlotArray(int numOfSlots, int wordInSlot[numOfSlots]);
void printGrid(int gridSize, char grid[gridSize][gridSize]);
void enterDetails(int numOfSlots,int slotDetails[numOfDetails][numOfSlots],char directions[numOfSlots]);
void wordInSlotIsMinus(int numOfSlots,int arr[numOfSlots],int currentCol);
void mainGridZeroStart(int gridSize,int numOfSlots,int slotsDetails[numOfDetails][numOfSlots],
    char mainGrid[gridSize][gridSize],int slotNum,int counter,char direction[numOfSlots]);
void mainGridLadderStart(int gridSize,int row,int col,char mainGrid[gridSize][gridSize]);
void getWordInput(int numOfWords,char dictionary[numOfWords][letterNum],int row,int col);
void makeItMinus(int rows,int cols,int arr[rows][cols],int currentRow,int currentCol);
void makeItZero(int numOfWords,char dictionary[numOfWords][letterNum],int currentRow,int currentCol);
int slotIsEmpty(int arrSize,char arr[arrSize][arrSize],int row,int col,char direction);
int haveMutualLetters(int gridSize,char direction,char grid[gridSize][gridSize],int curRow,int curCol
       ,int numOfWords,int wordRow,char dictionary[numOfWords][letterNum],int count);
int wordSizeCounter(int numOfWords,int wordRow,char dictionary[numOfWords][letterNum],int counter);
int isTheSameSize(int wordSize,int numOfSlots,int slotNum,int slotDetails[numOfDetails][numOfSlots]);
int wordIsUsed(int counter,int numOfSlots,int wordNum,int wordInSlot[numOfSlots]);
int canBeInserted(int gridSize,char direction,char grid[gridSize][gridSize],int curRow,int curCol,int numOfWords,
       int wordRow,char dictionary[numOfWords][letterNum],int wordSize,int numOfSlots,int slotNum,
       int slotDetails[numOfDetails][numOfSlots],int wordInSlot[numOfSlots]);
void enterWordInSlot(int counter,int gridSize,char grid[gridSize][gridSize],int numOfSlots,int slotNum,
       int slotDetails[numOfDetails][numOfSlots],char direction,int numOfWords,int wordRow,
       char dictionary[numOfWords][letterNum],int wordInSlot[numOfSlots]);
void deleteWordFromSlot(int counter,int gridSize,char grid[gridSize][gridSize],int numOfSlots,int slotNum,
        int slotDetails[numOfDetails][numOfSlots],char direction,int numOfWords,int wordRow,
        char dictionary[numOfWords][letterNum],int wordInSlot[numOfSlots]);
int task5CrosswordGenerator(int gridSize, char mainGrid[gridSize][gridSize],
                            int numOfWords, int wordNum, char dictionary[numOfWords][letterNum], int numOfSlots,
                            int slotNum, char slotDirections[numOfSlots], int slotDetails[numOfDetails][numOfSlots],
                            int wordInSlot[numOfSlots]);

int main()
{
    int task = -1;
    do
    {
        printf("Choose an option:\n"
               "1. Robot Paths\n"
               "2. The Human Pyramid\n"
               "3. Parenthesis Validation\n"
               "4. Queens Battle\n"
               "5. Crossword Generator\n"
               "6. Exit\n");

        if (scanf("%d", &task))
        {
            switch (task)
            {
            case 6:
                printf("Goodbye!\n");
                break;
            case 1:
                int column, row;
                printf("Please enter the coordinates of the robot (column, row):\n");
                scanf("%d %d", &column, &row); // Reading the coordinates (column, row) of the robot from the user
                printf("The total number of paths the robot can take to reach home is: %d\n",
                    task1RobotPaths(column, row)); // Calling the function to calculate the number of paths and printing the result
                break;

            case 2:
                int negativeCheck = 0; // Flag to check if negative weights are entered
                float pyramid[pyramidSize][pyramidSize] = {0}; // Initializing a 2D array to store the weights of the pyramid
                printf("Please enter the weights of the cheerleaders:\n");
                for (int i = 0; i < pyramidSize; i++) // Loop through rows of the pyramid
                {
                    for (int j = 0; j <= i; j++) // Loop through columns of the pyramid for each row
                    {
                        scanf("%f", &pyramid[i][j]); // Reading weight value for each position in the pyramid
                        if (pyramid[i][j] < 0) // Checking if the entered weight is negative
                        {
                            negativeCheck = addOne; // Set flag if negative weight is found
                            break; // Exit inner loop if negative weight is detected
                        }
                    }
                    if (negativeCheck == addOne) // Check if negative weight was detected in any row
                        break; // Exit outer loop if negative weight is detected
                }
                if (negativeCheck == addOne) // Handle the case of negative weight
                {
                    printf("Negative weights are not supported.\n"); // Inform user about unsupported input
                    scanf("%*[^\n]"); // Clean the input buffer to prevent issues with subsequent inputs
                    break;
                }
                printf("The total weight on each cheerleader is:\n");
                for (int i = 0; i < pyramidSize; i++) // Loop through rows of the pyramid for output
                {
                    for (int j = 0; j < pyramidSize; j++) // Loop through columns for each row
                    {
                        printf("%.2f ", task2HumanPyramid(j, i, pyramid)); // Print the calculated weight for each cheerleader
                        if (j == i) // Break inner loop after printing all values in the row
                            j = pyramidSize;
                    }
                    printf("\n"); // Move to the next line for the next row of the pyramid
                }
                scanf("%*[^\n]"); // Clean the input buffer for subsequent user inputs
                break;

            case 3:
                char open;
                printf("Please enter a term for validation:\n");
                scanf("%c", &open); // Reading a character to start parenthesis validation
                if (task3ParenthesisValidator1(0, 0, 0, 0, '0') == 0) // Call the function to validate parentheses
                    printf("The parentheses are balanced correctly.\n"); // Print success message if balanced
                else
                    printf("The parentheses are not balanced correctly.\n"); // Print error message if not balanced
                break;
            case 4:
                {
                    int boardSize;
                    printf("Please enter the board dimensions:\n");
                    scanf("%d", &boardSize); // Read the dimensions of the board
                    char areasBoard[boardSize][boardSize];
                    printf("Please enter a %d*%d puzzle board:\n", boardSize, boardSize);
                    for (int i = 0; i < boardSize; i++) // Loop to populate the puzzle board
                    {
                        for (int j = 0; j < boardSize; j++)
                            scanf(" %c", &areasBoard[i][j]); // Read each cell of the puzzle board
                    }
                    char queensBoard[boardSize][boardSize];
                    makeItAsterisk(boardSize, queensBoard, 0, 0); // Initialize the queens board with asterisks
                    if (task4QueensBattle(boardSize, areasBoard, 0, 0, queensBoard)) // Attempt to solve the puzzle
                    {
                        printf("Solution:\n");
                        for (int i = 0; i < boardSize; i++) // Print the solved queens board
                        {
                            for (int j = 0; j < boardSize; j++)
                                printf("%c ", queensBoard[i][j]);
                            printf("\n");
                        }
                    }
                    else
                        printf("This puzzle cannot be solved.\n"); // Inform the user if the puzzle is unsolvable
                    scanf("%*[^\n]"); // Clean the input buffer
                    break;
                }

            case 5:
                {
                    int gridSize, numOfSlots, numOfWords;

                    printf("Please enter the dimensions of the crossword grid:\n");
                    scanf("%d", &gridSize); // Read the dimensions of the crossword grid

                    printf("Please enter the number of slots in the crossword:\n");
                    scanf("%d", &numOfSlots); // Read the number of slots in the crossword

                    char grid[gridSize][gridSize];
                    initializeGrid(gridSize, grid); // Initialize the crossword grid

                    for (int i = 0; i < gridSize; i++) // Populate the grid with default values
                        for (int j = 0; j < gridSize; j++)
                            grid[i][j] = '#'; // Fill the grid with '#' symbols

                    int slotDetails[numOfDetails][numOfSlots];
                    for (int i = 0; i < numOfDetails; i++) // Initialize the slot details to 0
                    {
                        for (int j = 0; j < numOfSlots; j++)
                        {
                            slotDetails[i][j] = 0; // Set all entries in slotDetails to 0
                        }
                    };
                    char directions[numOfSlots]; // Array to store directions of each slot

                    printf("Please enter the details for each slot (Row, Column, Length, Direction):\n");
                    enterDetails(numOfSlots, slotDetails, directions); // Gather slot details from the user
                    // Process and set up the grid based on the slot details
                    mainGridZeroStart(gridSize, numOfSlots, slotDetails, grid, 0, 0, directions);

                    printf("Please enter the number of words in the dictionary:\n");
                    scanf("%d", &numOfWords); // Read the number of words in the dictionary

                    while (numOfWords < numOfSlots) // Ensure that there are enough words for the slots
                    {
                        printf("The dictionary must contain at least %d words. ",numOfSlots);
                        printf("Please enter a valid dictionary size:\n");
                        scanf("%d", &numOfWords);
                    }

                    char dictionary[numOfWords][letterNum];
                    for (int i = 0; i < numOfWords; i++) // Initialize the dictionary array
                        for (int j = 0; j < letterNum; j++)
                            dictionary[i][j] = '0'; // Set all entries in the dictionary to '0'
                    printf("Please enter the words for the dictionary:\n");
                    for (int i = 0; i < numOfWords; i++) // Read each word in the dictionary
                    {
                        scanf("%s", dictionary[i]);
                    }

                    int wordInSlot[numOfSlots];
                    for (int i = 0; i < numOfSlots; i++) // Initialize the wordInSlot array
                    {
                        wordInSlot[i] = -1; // Set all entries in wordInSlot to -1 (no word assigned)
                    }
                    initializeWordSlotArray(numOfSlots, wordInSlot); // Prepare word slot array for processing

                    if (task5CrosswordGenerator(gridSize, grid, numOfWords, 0, dictionary, numOfSlots, 0,
                        directions, slotDetails, wordInSlot))
                    {
                        printGrid(gridSize, grid); // Print the solved crossword grid if a solution is found
                    }
                    else
                        printf("This crossword cannot be solved.\n"); // Inform the user if the crossword is unsolvable
                    break;
                }

            default:
                printf("Please choose a task number from the list.\n"); // Prompt the user to enter a valid task number
                break;
            }
        }
        else
        {
            scanf("%*s");
        }

    } while (task != 6);
}
/*Task-1--------------------------------------------------------------------------------------------------------------*/
int task1RobotPaths(int col, int row)
{
    // Base case: If the robot is at the starting position (0, 0), there's only 1 path (stay there)
    if (col == 0 && row == 0)
        return 1;

    // Base case: If the robot goes out of bounds (negative column or row), there are no valid paths
    if (col < 0 || row < 0)
        return 0;

    // Recursive step: The total number of paths to the current position is the sum of:
    // 1. The paths from the cell directly above (row - 1)
    // 2. The paths from the cell directly to the left (col - 1)
    return task1RobotPaths(col - 1, row) + task1RobotPaths(col, row - 1);
}

/* Task-2 ---------------------------------------------------------------------------------------------------------- */

float task2HumanPyramid(int curCol, int curRow, float pyramid[pyramidSize][pyramidSize])
{
    // Base case: If the current position is invalid (outside the pyramid), return 0
    if (curCol > curRow || curCol < 0 || curRow < 0)
        return 0;

    // Recursive step: The total weight on a cheerleader is the sum of:
    // 1. Half of the weight from the cheerleader directly above in the previous row
    // 2. Half of the weight from the cheerleader diagonally to the left in the previous row
    // 3. The cheerleader's own weight at the current position
    return task2HumanPyramid(curCol, curRow - 1, pyramid) / 2 +
           task2HumanPyramid(curCol - 1, curRow - 1, pyramid) / 2 +
           pyramid[curRow][curCol];
}

/*Task-3--------------------------------------------------------------------------------------------------------------*/
char getCloser(char opener) {
    // This function returns the corresponding closing parenthesis for a given opening parenthesis.
    switch (opener) {
    case '{':
        return '}'; // If the opener is '{', return the matching closer '}'
    case '[':
        return ']'; // If the opener is '[', return the matching closer ']'
    case '(':
        return ')'; // If the opener is '(', return the matching closer ')'
    case '<':
        return '>'; // If the opener is '<', return the matching closer '>'
    default:
        return '\0'; // For any invalid input, return a null character to indicate no valid closer
    }
}



int task3ParenthesisValidator(int block,int square,int circle,int triangle,char opener)
{
    char input;
scanf("%c", &input); // Read a single character input from the user
if(input == '\n') // Base case: End of input
{
    if (block == 0 && square == 0 && circle == 0 && triangle == 0) // Check if all parentheses are balanced
    {
        return 0; // Return 0 if all counters are zero (balanced)
    }
    return 1; // Return 1 if any counter is non-zero (unbalanced)
}
// Handle opening parentheses
if (input == '{') { block++; opener = input; } // Increment block counter and update opener for '{'
if (input == '[') { square++; opener = input; } // Increment square counter and update opener for '['
if (input == '(') { circle++; opener = input; } // Increment circle counter and update opener for '('
if (input == '<') { triangle++; opener = input; } // Increment triangle counter and update opener for '<'
// Handle closing parentheses
if (input == '}') block--; // Decrement block counter for '}'
if (input == ']') square--; // Decrement square counter for ']'
if (input == ')') circle--; // Decrement circle counter for ')'
if (input == '>') triangle--; // Decrement triangle counter for '>'
/*
if(input == '}' || input == ']' || input == ')' || input == '>') // Check for closing parentheses
{
    if(input == '0') // This condition appears redundant and may not be applicable
        return task3ParenthesisValidator(block,square,circle,triangle,opener)+1; // Return 1 for an unmatched closing
    if(getCloser(opener) != input) // Check if the closer matches the last opener
        return task3ParenthesisValidator(block,square,circle,triangle,opener)+1; // Return 1 if the closer does not match
}
*/
// Check for negative counters (indicates unmatched closing parenthesis)
if(block < 0 || square < 0 || circle < 0 || triangle < 0)
{
    return task3ParenthesisValidator(block, square, circle, triangle, opener) + 1; // Propagate error through recursion
}
// Recursive call to process the next character
return task3ParenthesisValidator(block, square, circle, triangle, opener);
}
/*Task-4--------------------------------------------------------------------------------------------------------------*/
void makeItAsterisk(int size, char queensBoard[size][size], int currentRow, int currentCol)
{
    // Base case: If all rows are processed, return
    if (currentRow >= size)
        return;

    // Move to the next row if all columns in the current row are processed
    if (currentCol >= size)
    {
        makeItAsterisk(size, queensBoard, currentRow + 1, 0);
        return;
    }

    // Set the current cell to '*'
    queensBoard[currentRow][currentCol] = '*';

    // Recursively process the next column in the same row
    makeItAsterisk(size, queensBoard, currentRow, currentCol + 1);
}

int colorIsOccupied(int size, char arr[size][size], int currentRow, int currentCol, char queensArr[size][size],
    int xRow, int xCol)
{
    // Base case: If we have checked all rows up to xRow, return 0 (not occupied)
    if (currentRow >= xRow)
        return 0;

    // Check if the color matches and the position is occupied by a queen ('X')
    if (arr[currentRow][currentCol] == arr[xRow][xCol] && queensArr[currentRow][currentCol] == 'X')
        return 1;

    // Move to the next column or row as needed
    if (currentCol >= size - 1)
        return colorIsOccupied(size, arr, currentRow + 1, 0, queensArr, xRow, xCol);
    return colorIsOccupied(size, arr, currentRow, currentCol + 1, queensArr, xRow, xCol);
}

int columnIsOccupied(int size, int currentRow, char queensArr[size][size], int xRow, int xCol)
{
    // Base case: If we have checked all rows up to xRow, return 0 (not occupied)
    if (currentRow >= xRow)
        return 0;

    // Check if the column is occupied by a queen ('X')
    if (queensArr[currentRow][xCol] == 'X')
        return 1;

    // Recursively check the next row
    return columnIsOccupied(size, currentRow + 1, queensArr, xRow, xCol);
}

int isLinkedTo(int size, char queensArr[size][size], int xRow, int xCol)
{
    // Base case: If the current row is the first row, no linkage is possible
    if (xRow == 0)
        return 0;

    // Check if any of the neighboring cells in the previous row contains a queen ('X')
    if (queensArr[xRow - 1][xCol - 1] == 'X' || queensArr[xRow - 1][xCol] == 'X' ||
        queensArr[xRow - 1][xCol + 1] == 'X')
        return 1;

    return 0;
}

int properQueenPlace(int size, char arr[size][size], int currentRow, int currentCol,
    char queensArr[size][size], int xRow, int xCol)
{
    // Check if the placement is linked, or if the color or column is occupied
    if (isLinkedTo(size, queensArr, xRow, xCol) ||
        colorIsOccupied(size, arr, currentRow, currentCol, queensArr, xRow, xCol) ||
        columnIsOccupied(size, currentRow, queensArr, xRow, xCol))
        return 0;

    return 1; // Valid queen placement
}

int queenColumn(int size, int xRow, int currentCol, char queensArr[size][size])
{
    // Check if the previous row contains a queen in the current column
    if (queensArr[xRow - 1][currentCol] == 'X')
        return currentCol + 1;

    // Recursively check the next column
    return queenColumn(size, xRow, currentCol + 1, queensArr);
}

int rowIsEmpty(int size, int xRow, int currentCol, char queensArr[size][size])
{
    // Base case: If a queen ('X') is found in the current row, return 0
    if (queensArr[xRow][currentCol] == 'X')
        return 0;

    // Base case: If all columns are checked, return 1 (row is empty)
    if (currentCol >= size)
        return 1;

    // Recursively check the next column
    return rowIsEmpty(size, xRow, currentCol + 1, queensArr);
}

int task4QueensBattle(int size, char arr[size][size], int currentRow, int currentCol, char queensArr[size][size])
{
    // Base case: If all rows are processed, the task is complete
    if (currentRow >= size)
        return 1;

    // Handle the end of a row
    if (currentCol >= size)
    {
        // If the first row is empty, the task fails
        if (currentRow == 0 && rowIsEmpty(size, currentRow, 0, queensArr))
            return 0;

        // If the current row is empty, backtrack and adjust placement
        if (rowIsEmpty(size, currentRow, 0, queensArr))
        {
            int newCol = queenColumn(size, currentRow, 0, queensArr);
            queensArr[currentRow - 1][newCol - 1] = '*'; // Mark the previous queen's position as invalid
            return task4QueensBattle(size, arr, currentRow - 1, newCol, queensArr);
        }

        // If the row is not empty, proceed to the next row
        if (!rowIsEmpty(size, currentRow, 0, queensArr))
            return task4QueensBattle(size, arr, currentRow + 1, currentCol, queensArr);
    }

    // Check if the current position is a proper place for a queen
    if (properQueenPlace(size, arr, 0, 0, queensArr, currentRow, currentCol))
    {
        queensArr[currentRow][currentCol] = 'X'; // Place the queen
        return task4QueensBattle(size, arr, currentRow + 1, 0, queensArr); // Proceed to the next row
    }

    // Continue to the next column in the current row
    return task4QueensBattle(size, arr, currentRow, currentCol + 1, queensArr);
}

/*Task-5--------------------------------------------------------------------------------------------------------------*/
void enterDetails(int numOfSlots, int slotDetails[numOfDetails][numOfSlots], char directions[numOfSlots])
{
    // Collects details for each slot (row, column, length, and direction)
    for (int i = 0; i < numOfSlots; i++)
    {
        int row, col, length;
        char dir;
        scanf("%d %d %d %c", &row, &col, &length, &dir);
        slotDetails[0][i] = row;          // Store row index
        slotDetails[addOne][i] = col;     // Store column index
        slotDetails[second][i] = length;  // Store slot length
        directions[i] = dir;              // Store slot direction ('H' for horizontal, 'V' for vertical)
    }
}

void initializeGrid(int gridSize, char grid[gridSize][gridSize])
{
    // Initializes the crossword grid with default '#' character
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = '#';
        }
    }
}

void initializeWordSlotArray(int numOfSlots, int wordInSlot[numOfSlots])
{
    // Sets each slot in the word-slot mapping array to -1, indicating no word is assigned
    for (int i = 0; i < numOfSlots; i++) {
        wordInSlot[i] = -1;
    }
}

void printGrid(int gridSize, char grid[gridSize][gridSize])
{
    // Prints the crossword grid with borders for visualization
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            printf("| %c ", grid[i][j]);
        }
        printf("|\n");
    }
}

void enterDetails1(int numOfSlots, int slotDetails[numOfDetails][numOfSlots], char directions[numOfSlots])
{
    // Simplified slot details input collection (alternative implementation)
    for (int i = 0; i < numOfSlots; i++)
    {
        scanf("%d %d %d %c", &slotDetails[0][i], &slotDetails[addOne][i], &slotDetails[second][i],
            &directions[i]);
    }
}

void wordInSlotIsMinus(int numOfSlots, int arr[numOfSlots], int currentCol)
{
    // Recursively initializes the word-slot mapping array to -1
    if (currentCol >= numOfSlots)
        return;
    arr[currentCol] = -1;
    wordInSlotIsMinus(numOfSlots, arr, currentCol + 1);
}

void mainGridZeroStart(int gridSize, int numOfSlots, int slotsDetails[numOfDetails][numOfSlots],
    char mainGrid[gridSize][gridSize], int slotNum, int counter, char direction[numOfSlots])
{
    // Marks slots in the main grid with '0', preparing for word placement
    if (slotNum >= numOfSlots)
        return;

    int row = slotsDetails[0][slotNum];          // Start row of the slot
    int col = slotsDetails[addOne][slotNum];     // Start column of the slot
    int length = slotsDetails[second][slotNum];  // Length of the slot

    if (counter > length - 1)
    {
        // Move to the next slot after filling the current slot
        mainGridZeroStart(gridSize, numOfSlots, slotsDetails, mainGrid, slotNum + 1, 0, direction);
        return;
    }

    // Mark slots based on direction
    if (direction[slotNum] == 'H') // Horizontal slot
    {
        mainGrid[row][col + counter] = '0';
        mainGridZeroStart(gridSize, numOfSlots, slotsDetails, mainGrid, slotNum, counter + 1, direction);
    }
    if (direction[slotNum] == 'V') // Vertical slot
    {
        mainGrid[row + counter][col] = '0';
        mainGridZeroStart(gridSize, numOfSlots, slotsDetails, mainGrid, slotNum, counter + 1, direction);
    }
}

void mainGridLadderStart(int gridSize, int row, int col, char mainGrid[gridSize][gridSize])
{
    // Initializes the main grid with '#' recursively row by row
    if (row >= gridSize)
        return;

    if (col >= gridSize)
    {
        mainGridLadderStart(gridSize, row + 1, 0, mainGrid);
        return;
    }

    mainGrid[row][col] = '#';
    mainGridLadderStart(gridSize, row, col + 1, mainGrid);
}

void getWordInput(int numOfWords, char dictionary[numOfWords][letterNum], int row, int col)
{
    // Recursively reads words into the dictionary character by character
    char input;
    scanf("%c", &input);
    if (input == '\n') // End of word
        return;

    dictionary[row][col] = input;
    getWordInput(numOfWords, dictionary, row, col + 1);
}

void makeItMinus(int rows, int cols, int arr[rows][cols], int currentRow, int currentCol)
{
    // Recursively initializes a 2D array with -1
    if (currentRow >= rows)
        return;

    if (currentCol >= cols)
    {
        makeItMinus(rows, cols, arr, currentRow + 1, 0);
        return;
    }

    arr[currentRow][currentCol] = -1;
    makeItMinus(rows, cols, arr, currentRow, currentCol + 1);
}

void makeItZero(int numOfWords, char dictionary[numOfWords][letterNum], int currentRow, int currentCol)
{
    // Recursively initializes the dictionary array with '0'
    if (currentRow >= numOfWords)
        return;

    if (currentCol >= letterNum)
    {
        makeItZero(numOfWords, dictionary, currentRow + 1, 0);
        return;
    }

    dictionary[currentRow][currentCol] = '0';
    makeItZero(numOfWords, dictionary, currentRow, currentCol + 1);
}
int slotIsEmpty(int arrSize, char arr[arrSize][arrSize], int row, int col, char direction)
{
    // Check if a slot is empty (contains only '0') in the specified direction
    if (row >= arrSize || col >= arrSize)
        return 0; // If out of bounds, return 0 (not empty)

    if (arr[row][col] == '#')
        return 0; // If the slot contains '#', it's not empty

    if (direction == 'H') // Check horizontally
    {
        if (arr[row][col] == '0')
            return 1; // If a cell contains '0', the slot is empty
        return slotIsEmpty(arrSize, arr, row, col + 1, direction); // Check the next cell
    }

    if (direction == 'V') // Check vertically
    {
        if (arr[row][col] == '0')
            return 1; // If a cell contains '0', the slot is empty
        return slotIsEmpty(arrSize, arr, row + 1, col, direction); // Check the next cell
    }

    return 1; // Default case: slot is empty
}

int haveMutualLetters(int gridSize, char direction, char grid[gridSize][gridSize], int curRow, int curCol,
                      int numOfWords, int wordRow, char dictionary[numOfWords][letterNum], int count)
{
    // Check if a word can fit into a slot with overlapping (mutual) letters
    if (direction == 'H') // Check horizontally
    {
        if (curCol + count >= gridSize || grid[curRow][curCol + count] == '#')
            return 1; // If out of bounds or '#' is reached, it's valid

        if (grid[curRow][curCol + count] != '0')
        {
            if (grid[curRow][curCol + count] == dictionary[wordRow][count])
                return haveMutualLetters(gridSize, direction, grid, curRow, curCol, numOfWords, wordRow, dictionary,
                    count + 1);
            return 0; // Conflict with existing letters
        }

        return haveMutualLetters(gridSize, direction, grid, curRow, curCol, numOfWords, wordRow, dictionary, count + 1);
    }

    if (direction == 'V') // Check vertically
    {
        if (curRow + count >= gridSize || grid[curRow + count][curCol] == '#')
            return 1; // If out of bounds or '#' is reached, it's valid

        if (grid[curRow + count][curCol] != '0')
        {
            if (grid[curRow + count][curCol] == dictionary[wordRow][count])
                return haveMutualLetters(gridSize, direction, grid, curRow, curCol, numOfWords, wordRow,
                    dictionary, count + 1);
            return 0; // Conflict with existing letters
        }

        return haveMutualLetters(gridSize, direction, grid, curRow, curCol, numOfWords, wordRow, dictionary, count + 1);
    }

    return 1; // Default case: valid overlap
}

int wordSizeCounter(int numOfWords, int wordRow, char dictionary[numOfWords][letterNum], int counter)
{
    // Count the size of a word in the dictionary
    if (dictionary[wordRow][counter] == '\0' || counter == letterNum)
        return counter; // Stop counting at the end of the word or limit
    return wordSizeCounter(numOfWords, wordRow, dictionary, counter + 1);
}

int isTheSameSize(int wordSize, int numOfSlots, int slotNum, int slotDetails[numOfDetails][numOfSlots])
{
    // Check if the word size matches the slot size
    return slotDetails[second][slotNum] == wordSize;
}

int wordIsUsed(int counter, int numOfSlots, int wordNum, int wordInSlot[numOfSlots])
{
    // Check if a word is already used in another slot
    if (counter >= numOfSlots)
        return 0; // If all slots are checked, return 0 (not used)

    if (wordInSlot[counter] == wordNum)
        return 1; // Word is already used

    return wordIsUsed(counter + 1, numOfSlots, wordNum, wordInSlot);
}

int canBeInserted(int gridSize, char direction, char grid[gridSize][gridSize], int curRow, int curCol,
                  int numOfWords, int wordRow, char dictionary[numOfWords][letterNum], int wordSize, int numOfSlots,
                  int slotNum, int slotDetails[numOfDetails][numOfSlots], int wordInSlot[numOfSlots])
{
    // Check if a word can be inserted into a slot
    if (isTheSameSize(wordSize, numOfSlots, slotNum, slotDetails) &&
        haveMutualLetters(gridSize, direction, grid, curRow, curCol, numOfWords, wordRow, dictionary, 0) &&
        !wordIsUsed(0, numOfSlots, wordRow, wordInSlot))
        return 1; // The word fits all criteria

    return 0; // The word cannot be inserted
}

void enterWordInSlot(int counter, int gridSize, char grid[gridSize][gridSize], int numOfSlots, int slotNum,
                     int slotDetails[numOfDetails][numOfSlots], char direction, int numOfWords, int wordRow,
                     char dictionary[numOfWords][letterNum], int wordInSlot[numOfSlots])
{
    // Insert a word into a slot in the grid
    int row = slotDetails[0][slotNum];          // Start row of the slot
    int col = slotDetails[addOne][slotNum];     // Start column of the slot

    if (direction == 'H') // Horizontal insertion
    {
        if (col + counter >= gridSize || grid[row][col + counter] == '#')
            return; // Stop if out of bounds or blocked

        if (grid[row][col + counter] == '0')
        {
            grid[row][col + counter] = dictionary[wordRow][counter]; // Place the letter
            wordInSlot[slotNum] = wordRow; // Mark the word as used
        }

        enterWordInSlot(counter + 1, gridSize, grid, numOfSlots, slotNum, slotDetails, direction, numOfWords, wordRow,
            dictionary, wordInSlot);
    }

    if (direction == 'V') // Vertical insertion
    {
        if (row + counter >= gridSize || grid[row + counter][col] == '#')
            return; // Stop if out of bounds or blocked

        if (grid[row + counter][col] == '0')
        {
            grid[row + counter][col] = dictionary[wordRow][counter]; // Place the letter
            wordInSlot[slotNum] = wordRow; // Mark the word as used
        }

        enterWordInSlot(counter + 1, gridSize, grid, numOfSlots, slotNum, slotDetails, direction, numOfWords, wordRow,
            dictionary, wordInSlot);
    }
}
void deleteWordFromSlot(int counter, int gridSize, char grid[gridSize][gridSize], int numOfSlots, int slotNum,
                        int slotDetails[numOfDetails][numOfSlots], char direction, int numOfWords, int wordRow,
                        char dictionary[numOfWords][letterNum], int wordInSlot[numOfSlots])
{
    // Function to delete a word from a slot in the grid
    int row = slotDetails[0][slotNum];          // Starting row of the slot
    int col = slotDetails[addOne][slotNum];     // Starting column of the slot

    if (direction == 'H') // Handle horizontal direction
    {
        if (col + counter >= gridSize || grid[row][col + counter] == '#')
            return; // Stop if out of bounds or '#' is encountered

        if (wordInSlot[col + counter] == slotNum)
        {
            // If the letter belongs to the current slot, reset it
            grid[row][col + counter] = '0';
            wordInSlot[slotNum] = -1; // Mark the slot as empty
        }

        // Recursively delete the next letter in the slot
        deleteWordFromSlot(counter + 1, gridSize, grid, numOfSlots, slotNum, slotDetails, direction, numOfWords,
            wordRow, dictionary, wordInSlot);
    }

    if (direction == 'V') // Handle vertical direction
    {
        if (row + counter >= gridSize || grid[row + counter][col] == '#')
            return; // Stop if out of bounds or '#' is encountered

        if (wordInSlot[row + counter] == slotNum)
        {
            // If the letter belongs to the current slot, reset it
            grid[row + counter][col] = '0';
            wordInSlot[slotNum] = -1; // Mark the slot as empty
        }

        // Recursively delete the next letter in the slot
        deleteWordFromSlot(counter + 1, gridSize, grid, numOfSlots, slotNum, slotDetails, direction, numOfWords,
            wordRow, dictionary, wordInSlot);
    }
}

int task5CrosswordGenerator(int gridSize, char mainGrid[gridSize][gridSize],
                            int numOfWords, int wordNum, char dictionary[numOfWords][letterNum], int numOfSlots,
                            int slotNum, char slotDirections[numOfSlots], int slotDetails[numOfDetails][numOfSlots],
                            int wordInSlot[numOfSlots])
{
    // Function to generate the crossword puzzle recursively
    if (slotNum >= numOfSlots)
        return 1; // Base case: all slots are filled

    if (wordNum >= numOfWords)
    {
        // If no more words are available, backtrack
        if (slotIsEmpty(gridSize, mainGrid, slotDetails[0][slotNum], slotDetails[addOne][slotNum],
            slotDirections[slotNum]))
        {
            // If the current slot is empty, backtrack to the previous slot
            if (slotNum == 0)
                return 0; // Cannot backtrack further

            int newWord = wordInSlot[slotNum - 1] + 1; // Try the next word for the previous slot
            deleteWordFromSlot(0, gridSize, mainGrid, numOfSlots, slotNum - 1, slotDetails,
                slotDirections[slotNum - 1],
                               numOfWords, wordInSlot[slotNum - 1], dictionary, wordInSlot);
            return task5CrosswordGenerator(gridSize, mainGrid, numOfWords, newWord, dictionary, numOfSlots,
                slotNum - 1, slotDirections, slotDetails, wordInSlot);
        }

        return 0; // If slot is not empty, fail to generate
    }

    int wordSize = wordSizeCounter(numOfWords, wordNum, dictionary, 0); // Get the size of the current word

    if (canBeInserted(gridSize, slotDirections[slotNum], mainGrid, slotDetails[0][slotNum],
        slotDetails[1][slotNum],
                      numOfWords, wordNum, dictionary, wordSize, numOfSlots, slotNum, slotDetails, wordInSlot))
    {
        // If the word can be inserted, place it in the slot
        enterWordInSlot(0, gridSize, mainGrid, numOfSlots, slotNum, slotDetails, slotDirections[slotNum],
            numOfWords,wordNum, dictionary, wordInSlot);

        // Move to the next slot
        return task5CrosswordGenerator(gridSize, mainGrid, numOfWords, 0, dictionary, numOfSlots, slotNum + 1,
            slotDirections, slotDetails, wordInSlot);
    }

    // Try the next word for the current slot
    return task5CrosswordGenerator(gridSize, mainGrid, numOfWords, wordNum + 1, dictionary, numOfSlots, slotNum,
        slotDirections, slotDetails, wordInSlot);
}

