#include <stdio.h>
int main()
{
    int processes, j, n, time, unfinished, flag = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0, at[10], bt[10], rt[10];
    printf("Enter Total Process:\t ");
    scanf("%d", &n);
    unfinished = n;
    for (processes = 0; processes < n; processes++)
    {
        printf("Enter Arrival Time and Burst Time for Process Process Number %d :", processes + 1);
        scanf("%d", &at[processes]);
        scanf("%d", &bt[processes]);
        rt[processes] = bt[processes];
    }
    printf("Enter Time Quantum:\t");
    scanf("%d", &time_quantum);
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for (time = 0, processes = 0; unfinished != 0;)
    {
        if (rt[processes] <= time_quantum && rt[processes] > 0)
        {
            time += rt[processes];
            rt[processes] = 0;
            flag = 1;
        }
        else if (rt[processes] > 0)
        {
            rt[processes] -= time_quantum;
            time += time_quantum;
        }
        if (rt[processes] == 0 && flag == 1)
        {
            unfinished--;
            printf("P[%d]\t|\t%d\t|\t%d\n", processes + 1, time - at[processes], time - at[processes] - bt[processes]);
            wait_time += time - at[processes] - bt[processes];
            turnaround_time += time - at[processes];
            flag = 0;
        }
        if (processes == n - 1)
            processes = 0;
        else if (at[processes + 1] <= time)
            processes++;
        else
            processes = 0;
    }
    printf("\nAverage Waiting Time= %f\n", wait_time * 1.0 / n);
    printf("Avg Turnaround Time = %f", turnaround_time * 1.0 / n);
    return 0;
}