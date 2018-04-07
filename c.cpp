#include <iostream>
#include <fstream>
using namespace std;
struct studjg{
    string s;
    }ss[2];
class student
{
    public:

        int getData()
        {
             for(int i=0;i<2;i++){
         cout<<"Enter name:"; cin>>ss[i].s;

        }
        }

        int showData()
        {
             for(int i=0;i<2;i++){
        cout<<"Name:"<<ss[i].s<<endl;

        }}
};
int main()
{
    student s;
    //fstream file;

    ofstream file;
    file.open("x3.txt",ios::out);
    s.getData();
    //file.write((char*)&s,sizeof(s));
    file.close();
    ifstream file1;
    file1.open("x3.txt",ios::in);
    //file1.read((char*)&s,sizeof(s));
    s.showData();
    file1.close();
}
