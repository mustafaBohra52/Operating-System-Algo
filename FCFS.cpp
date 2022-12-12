#include<iostream>
using namespace std;
int main()
{   int n,i,j;
    float avgwt=0,avgtat=0;
    cout<<"Enter total number of processes:";
    cin>>n;
    int bt[n],wt[n],tat[n];

    cout<<"\nEnter Process Burst Time  \n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>bt[i];
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        //wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
    cout << "\n Arrival Time does not required because processes come into the sequence !!";
    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";

    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avgwt+=wt[i];
        avgtat+=tat[i];
        cout<<"\nP["<<i+1<<"]"<< "\t\t" <<bt[i]<< "\t\t" <<wt[i]<< "\t\t" <<tat[i];
    }

    avgwt = avgwt/i;
    avgtat = avgtat/i;

    cout<<"\n\nAverage Waiting Time:"<<avgwt;
    cout<<"\nAverage Turnaround Time:"<<avgtat;

    return 0;
}
