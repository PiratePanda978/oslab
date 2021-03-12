#include <iostream>
using namespace std;

//Waiting Time different arrival time
void waitingTime(int p[],int n,int bt[],int wt[],int at[]){
    int i;
    int prev_tt[n];
    prev_tt[0] = 0;
    wt[0] = 0;
    cout << endl;
    cout << "Waiting Time" << endl;
    for(i=1;i<n;i++){
        prev_tt[i] = prev_tt[i-1]+bt[i-1];
        wt[i] = prev_tt[i] - at[i];
        cout << wt[i] << endl;
        if(wt[i]<0)
        wt[i]=0;
    }
}

//waiting time same arrival time
void waitingTime(int p[],int n,int bt[],int wt[]){
    wt[0] = 0;
    int i;
    for(i=1;i<n;i++){
        wt[i] = bt[i-1]+wt[i-1];
    }
}

//Turn Around Time
void turnAroundTime(int p[],int n,int bt[],int wt[],int tat[]){
    int i;
    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
    }
}

//average time for different arrival times
void findavgTime(int processes[], int n, int bt[], int at[])
{
    int wt[n], tat[n];
    int ttat=0,twt=0;
    int completion_time;
    int i;

    waitingTime(processes, n, bt, wt, at);

    turnAroundTime(processes, n, bt, wt, tat);
    cout << endl;
    for(i=0;i<n;i++){
        twt = twt + wt[i];
        ttat = ttat + tat[i];
        completion_time = tat[i] + at[i];
        cout << "Completion time for process " << i+1 << " is : " << completion_time << endl;
    }

    cout << "\nTotal waiting Time : " << twt << endl;
    cout << "Total Turn Around Time : " << ttat << endl;
    cout << "Average waiting time : " << (double)twt/(double)n << endl;
    cout << "Average Turn Around Time : " << (double)ttat/(double)n << endl;
}

//Average time for same arrival times
void findavgTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n];
    int twt=0,ttat=0;
    int i;

    waitingTime(processes, n, bt, wt);

    turnAroundTime(processes, n, bt, wt, tat);
    cout << endl;
    for(i=0;i<n;i++){
        twt = twt+wt[i];
        ttat = ttat+tat[i];
        cout << "Completion time for process " << i+1 << " is : " << tat[i] << endl;
    }

    cout << "\nTotal waiting Time : " << twt << endl;
    cout << "Total Turn Around Time : " << ttat << endl;
    cout << "Average waiting time : " << (double)twt/(double)n << endl;
    cout << "Average Turn Around Time : " << (double)ttat/(double)n << endl;
}

int main()
{
    int i,n,a;
    cout << "Enter the number of processes : ";
    cin >> n;
    int processes[n];
    int burst_time[n];
    int arrival_time[n];
    cout << "Same or different arrival times ?? (0/1) : ";
    cin >> a;
    switch (a)
    {
    case 0:
    for(i=0;i<n;i++){
        processes[i] = i+1;
        cout << "Enter the cpu burst time of process " << i+1 << " : ";
        cin >> burst_time[i];
    }
    findavgTime(processes, n, burst_time);
    break;
    case 1:
    for(i=0;i<n;i++){
        processes[i] = i+1;
        cout << "Enter the cpu burst time of process " << i+1 << " : ";
        cin >> burst_time[i];
        cout << "Enter the arrival time of process "<< i+1 << " : ";
        cin >> arrival_time[i];
    }
    findavgTime(processes, n, burst_time, arrival_time);
    break;
    default:
        break;
    }
    return 0;
}