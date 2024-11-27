#include<stdio.h>

int main()
{
    int bt[20] = {6, 8, 7, 3, 4};
    int p[20] = {1, 2, 3, 4, 5};
    int wt[20], tat[20], i, j, n = 5, total = 0, totalT = 0, pos, temp;
    float avg_wt, avg_tat;

    printf("Number of processes: %d\n", n);
    printf("Burst times of processes: ");
    for (i = 0; i < n; i++) {
        printf("%d ", bt[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (bt[j] < bt[pos])
                pos = j;
        }

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;

    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
        total += wt[i];
    }

    avg_wt = (float)total / n;

    printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        totalT += tat[i];
        printf("\np%d\t\t %d\t\t %d\t\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    avg_tat = (float)totalT / n;
    printf("\n\nAverage Waiting Time = %f", avg_wt);
    printf("\nAverage Turnaround Time = %f", avg_tat);

    return 0;
}
