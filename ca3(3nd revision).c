#include<stdio.h>
#define N 10 //defining that no. of process cannot exceed 10
typedef struct
{
      int process_id, arrival_time, burst_time, priority;
      int q, ready;
}s;//structure for multiqueue
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
            return 1;
      }
      else
      {
            return 2;
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
                  fcfs();//call the first come first serve function 
            }
            else//else if priority is > 20  then use priority 
            {
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
      printf("first come first serve :\t");
      printf("quantum time of 10 seconds:\t");
      int static quantm=10;//declare quantm time 10 as constant 
        return 0;//return 0 for status return
}//end of fcfs function
prior()//start of prority function

{
      printf("priority scheduling :\t");
      printf("quantum time of 10 seconds:\t");
      int static quant=10;//quantum time 10 as constant
      return 0;
}//end of priority function
}





