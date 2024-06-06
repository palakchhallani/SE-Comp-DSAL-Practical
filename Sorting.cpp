
#include <iostream>
using namespace std;
int n;
#define size 10
template<class T>


void sel(T A[size]){

    int i,j,min;
    T temp;

    for (i=0;i<n-1;i++)
    {
    	min=i;
    	for(j=i+1;j<n;j++)
    	{
    			if (A[j]<A[min])
    			min=j;
    	}
    	temp=A[i];
    	A[i]=A[min];
    	A[min]=temp;
    }
    cout<<"\nSorted array:";
    for (i=0;i<n;i++)
    {
    	cout<<" "<<A[i];
    }
}

int main() {
    int choice;
	int A[size];
	float B[size];

	int i;

	cout<<"----------------------";
	do
	{
		cout<<"\n 1.Integer:";
		cout<<"\n 2.Float:";
		cout<<"\n 3.Exit:"<<endl;
		cout<<"\n Enter choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				cout<<"Enter total number of Integer Elements"<<endl;
				cin>>n;
				cout<<"Enter integer elements"<<endl;
				for (int i=0;i<n;i++)
				{
					cin>>A[i];
				}
				sel(A);
				break ;

			}
			case 2:
			{
				cout<<"\nEnter total number of float Elements"<<endl;
				cin>>n;
				cout<<"Enter float elements"<<endl;
				for (int i=0;i<n;i++)
				{
					cin>>B[i];
				}
				sel(B);

				break;
			}
			case 3:
			{
				cout<<"*********Program Executed Successfully**********";
				return 0;
			}
			default :
			{
				cout<<"\n Invalid";
			}
		}
	}while (choice!=4);
		return 0;
}

