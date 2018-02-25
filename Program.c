#include<stdio.h>

int i;
int timeQuantum;
int no_of_process;
int arrivalTime[200];
int burstTime[200];
int waitingTime[200];
int turnAround[200];
void main()
{
    printf("Enter the no of Process : ");
    scanf("%d",&no_of_process);

    printf("Enter Burst Time of each Process \n");
    for(i=0;i<no_of_process;i++)
    {
        scanf("%d",&burstTime[i]);
        remainingBurstTime[i] = burstTime[i];

    }
    printf("Enter Arrival Time of each Process \n");
    for(i=0;i<no_of_process;i++)
    {
        scanf("%d",&arrivalTime[i]);
    }

}
