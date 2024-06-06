#include <iostream>
using namespace std;
#define size 10

int n;
template<class T>
void selection(T A[size])
{
    int i,j,min;
    T temp;
    for (i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
            {
                min=j;
            }
        }
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
    cout<<"\nSorted Array is:\n";
    for (i=0;i<n;i++)
    {
        cout<<"\t"<<A[i]<<"\t";
    }
}

int main()
{
    int i, I[size];
    float F[size];
    
    cout<<"Sorting array"<<endl;
    cout<<"Integer sorting"<<endl;
    cout<<"How many elements you want to enter "<<endl;
    cin>>n;
    cout<<"Enter the integer elements"<<endl;
    for(i=0;i<n;i++)
    cin>>I[i];
    
    selection(I);
    
    cout<<"\nFloat sorting"<<endl;
    cout<<"How many float elemenyts you want to enter "<<endl;
    cin>>n;
    cout<<"Enter the float elements"<<endl;
    for(i=0;i<n;i++)
    cin>>F[i];
    
    selection(F);
}

