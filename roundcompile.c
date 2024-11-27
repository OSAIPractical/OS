#include<stdio.h>

#define max 30

int main()
{
    int i, n = 4, qt = 4, count = 0, temp, a = 0;
    int bt[max] = {6, 8, 7, 3};  // Hardcoded burst times for the processes
    int wt[max], tat[max], rem_bt[max];
    float awt = 0, atat = 0;

    for(i = 0; i < n; i++)
    {
        rem_bt[i] = bt[i];
    }

    while(1)
    {
        for(i = 0, count = 0; i < n; i++)
        {
            temp = qt;
            if(rem_bt[i] == 0)
            {
                count++;
                continue;
            }
            if(rem_bt[i] > qt)
                rem_bt[i] = rem_bt[i] - qt;
            else 
                if(rem_bt[i] >= 0)
                {
                    temp = rem_bt[i];
                    rem_bt[i] = 0;
                }
            a = a + temp;
            tat[i] = a;
        }
        if(n == count)
            break;
    }

    printf("Process\t Burst Time\t Waiting Time\t Turnaround Time\n");
    for(i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t %d\t\t %d\t\t %d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    awt = awt / n;
    atat = atat / n;
    printf("Average Waiting Time = %f\n", awt);
    printf("Average Turnaround Time = %f\n", atat);

    return 0;
}
