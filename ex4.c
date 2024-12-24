/******************
Name: Amit Rothschild
ID: 322317637
Assignment: EX4
*******************/
#include <stdio.h>
#include <string.h>

int task1RobotPaths(int,int);
float task2HumanPyramid(int,int,float[5][9]);
int task3ParenthesisValidator(char);
void task4QueensBattle();
void task5CrosswordGenerator();

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
                int column , row;
                printf("Please enter the coordinates of the robot (column, row):\n");
                scanf("%d %d",&column,&row);
                printf("The total number of paths the robot can take to reach home is: %d\n",task1RobotPaths(column,row));
                break;
            case 2:
                float arr[5][9]={0};
                //scanf("%f", &
                arr[4][4]=51.18;
                // scanf("%f %f", &
                arr[3][3]=55.90;
                arr[3][5]=131.25;
                //scanf("%f %f %f", &
                arr[2][2]=69.05;
                arr[2][4]=133.66;
                arr[2][6]=132.82;
                //scanf("%f %f %f %f", &
                arr[1][1]=53.43;
                arr[1][3]=139.61;
                arr[1][5]=134.06;
                arr[1][7]=121.63;
                //scanf("%f %f %f %f %f", &
                arr[0][0]=72.31;
                arr[0][2]=108.62;
                arr[0][4]=171.24;
                arr[0][6]=151.33;
                arr[0][8]=93.32;
                for(int i=4;i>-1;i--)
                {
                    for(int j=i;j<9;j++)
                    {
                        if(j%2 != i%2)
                        j++;
                       if (j+i <= 8)
                           printf("%.2f ",task2HumanPyramid(j,i,arr));
                    }
                    printf("\n");
                }
                break;
            case 3:
                char c;
                scanf("%c",&c);
                task3ParenthesisValidator(c);
                break;
            case 4:
                task4QueensBattle();
                break;
            case 5:
                task5CrosswordGenerator();
                break;
            default:
                printf("Please choose a task number from the list.\n");
                break;
            }
        }
        else
        {
            scanf("%*s");
        }

    } while (task != 6);
}

int task1RobotPaths(int col ,int row)
{
    // Todo
    if(col == 0 && row == 0)
        return 1;
    if(col < 0 || row < 0)
        return 0;
    return task1RobotPaths(col - 1,row) + task1RobotPaths(col,row - 1);
}

float task2HumanPyramid(int col ,int row,float arr[5][9])
{
    // Todo
    if(col-row < 0 || col+row > 8)
        return 0;
    return task2HumanPyramid(col+1,row+1,arr)/2 + task2HumanPyramid(col-1,row+1,arr)/2 + arr[row][col];
}

char getpernatesis(char c) {
    switch (c) {
    case '(': return c;
    case ')': return ')';
    case '[': return '[';
    case ']': return ']';
    case '<': return '<';
    case '>': return '>';
    case '{': return '{';
    case '}': return '}';
    case '\n': return '\n';
    default: return 0;
    }
}
char getopositesis(char c) {
    switch (c) {
    case '(': return ')';
    case '[': return ']';
    case '<': return '>';
    case '{': return '}';
    default: return 0;
    }
}

int task3ParenthesisValidator(char open)
{
    // Todo
    char current;
    if (scanf("%c", &current) != 1 || current == '\n') {
        if (open != '\0') {
            return 1;
        }
        return 0;
    }
    if (getpernatesis(current) == 0) {
        return task3ParenthesisValidator(open);
    }
    if (current == '(' || current == '[' || current == '{' || current == '<') {
        if (task3ParenthesisValidator(current) == 1) {
            return 1;
        }
        return task3ParenthesisValidator(open);
    }

    if (current == ')' || current == ']' || current == '}' || current == '>') {
        if (open == '\0' || getopositesis(open) != current) {
            return 1;
        }
        return 0;
    }
    return 1;
}


int colorIsOccupied(int size,char arr[size][size],int currentRow,int currentCol ,char queensArr[size][size],int xRow,int xCol)
{
    if (currentRow >= xRow)
        return 0;
    if(arr[currentRow][currentCol] == arr[xRow][xCol] && queensArr[currentRow][currentCol] == 'X')
        return 1;
    if(currentCol >= size-1)
     return colorIsOccupied(size,arr,currentRow+1,0,queensArr,xRow,xCol);
    return colorIsOccupied(size, arr, currentRow, currentCol + 1, queensArr, xRow, xCol);
}

int columnIsOccupied(int size,int currentRow,char queensArr[size][size],int xRow,int xCol)
{
    if (currentRow >= xRow)
        return 0;
    if(queensArr[currentRow][xCol] == 'X')
        return 1;
    return columnIsOccupied(size,currentRow+1,queensArr,xRow, xCol);
}

int isLinkedTo(int size,char queensArr[size][size],int xRow,int xCol)
{
    if(xRow == 0)
        return 0;
    if(queensArr[xRow-1][xCol-1] == 'X' || queensArr[xRow-1][xCol] == 'X' || queensArr[xRow-1][xCol+1] == 'X')
        return 1;
    return 0;
}

int properQueenPlace(int size,char arr[size][size],int currentRow,int currentCol ,char queensArr[size][size],int xRow,int xCol)
{
    if(isLinkedTo(size,queensArr,xRow,xCol) || colorIsOccupied(size,arr,currentRow,currentCol,queensArr,xRow,xCol) || columnIsOccupied(size,currentRow,queensArr,xRow,xCol))
        return 0;
    return 1;
}

int queenColumn(int size,int xRow,int currentCol ,char queensArr[size][size])
{
    if (queensArr[xRow-1][currentCol] == 'X')
        return currentCol+1;
      return queenColumn(size,xRow,currentCol+1,queensArr);
}

int rowIsEmpty(int size,int xRow,int currentCol,char queensArr[size][size])
{
    if (queensArr[xRow][currentCol] == 'X')
        return 0;
    if (currentCol >= size)
        return 1;
    return rowIsEmpty(size,xRow,currentCol+1,queensArr);
}

int task4QueensBattle(int size,char arr[size][size],int currentRow,int currentCol ,char queensArr[size][size])
{
    if (currentRow >= size)
        return 1;
    //
    if(currentCol>=size)
    {
        if(currentRow == 0 && rowIsEmpty(size,currentRow,0,queensArr))
            return 0;
       if(rowIsEmpty(size,currentRow,0,queensArr))
       {
           int newCol = queenColumn(size, currentRow, 0, queensArr);
           queensArr[currentRow-1][newCol-1] = '*';
           return task4QueensBattle(size,arr,currentRow-1,newCol,queensArr);
       }
        if(!rowIsEmpty(size,currentRow,0,queensArr))
           return task4QueensBattle(size,arr,currentRow+1,currentCol,queensArr);
    }
    //
    if(properQueenPlace(size,arr,0,0,queensArr,currentRow,currentCol))
    {
        queensArr[currentRow][currentCol] = 'X';
        return task4QueensBattle(size,arr,currentRow+1,0 ,queensArr);
    }
    //
      return task4QueensBattle(size,arr,currentRow,currentCol+1,queensArr);
}

/*--------------------------------------------------------------------------------------------------------------------*/

void makeItMinus(int size,int arr[size][size],int currentRow,int currentCol)
{
    if (currentRow >= size)
        return;
    if(currentCol >= size)
    {
        makeItMinus(size,arr,currentRow+1,0);
        return;
    }
    arr[currentRow][currentCol] = -1;
    makeItMinus(size,arr,currentRow,currentCol+1);
}


int slotIsEmpty(int arrSize,char arr[arrSize][arrSize],int row,int col,char direction)
{
    if (row >= arrSize || col >= arrSize)
        return 0;
    if(arr[row][col]== '#')
        return 0; //הבעיה שאם גלשו לשם אותיות נוספות שמכסות את כל הסלוט זה יצא תקין למרות שהמילה שם לא מהמילון, מה שכן לדעתי זה יסתדר עם התנאים הנוספים
    if (direction == 'H')
    {
        if (arr[row][col] == '0')
            return 1;
        return slotIsEmpty(arrSize,arr,row,col+1,direction);
    }
    if (direction == 'V')
    {
        if (arr[row][col] == '0')
            return 1;
        return slotIsEmpty(arrSize,arr,row+1,col,direction);
    }
    return 1;
}

int haveMutualLetters(int gridSize,char direction,char grid[gridSize][gridSize],int curRow,int curCol
    ,int numOfWords,int wordRow,char dictionary[numOfWords][15],int count)
{
    if(direction == 'H')
    {
        if (curCol+count >= gridSize || grid[curRow][curCol+count] == '#')
            return 1;
        if (grid[curRow][curCol+count] != '0')
        {
            if (grid[curRow][curCol+count] == dictionary[wordRow][count])
                return haveMutualLetters(gridSize,direction,grid,curRow,curCol,numOfWords,wordRow,dictionary,count+1);
            if (grid[curRow][curCol+count] != dictionary[wordRow][count])
                return 0;
        }
        return haveMutualLetters(gridSize,direction,grid,curRow,curCol,numOfWords,wordRow,dictionary,count+1);
    }
    if(direction == 'V')
    {
        if (curRow+count >= gridSize || grid[curRow+count][curCol] == '#')
            return 1;
        if (grid[curRow+count][curCol] != '0')
        {
            if (grid[curRow+count][curCol] == dictionary[wordRow][count])
                return haveMutualLetters(gridSize,direction,grid,curRow,curCol,numOfWords,wordRow,dictionary,count+1);
            if (grid[curRow+count][curCol] != dictionary[wordRow][count])
            {
                printf("dictionary bad letter - %c | grid bad letter - %c\n",dictionary[wordRow][curCol],grid[curRow][curCol]);
                return 0;
            }
        }
        return haveMutualLetters(gridSize,direction,grid,curRow,curCol,numOfWords,wordRow,dictionary,count+1);
    }
    return 1;
}

int wordSizeCounter(int numOfWords,int wordRow,char dictionary[numOfWords][15],int counter)
{
    if(dictionary[wordRow][counter] == '0' || counter == 15)
        return counter;
    return wordSizeCounter(numOfWords,wordRow,dictionary,counter+1);
}

int isTheSameSize(int wordSize,int numOfSlots,int slotNum,int slotDetails[3][numOfSlots])
{
    if(slotDetails[2][slotNum]==wordSize)
        return 1;
    return 0;
}

int wordIsUsed(int counter,int numOfSlots,int wordNum,int wordInSlot[numOfSlots])
{
    if(counter >= numOfSlots)
        return 0;
    if(wordInSlot[counter]==wordNum)
        return 1;
    return wordIsUsed(counter+1,numOfSlots,wordNum,wordInSlot);
}


int canBeInserted(int gridSize,char direction,char grid[gridSize][gridSize],int curRow,int curCol,int numOfWords,
    int wordRow,char dictionary[numOfWords][15],int wordSize,int numOfSlots,int slotNum,int slotDetails[3][numOfSlots],
    int wordInSlot[numOfSlots])
{
    if(!isTheSameSize(wordSize,numOfSlots,slotNum,slotDetails))
printf("Not the same size\n");//**********************************************************************************************
    if(!haveMutualLetters(gridSize,direction,grid,curRow,curCol,numOfWords,wordRow,dictionary,0))
        printf("Not the same letters\n");//************************************************************************************
    if (wordIsUsed(0,numOfSlots,wordRow,wordInSlot))
        printf("Word is used\n");//*****************************************************************************************
    if(isTheSameSize(wordSize,numOfSlots,slotNum,slotDetails)&&
        haveMutualLetters(gridSize,direction,grid,curRow,curCol,numOfWords,wordRow,dictionary,0)&&
        !wordIsUsed(0,numOfSlots,wordRow,wordInSlot))
        return 1;
    return 0;
}

void enterWordInSlot(int counter,int gridSize,char grid[gridSize][gridSize],int numOfSlots,int slotNum,
    int slotDetails[3][numOfSlots],char direction,int numOfWords,int wordRow,char dictionary[numOfWords][15],
    int slotGrid[gridSize][gridSize],int wordInSlot[numOfSlots])
{
    int row = slotDetails[0][slotNum];
    int col = slotDetails[1][slotNum];
    if(direction == 'H')
    {
        if (col+counter >= gridSize ||
        grid[row][col+counter] == '#')
            return;
        if (grid[row][col+counter] == '0')
        {
            grid[row][col+counter] = dictionary[wordRow][counter];
            printf("entered - now its %c\n ",grid[row][col+counter]);//*********************************************
            slotGrid[row][col+counter] = slotNum;
            wordInSlot[slotNum] = wordRow;
        }
        enterWordInSlot(counter+1,gridSize,grid,numOfSlots,slotNum,slotDetails,direction,numOfWords,wordRow,dictionary,slotGrid,wordInSlot);
    }
    if(direction == 'V')
    {
        if (row+counter >= gridSize ||
        grid[row+counter][col] == '#')
            return;
        if(grid[row+counter][col] == '0')
        {
            grid[row+counter][col] = dictionary[wordRow][counter];
            printf("entered - now its %c\n ",grid[row+counter][col]);//*********************************************

            slotGrid[row+counter][col] = slotNum;
            wordInSlot[slotNum] = wordRow;
        }
        enterWordInSlot(counter+1,gridSize,grid,numOfSlots,slotNum,slotDetails,direction,numOfWords,wordRow,dictionary,slotGrid,wordInSlot);
    }
}

void deleteWordFromSlot(int counter,int gridSize,char grid[gridSize][gridSize],int numOfSlots,int slotNum,
    int slotDetails[3][numOfSlots],char direction,int numOfWords,int wordRow,char dictionary[numOfWords][15],
    int slotGrid[gridSize][gridSize],int wordInSlot[numOfSlots])
{
    printf("we arrived to the delete part\n");//*************************************************************************888
    int row = slotDetails[0][slotNum];
    int col = slotDetails[1][slotNum];
    if(direction == 'H')
    {
        if (col+counter >= gridSize ||
        grid[row][col+counter] == '#')
            return;
        if(slotGrid[row][col+counter] == slotNum)
        {
            //letter doesnt belong to other slot
            grid[row][col+counter] = '0';
            slotGrid[row][col+counter] = -1;
            printf("delete - now its %c\n ",grid[row][col+counter]);//***********************************************
            wordInSlot[slotNum] = -1;
        }
        deleteWordFromSlot(counter+1,gridSize,grid,numOfSlots,slotNum,slotDetails,direction,numOfWords,wordRow,dictionary,slotGrid,wordInSlot);
    }
    if(direction == 'V')
    {
        if (row+counter >= gridSize ||
        grid[row+counter][col] == '#')
            return;
        if(slotGrid[row+counter][col] == slotNum)//letter doesnt belong to other slot
        {
            grid[row+counter][col] = '0';
            slotGrid[row+counter][col] = -1;
            printf("delete - now its %c\n ",grid[row+counter][col]);//***********************************************
            wordInSlot[slotNum] = -1;
        }
        deleteWordFromSlot(counter+1,gridSize,grid,numOfSlots,slotNum,slotDetails,direction,numOfWords,
            wordRow,dictionary,slotGrid,wordInSlot);
    }
}


int task5CrosswordGenerator(int gridSize, char mainGrid[gridSize][gridSize], int slotGrid[gridSize][gridSize],
                            int numOfWords, int wordNum, char dictionary[numOfWords][15], int numOfSlots,
                            int slotNum, char slotDirections[numOfSlots], int slotDetails[3][numOfSlots],
                            int wordInSlot[numOfSlots])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            printf("| %c ",mainGrid[i][j]);
        printf("|\n");
    }
    printf("\n\n");
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            printf("| %d ",slotGrid[i][j]);
        printf("|\n");
    }
    printf("Debug: slotNum=%d, wordNum=%d\n", slotNum, wordNum);

    // תנאי עצירה: כל הסלוטים מלאים
    if (slotNum >= numOfSlots)
        return 1;

    // אם כל המילים נבדקו ואין התאמה
    if (wordNum >= numOfWords)
    {
        printf("No more words to check for slotNum=%d\n", slotNum);//********************************************************

        // בדיקת מילוי חלקי וגלישה אחורה
        if (slotIsEmpty(gridSize, mainGrid, slotDetails[0][slotNum], slotDetails[1][slotNum], slotDirections[slotNum]))
        {
            printf("Slot is empty for slotNum=%d. Backtracking...\n", slotNum);//************************************************

            if (slotNum == 0)
            {
                printf("Backtracking failed. Cannot go back further.\n");//********************************************************

                return 0; // לא ניתן לגלוש אחורה יותר
            }

            // מחיקת מילה מהסלוט הקודם ונסיון מילוי מחדש
            int newWord = wordInSlot[slotNum-1]+1;
            deleteWordFromSlot(0, gridSize, mainGrid, numOfSlots, slotNum - 1, slotDetails, slotDirections[slotNum - 1],
                               numOfWords, wordInSlot[slotNum - 1], dictionary, slotGrid, wordInSlot);
            return task5CrosswordGenerator(gridSize, mainGrid, slotGrid, numOfWords, newWord,
                                           dictionary, numOfSlots, slotNum - 1, slotDirections, slotDetails, wordInSlot);
        }
        return 0; // לא נמצאה התאמה
    }
    // חישוב גודל המילה הנוכחית
    int wordSize = wordSizeCounter(numOfWords, wordNum, dictionary, 0);
    printf("Trying word '%s' (size=%d) in slotNum=%d\n", dictionary[wordNum], wordSize, slotNum);//**********************************************

    // בדיקת אפשרות להכניס את המילה לסלוט
    if (canBeInserted(gridSize, slotDirections[slotNum], mainGrid, slotDetails[0][slotNum], slotDetails[1][slotNum],
                      numOfWords, wordNum, dictionary, wordSize, numOfSlots, slotNum, slotDetails, wordInSlot))
    {
        printf("Word '%s' fits in slotNum=%d. Inserting...\n", dictionary[wordNum], slotNum);//***************************************************88

        // הכנסת המילה
        enterWordInSlot(0, gridSize, mainGrid, numOfSlots, slotNum, slotDetails, slotDirections[slotNum], numOfWords,
                        wordNum, dictionary, slotGrid, wordInSlot);

        // מעבר לסלוט הבא
        return task5CrosswordGenerator(gridSize, mainGrid, slotGrid, numOfWords, 0, dictionary, numOfSlots, slotNum + 1,
                                       slotDirections, slotDetails, wordInSlot);
    }
    printf("Word '%s' does not fit in slotNum=%d. Trying next word...\n", dictionary[wordNum], slotNum);//******************************************


    // ניסיון עם המילה הבאה
    return task5CrosswordGenerator(gridSize, mainGrid, slotGrid, numOfWords, wordNum + 1, dictionary, numOfSlots,
                                   slotNum, slotDirections, slotDetails, wordInSlot);
}

