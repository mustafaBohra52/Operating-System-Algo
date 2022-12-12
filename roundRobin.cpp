#include <iostream>
#include <vector>

using namespace std;

int main(){
	int i,n,time,remain,temps=0,TQ;

	int wt=0,tat=0;

	cout<<"Enter the total number of process="<<endl;
	cin>>n;

	remain=n;


	int avgt[n];
	int bt[n];
	int rt[n];

	cout<<"Enter the Arrival time, Burst time for All the processes"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>avgt[i];
		cin>>bt[i];
		rt[i]=bt[i];
	}

	cout<<"Enter the value of time QUANTUM:"<<endl;
	cin>>TQ;

	cout<<"\n\nProcess\t\t\tTurnaround Time\t\t\tWaiting Time\n\n";
	for(time=0,i=0;remain!=0;)
	{
		if(rt[i]<=TQ && rt[i]>0)
		{
			time += rt[i];
			rt[i]=0;
			temps=1;
		}

		else if(rt[i]>0)
		{
			rt[i] -= TQ;
			//Subtraction using shorthand operators
			time += TQ;
			//Addition using shorthand operators
		}

		if(rt[i]==0 && temps==1)
		{
			remain--;
			printf("Process[%d]\t\t\t%d\t\t\t%d\n",i+1,time-avgt[i],time-avgt[i]-bt[i]);
			cout<<endl;

			wt += time-avgt[i]-bt[i];
			tat += time-avgt[i];
			temps=0;
		}

		if(i == n-1)
			i=0;
		else if(avgt[i+1] <= time)
			i++;
		else
			i=0;
	}

	cout<<"Average waiting time "<<wt*1.0/n<<endl;
	cout<<"Average turn around time "<<tat*1.0/n<<endl;;

	return 0;
}
