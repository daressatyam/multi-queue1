#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<vector>
#include<unistd.h>
using namespace std;

// This function will work for the interactive process
int interactive(){
    int r;
    int start_s=clock();
    r=rand()%128;
    cout<<endl<<r<<" "<<char(r);
    int stop_s=clock();
    cout <<endl<< "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << endl;
    return(r);
}
//For non interactive process this function will  which include wait
int non_interactive(){
    int r;
    int milliseconds=3000;
    int start_s=clock();
    r=rand()%128;
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end)
    {
    }
    int stop_s=clock();
    cout <<endl<< "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << endl;
    return(r);
}

int main(){
    int a,b=20,c;
    vector<char> high_priority; //Queue for high priority
    vector<char> low_priority;  //Queue for low priority

    while(b>0){
        a=rand()%2;
        cout<<endl<<a;
        if(a==0){
            c=interactive();
            high_priority.push_back(char(c));

        }
        else{
            c=non_interactive();
            low_priority.push_back(char(c));
        }
        b--;
    }


    cout<<endl<<"High Priority queue"<<endl;
    for(int i=0;i<high_priority.size();i++){
        cout<<high_priority[i]<<" ";
    }

    cout<<endl<<"Low priority queue"<<endl;

    for(int i=0;i<low_priority.size();i++){
        cout<<low_priority[i]<<" ";
    }
}
