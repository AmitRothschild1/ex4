/******************
Name:
ID:
Assignment:
*******************/
#include <stdio.h>
#include <string.h>

int task1RobotPaths(int,int);
float task2HumanPyramid();
int task3ParenthesisValidator();
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
                task3ParenthesisValidator();
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
        return 1;
    if (currentCol >= size)
        return 0;
    return rowIsEmpty(size,xRow,currentCol+1,queensArr);
}

int theFuckingThing(int size,char arr[size][size],int currentRow,int currentCol ,char queensArr[size][size])
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
           return theFuckingThing(size,arr,currentRow-1,newCol,queensArr);
       }
        if(!rowIsEmpty(size,currentRow,0,queensArr))
           return theFuckingThing(size,arr,currentRow+1,currentCol,queensArr);
    }
    //
    if(properQueenPlace(size,arr,0,0,queensArr,currentRow,currentCol))
    {
        queensArr[currentRow][currentCol] = 'X';
        return theFuckingThing(size,arr,currentRow+1,0 ,queensArr);
    }
    //
      return theFuckingThing(size,arr,currentRow,currentCol+1,queensArr);
}

void task4QueensBattle()
{
    // Todo
}

void task5CrosswordGenerator()
{
    // Todo
}
