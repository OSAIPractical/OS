#include<stdio.h>
#include<string.h>
#define max 30

int main()
{
    int i, j, n = 5;
    int bt[max] = {6, 8, 7, 3, 4};
    int wt[max], tat[max];
    float awt = 0, atat = 0;

    printf("Number of processes: %d\n", n);
    printf("Burst times of processes: ");
    for (i = 0; i < n; i++) {
        printf("%d ", bt[i]);
    }
    printf("\n");
    
    printf("process\t burst time\t  waiting time\t turn around time\n");
    
    for(i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        
        for(j = 0; j < i; j++)
        { 
            wt[i] = wt[i] + bt[j];
        }
        
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    awt = awt / n;
    atat = atat / n;

    printf("Average waiting time = %f\n", awt);
    printf("Average turnaround time = %f\n", atat);

    return 0;
}
