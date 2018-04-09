#include<stdio.h>//header file
#define N 10 //defining that no. of process cannot exceed 10
typedef struct
{
      int process_id, arrival_time, burst_time, priority;
      int q, ready;
}s;//obj structure for multiqueue
typedef struct
{
      int p_id;ra_t,rb_t,rp;
}r;//structure for round robin
typedef struct
{
      int fp_id;fa_t,fb_t,fp;
}f;//structure for first come first serve
typedef struct
{
      int pp_id;pa_t,pb_t,pp;
}p;//structure for priority queue
int Queue(int q) {
      if(q == 0 || q == 1 || q == 2 || q == 3)// 3 queue generation
      {
            return 1;//return 1
      }
      else
      {
            return 2;//return 2
      }
}
int main()//start of main class
{
      int n, i, temp_process, time, j, y;
      s temp;
      printf("Enter Total Number of Processes:\t");
      scanf("%d", &n);// taking no. of process from user
      s process[n];//array of n size of s type (multiqueue type)
      for(i = 0; i < n; i++)
      {
            printf("\nProcess ID:\t");
            scanf("%d", &process[i].process_id);//take process ID
            printf("Arrival Time:\t");
            scanf("%d", &process[i].arrival_time);//take arrival time
            printf("Burst Time:\t");
            scanf("%d", &process[i].burst_time);//take burst time
            printf("Process Priority:\t");
            scanf("%d", &process[i].priority);//take priority 
      } r proces[n];//array of n size of type r (round robin)
      f pro[n];//array of n size of type f (fcfs)
      p pr[n]; //array of n size of type r (priority)   
      for(i=0;i<n;i++)//loop from 0 to total no. of process
      {
            if(process[i].priority>0 && process[i].priority<10)//check condition if priority is b/w 0-10 then use round robin
            {     rr=rr+1;//count no. of process is b/w 0-10
                  proces[i].p_id=process[i].process_id;//store process id from multiqueue to round robin
                  proces[i].ra_t=process[i].arrival_time;//store arrival time from multiqueue to round robin
                  proces[i].rb_t=process[i].burst_time;//store burst time from multiqueue to round robin
                  proces[i].rp=process[i].priority;//store priority from multiqueue to round robin
                  round_robin();//call the round robin function 
            }
            else if(process[i].priority>10 && process[i].priority<20)//check condition if priority is b/w 10-20 then use first come first serve
            {  
                   m=m+1;//count total no of process b/w 10-20
                  return m;
                  pro[i].fp_id=process[i].process_id;//store process id from multiqueue to fcfs
                  pro[i].fa_t=process[i].arrival_time;//store arrival time from multiqueue to fcfs
                  pro[i].fb_t=process[i].burst_time;//store burst time from multiqueue to fcfs
                  pro[i].fp=process[i].priority;//store priority from multiqueue to fcfs
                  fcfs();//call the first come first serve function 
            }
            else//else if priority is > 20  then use priority 
            {       
                   pp=pp+1;//count no. of process <20
                  pr[i].pp_id=process[i].process_id;//store process id from multiqueue to priority
                  pr[i].pa_t=process[i].arrival_time;//store arrival time from multiqueue to priority structure
                  pr[i].pb_t=process[i].burst_time;//store burst time from multiqueue to priority structure
                  pr[i].pp=process[i].priority;//store priority from multiqueue to priority structure
                  prior();//call the priorityfunction 
            }
      }

      return 0;//return 0 status
 }
round_robin()//start of round robin function
 {
      int total=0,count=0,i;
      int wait_time = 0, turnaround_time = 0, temp[10]; //temp to store burst time from structure
      float average_wait_time, average_turnaround_time;
      printf("round_robin :\t");
      printf("quantum time of 4 seconds:\t");
      int static time_quantum=4;//define static quantum time  4 second with is constant
      int x=rr;//store total no. of process b/w 0-10 in x
      for(i=0;i<10;i++)//for for start to store burst time in temp
      {
            temp[i]=proces[i].rb_t;//store burst time in temp array
      }
       printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_quantum && temp[i] > 0) //check burst time is > 0 nd <= quantum time
            { 
                  total = total + temp[i]; //add in total
                  temp[i] = 0; //if condtion true temp =0
                  counter = 1; 
            } 
            else if(temp[i] > 0) //burst time of 1st process is > o
            { 
                  temp[i] = temp[i] - time_quantum; //burst time - quauntum time
                  total = total + time_quantum; //add 
            } 
            if(temp[i] == 0 && counter == 1) //check if burst time =0 and counter =1
            { 
                  x--; //decrement x by 1
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, proces[i].rb_t, total - proces[i].ra_t, total - proces[i].rb_t);//print burst time and arrival time
                  wait_time = wait_time + total -proces[i].ra_t - proces[i].rb_t; //calculate waiting time
                  turnaround_time = turnaround_time + total - proces[i].ra_t; //calcute turnarround time
                  counter = 0; 
            } 
            if(i == limit - 1) //check
            {
                  i = 0; //initlize i=0
            }
            else if(proces[i+1].ra_t <= total)//check if arrival time +1 is less than or greater than total 
            {
                  i++;//increment by 1
            }
            else //otherwise
            {
                  i = 0;//decrement by 1
            }
        }//end of for loop
       
      average_wait_time = wait_time * 1.0 / limit;//calculate the average wait time of all processes in round robin
      average_turnaround_time = turnaround_time * 1.0 / limit;//calculate the average turnaround time of all processes in round robin
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time); //print average wait time
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time); //print turnaround time
      return 0; 
 }//end of round robin function
fcfs()//start of first come first serve function
{
     int i, m;
      float waiting_time[30], turnaround_time[30];//waiting time and turnaround time
      float average_waiting_time = 0.0, average_turnaround_time = 0.0;// variable to store average waiting time and turnaround time
      int j;
      printf("first come first serve :\t");
      printf("quantum time of 10 seconds:\t");
      int static quantm=10;//define static quantum time  4 second with is constant
      waiting_time[0] = 0;//initailzing waiting time at 0 is 0
        for(j = 1; j < m; j++)
        {
                waiting_time[j] = 0;
                for(i = 0; i < j; i++)
                {
                        waiting_time[j]=waiting_time[j]+pro[j].fb_t;// calcluate waiting time at j
                }
        }
      printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
        for(j = 0; j < m; j++)
        {
                turnaround_time[j] = pro[j].fb_t + waiting_time[j];//calculate turnaround time
                average_waiting_time = average_waiting_time + waiting_time[j];//calculate average waiting time
                average_turnaround_time = average_turnaround_time + turnaround_time[j];//calculate average turnaround time
                printf("\nProcess [%d]\t\t%.2f\t\t%.2f\t\t%.2f", j + 1, pro[j].fb_t, waiting_time[j], turnaround_time[j]);//print burst time , waiting time and turnaround time
        }
        printf("\n");
        average_waiting_time = average_waiting_time/j;//calculate average waiting time
        average_turnaround_time = average_turnaround_time / j;//calculate average turnaround time
        printf("\nAverage Waiting Time = %f", average_waiting_time);//print average waiting time
        printf("\nAverage Turnaround Time = %f", average_turnaround_time);//print turnaround time
        printf("\n");
        return 0;
}//end of fcfs function
prior()//start of prority function

{
      int i, limit, total = 0, x, counter = 0; 
      int wait_time = 0, turnaround_time = 0, arrival_time[10], temp[10]; //declaration of time to calculate
      float average_wait_time, average_turnaround_time;
      printf("priority scheduling :\t");
      printf("quantum time of 10 seconds:\t");
      int static time_quantum=10;//time quantum constant value 10
      limit=pp;//store total no of process in limit
      for(i = 0; i < limit; i++)
      {
        temp[i]=pr[i].pb_t;//store burst time in temp array
      }
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_quantum && temp[i] > 0) //check is burst time >0 and <=time quantum
            { 
                  total = total + temp[i]; //calculate total
                  temp[i] = 0; //initialize temp[i]=0
                  counter = 1; //initialize counter =1
            } 
            else if(temp[i] > 0) //check burst time of process i is >0
            { 
                  temp[i] = temp[i] - time_quantum; //calculate burst time
                  total = total + time_quantum; //store total
            } 
            if(temp[i] == 0 && counter == 1) //check condition burst time 0f process i is 0
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, pr[i].pb_t, total - pro[i].fa_t, total - pro[i].fa_t - pr[i].pb_t);//print burst time and arrival time
                  wait_time = wait_time + total - pro[i].fa_t - pr[i].pb_t; //claculate wait time
                  turnaround_time = turnaround_time + total - pro[i].fa_t; //calculate turnaround time
                  counter = 0; //initilize counter as 0
            } 
            if(i == limit - 1) //check if i equal no. of process -1
            {
                  i = 0; //initilize i as 0
            }
            else if(pro[i+1].fa_t <= total) //check if arrival time of i+1 process <= total
            {
                  i++;//increment i by 1
            }
            else //else
            {
                  i = 0;//initilize i as 0
            }
      } 
      average_wait_time = wait_time * 1.0 / limit;//calculate average waiting time
      average_turnaround_time = turnaround_time * 1.0 / limit;//calculate average turnaround time
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time); //print average waiting time
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time); //print average turnaround time
      return 0;
}//end of priority function
}





