
#include <iostream>
#include <cstring>
#include <exception>
using namespace std;
class publication
{
    protected:
        string title;
        float price;
    public:
        publication(string t="No title", float p =0.0)
        {
            title =t;
            price =p;

        }
};
class books :public publication
{
    int pages;
    public:
        books(string t="No title", float p=0.0,int pa =0):publication(t,p)
        {
            pages =pa;
        }
        void getb()
        {
            cout<<"\nEnter the details of the book";
            cout<<"\nEnter the title of the book:";
            cin>>title;
            cout<<"\nEnter the price of the book";
            cin>>price;
            cout<<"\nEnter the pages of the book:";
            cin>>pages;
            try
            {
                if (pages>500&&pages<1500)
                {
                    if(price>100&&price<2000)
                    {
                        displayb();
                    }
                }
                else throw (pages);

            }
        catch (int i){
            cout<<"Caught exception in function of book:"<<endl;
            cout<<" Invalid data:"<<endl;
            title="0";
            price=0.0;
            pages=0;
            displayb();
        throw;
        }
    }
    void displayb()
    {
        cout<<"The book you entered is:"<<endl;
        cout<<"The entered title is:"<<title<<endl;
        cout<<"The entered price is :"<<price<<endl;
        cout<<"The enter pages are:"<<pages<<endl;
    }

};
class tape :public publication
{
  float min;
  public:
  tape( string t="No title", float p =0.0, float m=0.00 ):publication (t,p)
  {
      min =m;
  }
  void gett()
  {
      cout<<"Enter the details of the tape:"<<endl;
      cout<<"Enter the title of the tape:"<<endl;
      cin>>title;
      cout<<"Enter the price of the tape:"<<endl;
      cin>>price;
      cout<<"Enter the pages of the playing time(in minutes):"<<endl;
      cin>>min;
      try
      {
          if(min>30.00&&min<90.00)
          {
              if(price>500&&price<1500)
              {
                  displayt();
              }
          }
          else throw min;
      }
      catch(float f)
      {
          cout<<"Caught Exception in the function of the tape"<<endl;
          cout<<"You enter an invalid data"<<endl;
          title="0";
          price =0.0;
          min=0.0;
          displayt();
          throw;

      }
  }
void displayt()
{
    cout<<"The details of the tape you entered are:"<<endl;
    cout<<"The Entered title is :"<<title<<endl;
    cout<<"The Entered price is:"<<price<<endl;
    cout<<"the Enter play time is :"<<min<<endl;
}
};
int main()
{
    books b;
    tape t;
    int choice;
    cout<<"Do you to Buy book (Press 1) or Do you to buy tape (press 2):"<<flush;
    cin>>choice;
    switch(choice)
    {
        case 1:
            try
            {
                b.getb();
            }
            catch (int i)
            {
                cout<<"Caught exception in int main()"<<endl;
            }
            break;
        case 2:
            try
            {
                t.gett();

            }
            catch(float f)
            {
                cout<<"Caught exception in int main()"<<endl;
            }
            break;
            cout<<"Entered bad choice!!Try again!!"<<endl;
    }


    return 0;
}


