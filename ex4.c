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

int task3ParenthesisValidator()
{
    // Todo
}

void task4QueensBattle()
{
    // Todo
}

void task5CrosswordGenerator()
{
    // Todo
}
