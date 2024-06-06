#include <iostream>
#include<fstream>
using namespace std;

class employee 
{
   public:
   string name;
   int id;
   float salary;
   
   void getdata();
   void printdata();
};

void employee:: getdata()
{
    cout<<"Enter employee name"<<endl;
    cin>>name;
    cout<<"Enter employee id"<<endl;
    cin>>id;
    cout<<"Enter employee salary"<<endl;
    cin>>salary;
}

void employee :: printdata()
{
    cout<<"\nEmployee Details: "<<endl;
    cout<<"Employee name: "<<name<<endl;
    cout<<"Employee id: "<<id<<endl;
    cout<<"Employee salary: "<<salary<<endl;
}

int main()
{
    int i,count;
    cout<<"Enter the number of user: "<<endl;
    cin>>count;
    
    ofstream fout("demo.txt");
    employee obj[count];
    for (i=0;i<count;i++)
    {
        obj[i].getdata();
        fout<<obj[i].name<<"\t"<<obj[i].id<<"\t"<<obj[i].salary<<endl;
        obj[i].printdata();
    }
    
    ifstream myfile("demo.txt");
    string line;
    if (myfile.is_open())
    {
        while(getline(myfile,line))
        {
            cout<<line<<"\n";
        }
    }
    myfile.close();
    
}
