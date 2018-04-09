#include<stdio.h>//header file  for pre-defined functions
#include<conio.h>//header file use for console for input/output

int round_robin(int a, int b);//round robin function declaration
int fcfs(int a, int b);//fcfs function declaration
int priority(int a , int b);//priority function declaration
int waiting_time[20];//integer array initialization
int q1,q2,q3;// initialization if variables of int datatype
int main()// main class declaration
{//body of main class
	//int q1,q2,q3;
	printf("\n\t\tEnter number of processes in queue 1\t\t::\t\t");
	scanf("%d",&q1);// Store total no. processes in first queue
	printf("\n\t\tEnter number of processes in queue 2\t\t::\t\t");
	scanf("%d",&q2);// Store total no. processes in second queue
	printf("\n\t\tEnter number of processes in queue 3\t\t::\t\t");
	scanf("%d",&q3);// Store total no. processes in third queue
	char name[3];//array of character datatype to store name
  int p1,p2,p3;//initialization if variables of int datatype  to store priority for all processes
	printf("\n\t\tEnter priority of queue 1\t\t::\t\t");
	scanf("%d",&p1);//store priority of 1st queue
	while(1)//while loop 
	{
	printf("\n\t\tEnter priority of queue 2\t\t::\t\t");
	scanf("%d",&p2);//store priority of 2st queue
	if(p1!=p2)//check priority 1 is equal or not to priority 2
	{
		break;//if p1 is not equal to p2 exit from while loop
	}
	else
	{
		printf("priorities cannot be equal");
	}
	}
	while(1)
	{
	printf("\n\t\tEnter priority of queue 3\t\t::\t\t");
	scanf("%d",&p3);//store priority of 2st queue
	if(p1!=p3&&p2!=p3)//check if priority p1 not equal to p3 and p2 is also not qual to p3
	{
		break;
	}
	else
	{
		printf("priorities cannot be equal");
	}
	}
	if (p1<p2&&p1<p3)//check if priority p1 less than p2 and p1 is also less than p3
	{
		round_robin(q1,1);//calling round robin function ... queue1 at 1
		if(p2<p3)//check if priority p2 is less than p3
		{
			priority(q2,2);//calling priority function.....queue2 at 2
			fcfs(q3,3);//calling fcfs function.....queue3 at 3
		}
		else
		{
			priority(q3,3);//calling priority function.....queue3 at 3
			fcfs(q2,2);//calling fcfs function.....queue2 at 2
		}
	}
	else if(p2<p1&&p2<p3)//check if priority p2 less than p1 and p2 is also less than p3
	{
		round_robin(q2,2);//calling round robin function ... queue2 at 2
		if(p1<p3)//check if priority p1 is less than p3
		{
			priority(q1,1);//calling priority function.....queue1 at 1
			fcfs(q3,3);//calling fcfs function.....queue3 at 3
		}
		else
		{
			priority(q3,3);//calling priority function.....queue3 at 3
			fcfs(q1,1);//calling fcfs function.....queue1 at 1
		}
	}
	else
	{
		round_robin(q3,3);//calling round robin function ... queue3 at 3
		if(p1<p2)
		{
			priority(q1,1);//calling priority function.....queue1 at 1
			fcfs(q2,2);//calling fcfs function.....queue2 at 2
		}
		else
		{
			priority(q2,2);//calling priority function.....queue2 at 2
			fcfs(q1,1);//calling fcfs function.....queue1 at 1
		}
	}
}


int priority(int a,int b)//start of prority function
{
	int burst_time[20], process[20], turnaround_time[20], priority[20];
      int i, j, limit, sum = 0, position, temp;
      float average_wait_time, average_turnaround_time;//declaration of time to calculate
      printf("applying priority scheduling algorithm on queue no. %d",b);
      limit=a;//store total no of process in limit
      int ask=1;//initalize ask =1
      printf("\nEnter Burst Time and Priority For %d Processes\n", limit);
      if(ask=1)//check if ask =1
      {
      	for(i = 0; i < limit; i++) /* first for loop */
      {
            printf("\nProcess[%d]\n", i + 1);//increment of i by 1 
            printf("Process Burst Time:\t");
            scanf("%d", &burst_time[i]);//store the burst time
            printf("Process Priority:\t");
            scanf("%d", &priority[i]);//store the priority
            process[i] = i + 1;//store in process no as i+1
      }
      ask=0;//change ask as 0
	  }
      for(i = 0; i < limit; i++)
      {
            position = i;//store first i value in postion so we compare the first and second value in priority array
            for(j = i + 1; j < limit; j++)
            {
                  if(priority[j] < priority[position])//check if 2nd process priority is greater than 1st process priority
                  {
                        position = j;//if greater then change position from 1st process to second 
                  }
            }
            temp = priority[i];//store the first process of priority in temp array
            priority[i] = priority[position];//and store the value of second process in first
            priority[position] = temp; //store upper temp value in 1st postion in priority process
            temp = burst_time[i];//store the burst time of 1st process of priority in temp array
            burst_time[i] = burst_time[position];//store burst time of 2nd process to 1st
            burst_time[position] = temp;//store  temp value in burst time 
            temp = process[i];//store process i from 0 to max in temp
            process[i] = process[position];// store process of 2nd in 1st process
            process[position] = temp;//store temp in 1st process
      }
      waiting_time[0] = 0;//intialize waiting time array at 0 as 0
      for(i = 1; i < limit; i++)
      {
            waiting_time[i] = 0;//store from 1 to max as 0
            for(j = 0; j < i; j++)
            {
                  waiting_time[i] = waiting_time[i] + burst_time[j];//calculate waiting time of all processes from 1 by burst time from 0
            }
            sum = sum + waiting_time[i];//add all the waiting time to sum as total wating time
      }
      average_wait_time = sum / limit;// caculate average waiting time as sum of all the waiting time divide by no. of processes in priority queue
      sum = 0;//intilize sum as 0
      printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
      for(i = 0; i < limit; i++)
      {
            turnaround_time[i] = burst_time[i] + waiting_time[i];//calculate turnaround time from 0 process 
            sum = sum + turnaround_time[i];//add all the turnaround time of processes
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n", process[i], burst_time[i], waiting_time[i], turnaround_time[i]);//print process no.    waiting time , burst time,turnaround time of that no
      }
      average_turnaround_time = sum / limit;//calculate average turnaround time of all processes by total no of processes
      printf("\nAverage Waiting Time:\t%f", average_wait_time);
      printf("\nAverage Turnaround Time:\t%f\n", average_turnaround_time);
      return 0;
}

int fcfs(int c, int d)//start of fcfs function
{
	float burst_time[30], waiting_time[30], turnaround_time[30];
        float average_waiting_time = 0.0, average_turnaround_time = 0.0;
        int count, j, total_process;
        printf("applying fcfs on queue no . %d",d);
        total_process=c;//store total no of process in limit
        printf("\nEnter The Burst Time of Processes:\n\n");
        for(count = 0; count < total_process; count++)
        {
                printf("Process [%d]:", count + 1);
                scanf("%f", &burst_time[count]);//store burst time
        }
        waiting_time[0] = 0;  //store from 1 to max as 0 
        for(count = 1; count < total_process; count++)
        {
                waiting_time[count] = 0;
                for(j = 0; j < count; j++)
                {
                        waiting_time[count] = waiting_time[count] + burst_time[j];//calculate waiting time of all processes from 1 by burst time from 0
                }
        }
        printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
        for(count = 0; count < total_process; count++)
        {
                turnaround_time[count] = burst_time[count] + waiting_time[count];//calculate turnaround time from 0 process 
                average_waiting_time = average_waiting_time + waiting_time[count];//add all the waiting time to sum as total wating time
                average_turnaround_time = average_turnaround_time + turnaround_time[count];//calculate average turnaround time of all processes by total no of processes
                printf("\nProcess [%d]\t\t%.2f\t\t%.2f\t\t%.2f", count + 1, burst_time[count], waiting_time[count], turnaround_time[count]);
        }
        printf("\n");
        average_waiting_time = average_waiting_time / count;// caculate average waiting time as sum of all the waiting time divide by no. of processes in  queue
        average_turnaround_time = average_turnaround_time / count;//calculate average turnaround time of all processes by total no of processes
        printf("\nAverage Waiting Time = %f", average_waiting_time);
        printf("\nAverage Turnaround Time = %f", average_turnaround_time);
        printf("\n");
        return 0;
}

int round_robin(int e, int f)//start of round robin fun=ction
{
	int i, limit, total = 0, x, counter = 0, time_quantum; 
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10]; 
      float average_wait_time, average_turnaround_time;
      printf("applying round_robin on queue no. %d ",f);
	  limit=e; //store total no of processes in limit
      x = limit;//store total no of process in limit 
      for(i = 0; i < limit; i++) 
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &arrival_time[i]);//store the arrival time
            printf("Burst Time:\t");
            scanf("%d", &burst_time[i]); //enter burst time
            temp[i] = burst_time[i];//store burst time in temp array to compare further
      } 
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &time_quantum); //enter quantum the which should be 4
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_quantum && temp[i] > 0) //check if temp array is <= time 
            { 
                  total = total + temp[i]; //add array temp to total
                  temp[i] = 0; //and temp set to be 0
                  counter = 1; 
            } 
            else if(temp[i] > 0) //check if array temp is > 0
            { 
                  temp[i] = temp[i] - time_quantum; //substract temp array from quantim time (4)
                  total = total + time_quantum;//add quANTAUM 4 TO total 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i]; //add all the waiting time to sum as total wating time
                  turnaround_time = turnaround_time + total - arrival_time[i]; //calculate turnaround time from 0 process 
                  counter = 0; 
            } 
            if(i == limit - 1) // check is i is equal to total no processes -1
            {
                  i = 0; 
            }
            else if(arrival_time[i + 1] <= total) //check if arrival time of i+1 process is <= total
            {
                  i++;//then increment i by 1
            }
            else 
            {
                  i = 0;
            }
      } 
      average_wait_time = wait_time * 1.0 / limit;// caculate average waiting time as sum of all the waiting time divide by no. of processes in priority queue
      average_turnaround_time = turnaround_time * 1.0 / limit;//calculate average turnaround time of all processes by total no of processes
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time); 
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time); 
      return 0; 
}
