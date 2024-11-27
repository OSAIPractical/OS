#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n = 4;  // Hardcoded number of processes
    int b[4] = {6, 2, 8, 3};  // Hardcoded burst times for the processes
    int p[4] = {3, 1, 4, 2};  // Hardcoded priorities for the processes
    int index[4] = {1, 2, 3, 4};  // Process IDs

    for (int i = 0; i < n; i++)
    {
        printf("Enter Burst Time and Priority Value for Process %d: %d %d\n", i + 1, b[i], p[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int a = p[i], m = i;

        for (int j = i; j < n; j++)
        {
            if (p[j] > a)
            {
                a = p[j];
                m = j;
            }
        }

        swap(&p[i], &p[m]);
        swap(&b[i], &b[m]);
        swap(&index[i], &index[m]);
    }

    int t = 0;

    printf("Order of process Execution is\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d is executed from %d to %d\n", index[i], t, t + b[i]);
        t += b[i];
    }

    printf("\n");
    printf("Process Id     Burst Time   Wait Time    TurnAround Time\n");
    int wait_time = 0;
    for (int i = 0; i < n; i++)
    {
        printf("P%d          %d          %d          %d\n", index[i], b[i], wait_time, wait_time + b[i]);
        wait_time += b[i];
    }

    return 0;
}
