#include<iostream>
#include<cstring>
#include<exception>
using namespace std;

class publication
{
    protected:
    string title;
    float price;
    
    publication(string t="No Title",float p=0.0)
    {
        title=t;
        price=p;
    }
};

class books: public publication
{
    int pages;
    public:
    books( string t="No Title",float p=0.0, int pg=0):publication(t,p)
    
    {
        pages=pg;
    }
    
    void getb()
    {
        cout<<"\nEnter the details of the book"<<endl;
        cout<<"\nEnter the title of the book"<<endl;
        cin>>title;
        cout<<"\nEnter the price of the book"<<endl;
        cin>>price;
        cout<<"\nEnter the pages of the book"<<endl;
        cin>>pages;
        
        try
        {
            if(pages>500&&pages<1500)
            {
                if(price>100&&price<2000)
                {
                    displayb();
                }
            }
            else throw(pages);
        }
        catch(int i)
        {
            cout<<"\nCaught exception in function of book";
            cout<<"\nInvalid data";
            title=" ";
            price=0.0;
            pages=00;
            displayb();
            throw;
        }
    }
     
    void displayb()
    {
        cout<<"\nThe book you enetred is:"<<endl;
        cout<<"Title"<<title<<endl;
        cout<<"Price"<<price<<endl;
        cout<<"Pages"<<pages<<endl;
    }
};

class tape :public publication
{
    float min;
    public:
    tape(string t="No title",float p=0.0,float m=0.0):publication(t,p)
    
    {
        min=m;
    }
    void gett()
    {
        cout<<"\nEnter the details of tape"<<endl;
        cout<<"Enter the title of tape"<<endl;
        cin>>title;
        cout<<"Enter the price of tape"<<endl;
        cin>>price;
        cout<<"Enter the min of book"<<endl;
        cin>>min;
        
        try
        {
            if(price>100&&price<1500)
            {
                if(min>30.0&&min<120.0)
                {
                    displayt();
                }
            }
            else throw(min);
        }
        catch(float f)
        {
            cout<<"Exception caught in tape function"<<endl;
            cout<<"you entered invalid data"<<endl;
            title="No title";
            price=0.0;
            min=0.0;
            displayt();
            throw;
        }
    }
    
    void displayt()
    {
        cout<<"\n The details of the tape are"<<endl;
        cout<<"Title"<<title<<endl;
        cout<<"Price"<<price<<endl;
        cout<<"Min"<<min<<endl;
    }
};

int main()
{
    books b;
    tape t;
    int choice;
    cout<<"Enter your choice\n1.Book\n2.tape"<<endl;
    cin>>choice;
    
    switch(choice)
    {
        case 1:
            b.getb();
            break;
        case 2:
            t.gett();
            break;
    }
    return 0;
    
}

