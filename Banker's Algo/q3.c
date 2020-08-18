#include<stdio.h>

const int P = 5; // Number of process
const int R = 3; // Number of resources

void NeedMatrix(int need[P][R], int max[P][R], int allot[P][R]) {
   int i,j; // fill the need matrix
    for ( i = 0 ; i < P ; i++)
        for ( j = 0 ; j < R ; j++)
            need[i][j] = max[i][j] - allot[i][j];
}

int main()
{
    int processes[] = {0, 1, 2, 3, 4};  //No. of Processes
    int avail[] = {3, 3, 2};            //Initially available resources
    int max[5][3] = {{7, 5, 3},         //Max Resource Need for all processes
                     {3, 2, 2},
                     {9, 0, 2},
                     {2, 2, 2},
                     {4, 3, 3}};
                  
    int Allocation[][3] = {{0, 1, 0},   //Initially Allocated Resources
                          {2, 0, 0},
                          {3, 0, 2},
                         {2, 1, 1},
                         {0, 0, 2}};
    int need[P][R];
    NeedMatrix(need, max, Allocation);  //Calculation of need matrix for applying banker's algorithm
    int completion[5] = {0};
    int Sequence[P];
    int available[R];
    int i,p,k;
    for (i = 0; i < R ; i++)
        available[i] = avail[i];
    int count = 0;
    while (count < P)
    {
      
        int found = 0;
        for (p = 0; p < P; p++)
        {
            if (completion[p] == 0)
            {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > available[j]) //check the condition
                        break;
                if (j == R)
                {
                    for (k = 0 ; k < R ; k++)
                        available[k] += Allocation[p][k];
                        //Available = Available + Allocation
                        //Freeing up resources after execution
                        Sequence[count++] = p;
                        completion[p] = 1;
                        found = 1;
                }
            }
        }
        if (found == 0)
        {
            printf("System is not in safe state");
            return 0;
        }
    }
    //1 Flag for process implies process completed
    //0 Flag for process implies process incomplete
    //for (i = 0; i < P ; i++)
       //printf("P%d - %d ",i,completion[i]);
    //printf("\n");

    printf("System is in safe state.\n");
    printf("Safe sequence is: ");
    
    for (i = 0; i < P ; i++)
        printf("P%d ",Sequence[i]);
    printf("\n");
    return 0;
}