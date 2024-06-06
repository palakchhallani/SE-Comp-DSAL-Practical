

#include <iostream>
using namespace std;

class complex
{
	float x;
	float y;
public:
	complex()
{
		x=0;
		y=0;
}
complex operator+(complex);
complex operator*(complex);
friend istream &operator >>(istream &input,complex &t)
{
	cout<<"Enter the real part";
	input>>t.x;
	cout<<"Enter the imaginary part";
	input>>t.y;
}
friend ostream &operator <<(ostream &output, complex &t)
{
	output<<t.x<<"+"<<t.y<<"i\n";
}
};
complex complex :: operator+(complex c)
{
	complex temp;
	temp.x=x+c.y;
	temp.y=y+c.y;
	return(temp);
}
complex complex::operator*(complex c){
	complex temp2;
	temp2.x=(x*c.x)-(y*c.y);
	temp2.y=(y*c.x)+(x*c.y);
	return (temp2);
}
int main ()
{
	int x;
	complex c,c1,c2,c3,c4;
    cout<<"The first number is \n";
	cin>>c1;
	cout<<"The second number is \n";
	cin>>c2;
	do
	{
	cout<<"Enter 1 for default constructor"<<endl;
	cout<<"Enter 2 for addition"<<endl;
	cout<<"Enter 3 for multiplication"<<endl;
	cout<<"Enter your case:"<<endl;
	cin>>x;

	switch(x)
		{
		case 1:
			cout<<"Default constructor value=\n";
			cout<<c;
			break;
		case 2:
			c3=c1+c2;
			cout<<"Addition is";
			cout<<c3;
			break;
		case 3:
			c4=c1*c2;
			cout<<"Multiplication is";
			cout<<c4;
			break;
		case 4:
			cout<<"Thank you";
		default:
			break;
		}
	}
	while (x!=4);
return 0;
}
