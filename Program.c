#include<stdio.h>

int i,j,k,x;
int time;
int timeQuantum;
int no_of_process;
int arrivalTime[200];
int burstTime[200];
int waitingTime[200];
int turnAround[200];
int queue[200];
int remainingBurstTime[200];

void maintainingQueueAT();

void main()
{
    printf("Enter the no of Process : ");
    scanf("%d",&no_of_process);

    printf("Enter Burst Time of each Process \n");
    for(i=0;i<no_of_process;i++)
    {
        scanf("%d",&burstTime[i]);
        remainingBurstTime[i] = burstTime[i];
        waitingTime[i]=0;
        turnAround[i]=0;
    }

    printf("Enter Arrival Time of each Process \n");
    for(i=0;i<no_of_process;i++)
    {
        scanf("%d",&arrivalTime[i]);
    }

    time=0;

    timeQuantum = 6;
    maintainingQueueAT();
    for(i=0;i<no_of_process;i++)
    {
        x = queue[i];
        if(time < arrivalTime[x])
        {
            time = arrivalTime[x];
        }
        if(time >= arrivalTime[x] && remainingBurstTime[x]!=0)
        {
            waitingTime[x] +=  time - arrivalTime[x];
            if(remainingBurstTime[x] < timeQuantum)
            {
                time += remainingBurstTime[x];
                remainingBurstTime[x]=0;
            }
            else
            {
                time +=timeQuantum;
                remainingBurstTime[x] -= timeQuantum;
            }
            turnAround[x] = time;
        }
    }

    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for(i=0;i<no_of_process;i++)
    {
        printf("P[%d]\t|\t%d\t%d\n",i,turnAround[i]-arrivalTime[i],waitingTime[i]);
    }

    timeQuantum = 9;
    for(i=0;i<no_of_process;i++)
    {
        int x = queue[i];
        if(remainingBurstTime[x]!=0)
        {
            waitingTime[x] += time - turnAround[x];
            if(remainingBurstTime[x]<timeQuantum)
            {
                time += remainingBurstTime[x];
                remainingBurstTime[x]=0;
            }
            else
            {
                time +=timeQuantum;
                remainingBurstTime[x] -= timeQuantum;
            }
            turnAround[x] = time;
        }
    }
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for(i=0;i<no_of_process;i++)
    {
        printf("P[%d]\t|\t%d\t%d\n",i,turnAround[i]-arrivalTime[i],waitingTime[i]);
    }
}

void maintainingQueueAT()
{
    int copyArray[no_of_process];
    for(i=0;i<no_of_process;i++)
        {
            copyArray[i]=arrivalTime[i];
        }

    int min,k;
    k=0;
    for(i=0;i<no_of_process;i++)
    {
        min = 0;
        for(j=0;j<no_of_process;j++)
        {
            if(copyArray[j]<copyArray[min])
                min = j;
        }
        queue[k++] = min;
        copyArray[min] = MAX_VALUE;
    }
}


