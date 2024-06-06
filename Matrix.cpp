

#include <iostream>
#include<graphics.h>
#include<math.h>
using namespace std;



class Matrix
{
public:
	int m[3][3],i,j;
	friend Matrix operator*(Matrix a ,Matrix b)
	{
		int sum=0;
		int i,j,k;
		Matrix c;
		for (i=0;i<3;i++)
		{
			for (j=0;j<3;j++)
			{
				for(k=0;k<3;k++)
				{
					sum=sum+a.m[i][k]*b.m[k][j];
				}
				c.m[i][j]=sum;
				sum=0;
			}
		}
		return c;
	}
	 void getdata();
	 void display();
	 void fdrawpoly(int mat[3][3]);
	 void gettrans();
	 void rotation();
	 void scaling();


};

void Matrix :: getdata()
{
	for (i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>m[i][j];
		}
		cout<<"\n";
	}


}

void Matrix :: display()
{
	for (i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<m[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
void Matrix :: fdrawpoly(int mat [3][3])
{
	int gd, gm;
	initgraph(&gd, &gm, " ");
	int arr[]={mat[0][0],mat[1][0],mat[0][1],mat[1][1],mat[0][2],mat[1][2],mat[0][0], mat [1][0]};
	drawpoly(4,arr);
	delay(8000);
	closegraph();
}

void Matrix :: gettrans()
{
	int tx, ty;
	cout<<"Enter the value of tx"<<endl;
	cin>>tx;
	cout<<"Enter value of ty"<<endl;
	cin>>ty;
	m[0][0]=1;
	m[0][1]=0;
	m[0][2]=tx;
	m[1][0]=0;
	m[1][1]=1;
	m[1][2]=ty;
	m[2][0]=0;
	m[2][1]=0;
	m[2][2]=1;
}

void Matrix :: scaling()
{
	int sx, sy;
	cout<<"Enter the value of sx"<<endl;
	cin>>sx;
	cout<<"Enter value of sy"<<endl;
	cin>>sy;
	m[0][0]=sx;
	m[0][1]=0;
	m[0][2]=0;
	m[1][0]=0;
	m[1][1]=sy;
	m[1][2]=0;
	m[2][0]=0;
	m[2][1]=0;
	m[2][2]=1;
}

void Matrix :: rotation()
{
	int th;
	float rth;
	cout<<"Enter the value of Rotation angle "<<endl;
	cin>>th;
	rth=th*(3.14/180);
	m[0][0]=cos (rth);
	m[0][1]=sin(rth);
	m[0][2]=0;
	m[1][0]=-sin(rth);
	m[1][1]=cos(rth);
	m[1][2]=0;
	m[2][0]=0;
	m[2][1]=0;
	m[2][2]=1;
}


int main()
{

	Matrix a,b,c ;
	int ch;
	cout<<"first matrix: \n";
	a.getdata();
	a.display();
	a.fdrawpoly(a.m);
	cout<<"1.Translation"<<endl<<"2.Scaling"<<endl<<"3.Rotation";
	cout<<"Enter your choice"<<endl;
	cin>>ch;

	switch(ch)
	{
	case 1:
		b.gettrans();
		b.display();
		c=b*a;
		cout<<endl;
		cout<<"Multiplication of matrix is"<<endl;
		c.display();
		//a.fdrawpoly(a.m);
		c.fdrawpoly(c.m);
		break;
	case 2:
		b.scaling();
		b.display();
		c=b*a;
		cout<<endl;
		cout<<"Multiplication of matrix is"<<endl;
		c.display();
		//a.fdrawpoly(a.m);
		c.fdrawpoly(c.m);
		break;

	case 3:
		b.rotation();
		b.display();
		c=b*a;
		cout<<endl;
		cout<<"Multiplication of matrix is"<<endl;
		c.display();
		//a.fdrawpoly(a.m);
		c.fdrawpoly(c.m);
		break;
	}
	return 0;
}
