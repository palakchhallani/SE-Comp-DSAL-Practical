#include<iostream>
#include<string.h>
using namespace std;

class stud_data;
class student
{
    string name;
    int roll_no;
    string cls;
    char* div;
    string dob;
    char* b_grp;
    static int count;

    public:

    student()
    {
        name="";
        roll_no=0;
        cls="";
        div=new char;
        dob="dd/mm/yyyy";
        b_grp=new char[4];
    }

    ~student()
    {
        delete div;
        delete[] b_grp;
    }

  /*  static int getcount()
    {
        return count;
    }*/

    void getdata(stud_data*);
    void display(stud_data*);
};

class stud_data
{
    string add;
    long int* telno;
    long int* drive;

    friend class student;

    public:

    stud_data()
    {
        add="";
        telno=new long;
        drive=new long;

    }
    ~stud_data()
    {
        delete telno;
        delete drive;
    }

    void acc1()
    {
        cout<<"Enter Address:";
        cin.get();
        getline(cin,add);
        cout<<"Enter Telephone Number:";
        cin>>*telno;
        cout<<"Enter Drivinge License:";
        cin>>*drive;
    }

    void show1()
    {
        cout<<"\nAddress:"<<add;
        cout<<"\nTelephone Number:"<<*telno;
        cout<<"\nDriving Number:"<<*drive;
    }
};

inline void student :: getdata(stud_data* st)
{
    cout<<"\nEnter Student Name:";
    cin.get();
    getline(cin,name);
    cout<<"Enter Roll No:";
    cin>>roll_no;
    cout<<"Enter Class:";
    cin.get();
    getline(cin,cls);
    cout<<"Division:";
    cin>>div;
    cout<<"Enter DOB:";
    cin.get();
    getline(cin,dob);
    cout<<"Enter Blodd Group:";
    cin>>b_grp;

    st->acc1();
    //count++;
}

inline void student:: display(stud_data* st1)
{
    cout<<"\nStudent Name:"<<name;
    cout<<"\nRoll Number:"<<roll_no;
    cout<<"\nClass:"<<cls;
    cout<<"\nDivision:"<<div;
    cout<<"\nDOB:"<<dob;
    cout<<"\nBlood Grp:"<<b_grp;

    st1->show1();
}

int main()
{
    student* s1[100];
    stud_data* s2[100];
    int n=0;
    char ch;

    do 
    {
        s1[n]=new student;
        s2[n]=new stud_data;

        s1[n]->getdata(s2[n]);
        n++;
        cout<<"\nDo you Want to add More Data:";
        cin>>ch;
    }while(ch=='y'||ch=='Y');

    for(int i=0;i<n;i++)
    {
        cout<<"\n===========================";
        s1[i]->display(s2[i]);
    }

    cout<<"\n================";
   // cout<<"Total Students:"<<student::getcount();

    for(int i=0;i<n;i++)
    {
        delete s1[i];
        delete s2[i];
    }

    return 0;
}
