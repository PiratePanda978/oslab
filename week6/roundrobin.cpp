#include<iostream>
using namespace std;
int main()
{
    int processes, j, n, time, unfinished, flag = 0, quantum,wt,tat;
    int wait_time = 0, turnaround_time = 0, at[10], bt[10], rt[10];
    cout << "Enter Number of Process : ";
    cin >> n;
    unfinished = n;
    for (processes = 0; processes < n; processes++)
    {
        cout << "Enter Arrival Time for Process[" << processes + 1 << "] : ";
        cin >> at[processes];
        cout << "Enter Burst Time for Process[" << processes + 1 << "] : ";
        cin >> bt[processes];
        rt[processes] = bt[processes];
    }
    cout << "Enter Time Quantum : ";
    cin >> quantum;
    cout << "\n\nProcess\tTurnaround Time\tWaiting Time\n\n";
    for (time = 0, processes = 0; unfinished != 0;)
    {
        if (rt[processes] <= quantum && rt[processes] > 0)
        {
            time += rt[processes];
            rt[processes] = 0;
            flag = 1;
        }
        else if (rt[processes] > 0)
        {
            rt[processes] -= quantum;
            time += quantum;
        }
        if (rt[processes] == 0 && flag == 1)
        {
            unfinished--;
            wt = time - at[processes] - bt[processes];
            if(wt<0)
            wt=0;
            tat = time-at[processes];
            cout << "P[" << processes+1 << "]" << "\t\t" << tat << "\t\t" << wt << endl;
            wait_time += wt;
            turnaround_time += tat;
            flag = 0;
        }
        if (processes == n - 1)
            processes = 0;
        else if (at[processes + 1] <= time)
            processes++;
        else
            processes = 0;
    }
    cout << "\nAverage Waiting Time = " << (wait_time * 1.0 / n) << endl;
    cout << "Avg Turnaround Time = " << (turnaround_time * 1.0 / n) << endl;
    return 0;
}