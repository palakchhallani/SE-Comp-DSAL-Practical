

#include <iostream>
using namespace std;

class stud{
	string name;
	string cls;
	char div;
	int rollno;

public:
	void getdata();
	void display();

stud(){
	name="Palak";
	cls="SE";
	div='A';
	rollno=23;
}
stud(string n,string c,char d,int r){
	name=n;
	cls=c;
	div=d;
	rollno=r;

}
stud(stud &sobj){
	this->name=sobj.name;
	this->cls=sobj.cls;
	this->div=sobj.div;
	this->rollno=sobj.rollno;

}
};
void stud::getdata(){
	cout<<"Enter Name"<<endl;
	cin>>name;
	cout<<"Enter class"<<endl;
	cin>>cls;
	cout<<"Enter div"<<endl;
	cin>>div;
	cout<<"Enter roll no"<<endl;
	cin>>rollno;
}
void stud::display(){
	cout<<"Name:"<<name<<endl;
	cout<<"Class:"<<cls<<endl;
	cout<<"Div:"<<div<<endl;
	cout<<"Roll No:"<<rollno<<endl;
}
int main (){
	stud obj;
	stud obj1;
	stud obj2("Mansi","SE",'A',34);
	stud obj3(obj2);
    cout<<"Function wise"<<endl;
	obj.getdata();
	obj.display();
	cout<<"Default Constructer"<<endl;
	obj1.display();
	cout<<"Parameterise Constructer"<<endl;
	obj2.display();
	cout<<"Copy Constructer"<<endl;
	obj3.display();

	return 0;


}
