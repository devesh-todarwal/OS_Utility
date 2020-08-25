#include <pthread.h>
#include <stdio.h>
#include <math.h>

//Declaring Global variables

double avg=0, medValue=0, sdValue=0;
int minValue=0, maxValue=0;

int len;

/* Function to calculate average of the values in the given array */

void *calcAvg(void *arg)
{
    int i = 0, sum = 0;
    int *values;

    //Fetching array
    values = (int*)arg;

    //Iterating over array
    for(i=0; i<len; i++)
    {
        //Accumulating sum
        sum = sum + values[i];
    }

    //Calculating average
    avg = sum / (double)len;

    return NULL;
}

/* Function to calculate minimum value in the given array */


void *calcMin(void *arg)
{
    int i = 0;
    int *values;

    //Fetching array
    values = (int*)arg;

    //Initializing minimum value as starting element
    minValue = values[0];

    //Iterating over array
    for(i=0; i<len; i++)
    {
        //Comparing value
        if(values[i] < minValue)  
        {
            //Updating minimum value
            minValue = values[i];
        }
    }

    return NULL;
}

/* Function to calculate maximum value in the given array */
void *calcMax(void *arg)
{
    int i = 0;
    int *values;

    //Fetching array
    values = (int*)arg;

    //Initializing maximum value as starting element
    maxValue = values[0];

    //Iterating over array
    for(i=0; i<len; i++)
    {
        //Comparing value
        if(values[i] > maxValue)  
        {
            //Updating maximum value
            maxValue = values[i];
        }
    }

    return NULL;
}

/* Function to calculate median value in the given array */
void *calcMed(void *arg)
{
    int i = 0, j = 0;
    int *values;
    int temp;
    //Fetching array
    values = (int*)arg;
    
    // First we sort the array 
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < (len - i - 1); j++)
        {
            if (values[j] > values[j + 1])
            {
                temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
    // check for even case 
    if (len % 2 != 0) {
        medValue=(double)values[len/2];
    }
    else{ 
        medValue=(double)(values[(len-1)/2] + values[len/2])/2.0; 
    }
    return NULL;
}

/* Function to calculate standard deviation value in the given array */
void *calcSD(void *arg) 
{
    int i = 0, j = 0;
    int *values;
    int sum1=0;
    double sd2=0;
        
    //Fetching array
    values = (int*)arg;

    for(i=0; i<len; i++)
    {
        //Accumulating sum
        sum1 = sum1 + values[i];
    }

    //Calculating average
    average = sum1 / (double)len;

    //calculating SD
    for (i = 0; i < len; ++i)
        sd2 += pow(values[i] - avg, 2);
    
    sdValue=sqrt(sd2 /len);

    return NULL;
}

/* Main function */
int main(void)
{
    //Thread identifiers
    pthread_t avgPth, minPth, maxPth, medPth, sdPth;  
    int i, values[100];

    scanf("%d", &len);
    for (i = 0; i < len; ++i)
    scanf("%d", &values[i]);

    //Creating five threads one for each operation

    pthread_create(&avgPth,NULL,calcAvg, values);
    pthread_create(&minPth,NULL,calcMin, values);
    pthread_create(&maxPth,NULL,calcMax, values);
    pthread_create(&medPth,NULL,calcMed, values);
    pthread_create(&sdPth,NULL,calcSD, values);
  
    //Waiting till all threads finish their work

    pthread_join(avgPth,NULL);
    pthread_join(minPth,NULL);
    pthread_join(maxPth,NULL);
    pthread_join(medPth,NULL);
    pthread_join(sdPth,NULL);
  
    //Printing results

    printf("\nAverage : %f", avg);
    printf("\nMinimum : %d", minValue);
    printf("\nMaximum : %d", maxValue);
    printf("\nMedian : %f", medValue);
    printf("\nStandard Deviation : %f\n", sdValue);
    printf("The number numbers entered = %d", len);

    return 0;
}