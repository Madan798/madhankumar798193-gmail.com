#include<stdio.h>
#include<conio.h>
int main()
{
int i,lim,time_quantum,waiting_time = 0,turnaround_time = 0,arrival_time[10],burst_time[10],temp[10],total = 0,x,count = 0;
float avg_waitingtime, avg_turnaroundtime;
printf("Enter the total number of processes:t ");
scanf("%d",&lim);
x=lim;
for(i=0;i<lim;i++)
{
printf("enter details of process[%d]\n",i+1);
printf("Burst Time:t ");
scanf("%d",&burst_time[i]);
printf("Arrival Time:t");
scanf("%d",&arrival_time[i]);
temp[i]=burst_time[i];
}
printf("enter time quantum:t");
scanf("%d", &time_quantum);
printf("process ID Burst time turnaround time Waiting Time\n");
for(total = 0, i = 0; x != 0;)
{
if(temp[i] <= time_quantum && temp[i] > 0)
{
total = total + temp[i];
temp[i] = 0;
count = 1;
} 
else if(temp[i] > 0)
{
temp[i]=temp[i]-time_quantum;
total=total+time_quantum;
}
if(temp[i]==0 && count == 1)
{
x--;
printf("Process[%d]%d %d %d\n", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
waiting_time = waiting_time+total-arrival_time[i]-burst_time[i];
turnaround_time=turnaround_time+total-arrival_time[i];
count=0;
}
if(i==lim-1)
{
i = 0;
}
else if(arrival_time[i + 1] <= total)
{
i++;
}
else
{
i = 0;
}
}
avg_waitingtime = waiting_time * 1.0/lim;
avg_turnaroundtime=turnaround_time*1.0/lim;
printf("Avg waiting time:t%f\n",avg_waitingtime);
printf("Avg turnaround time:t%f\n",avg_turnaroundtime);
return 0;
}
