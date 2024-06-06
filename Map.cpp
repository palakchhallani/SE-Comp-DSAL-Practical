#include<iostream>
#include<map>
using namespace std;

int main ()
{
    typedef map<string,int>mymap;
    mymap pmap;
    
    pmap.insert(pair<string,int>("maharashtra",2587));
    pmap.insert(pair<string,int>("rajasthan",587));
    pmap.insert(pair<string,int>("west bengal",589));
    pmap.insert(pair<string,int>("andra pradesh",2654));
    pmap.insert(pair<string,int>("chattishgarh3",1236));
    
    mymap::iterator iter;
    for(iter=pmap.begin();iter!=pmap.end();++iter)
    {
        cout<<iter->first<<":"<<iter->second<<"million\n";
    }
    cout<<"\nsize of population map"<<pmap.size()<<endl;
    
    string state_name;
    cout<<"Enter the name of state"<<endl;
    cin>>state_name;
    iter=pmap.find(state_name);
    //if (iter!=pmap.end())
    cout<<state_name<<"state population is "<<iter->second<<"million";
    
    pmap.clear();
}


