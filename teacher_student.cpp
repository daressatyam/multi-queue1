#include<iostream>
#include<stdlib.h>
#include<stdbool.h>
using namespace std;

struct table{
    bool pen=false;
    bool paper=false;
    bool question_paper=false;
    bool assignment_done=false;
}s[3];

int main(){
    int c1,c2,sum;
    for(int i=0;i<3;i++){
        if(i==0){
            s[0].pen=true;
        }
        else if(i==1){
            s[1].paper=true;
        }
        else{
            s[2].question_paper=true;
        }
    }

    // Shared table;
    while(1){
        if(s[0].assignment_done==true && s[1].assignment_done==true && s[2].assignment_done==true){
            cout<<endl<<"All the assignments have completed";
            cout<<endl<<"Exiting......";
            exit(1);
        }
        cout<<endl<<"1.->Pen";
        cout<<endl<<"2.->Paper";
        cout<<endl<<"3.-> Question Paper";
        cout<<endl<<"Choose two things to put on the shared table..... ";
        cin>>c1>>c2;
        sum=c1+c2;
        if(c1!=c2){
            if(sum==5){
                if(s[0].assignment_done==false){
                    s[0].assignment_done=true;
                    cout<<endl<<"Assignment done by the first Student";
                }
                else{
                    cout<<endl<<"Assignment already done by this student";
                }
            }
            else if(sum==4){
                if(s[1].assignment_done==false){
                    s[1].assignment_done=true;
                    cout<<endl<<"Assignment done by the second Student";
                }
                else{
                    cout<<endl<<"Assignment already done by this student";
                }
            }
            else if(sum==3){
                if(s[2].assignment_done==false){
                    s[2].assignment_done=true;
                    cout<<endl<<"Assignment done by the third Student";
                }
                else{
                    cout<<endl<<"Assignment already done by this student";
                }
            }
            else{
                int a;
                cout<<endl<<"Item does not exists";
                cout<<endl<<"pres 1 to exit.... ";
                cin>>a;
                if(a==1){
                    exit(1);
                }
                else{
                    cout<<"OK you  want to try again";
                }
            }
        }
        else{
            cout<<endl<<"Two identical items";
        }
    }
}
