
#include <iostream>
#include<fstream>
using namespace std;

class employee{
public :
	string name;
	int emo_id;
	float salary;

void getdata();
void printdata();



};
void employee::getdata()
{
	cout<< "Enter the name of employee"<<endl;
	cin>>name;
	cout<<"Enter employee id"<<endl;
	cin>>emo_id;
	cout<<"Enter the salary"<<endl;
	cin>>salary;

}

void employee::printdata()
{
	cout<<"The name of employee is :"<<name<<endl;
	cout<<"The id of employee is :"<<emo_id<<endl;
	cout<<"The salary of employee is :"<<salary<<endl;
}


int main() {
	int count,i;
	cout<<"Enter the number of users"<<endl;
	cin>>count;

	ofstream fout("palak_3.txt");


	employee obj[count];
	for (i=0;i<count;i++)
	{
		obj[i].getdata();
		fout<<obj[i].name<<"\t"<<obj[i].emo_id<<"\t"<<obj[i].salary<<endl;

		obj[i].printdata();
	}
	ifstream myfile("palak_3.txt");
	string line;
	   if (myfile.is_open())
	   {
		   while(getline(myfile,line))
		   {
		        cout<<line<<"\n";
		   }
	   myfile.close();
}
	return 0;
}

