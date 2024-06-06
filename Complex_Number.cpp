#include<iostream>
using namespace std;

class complex
{
  private:
    int x;
    int y;
  public:
   complex()
   {
       x=0;
       y=0;
   }
   
   complex operator+(complex);
   complex operator*(complex);
   friend istream &operator >>(istream &input, complex &t)
   {
       cout<<"Enter the real part"<<endl;
       cin>>t.x;
       cout <<"Enter the imaginary part"<<endl;
       cin>>t.y;
   }
   friend ostream &operator <<(ostream &output , complex &t)
   {
       cout<<t.x<<"+"<<t.y<<"i\n";
   }
};

complex complex :: operator+ (complex c)
{
    complex temp;
    temp.x=x+c.x;
    temp.y=y+c.y;
    return(temp);
}

complex complex :: operator*(complex c)
{
    complex temp2;
    temp2.x=(x*c.x)-(y*c.y);
    temp2.y=(y*c.x)+(x*c.y);
    return(temp2);
}
int main ()
{
    complex c1,c2,c3,c4;
    
    cout<<"The value of default constructor:\n";
    cout<<c1;
    
    cout<<"Enter the first number \n";
    cin>>c1;
    
    cout<<"Enter the second number \n";
    cin>>c2;
    
    cout<<"\nfirst complex number is \n"<<c1;
    cout<<"\nsecond complex number is \n"<<c2;
    
    c3=c1+c2;
    cout<<"\naddition is "<<c3;
    
    c4=c1*c2;
    cout<<"\nmultiplication is "<<c4;
    
    
}
