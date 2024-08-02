#include<iostream>
#include<vector>
using namespace std;
void printvector(const vector<int> &V)
{
    cout<<"The vector ";
    for(auto v: V)
    {
        cout<<v<<" ";
    }
    cout<<"\n";
}
void CapacityCheck()
{
    vector<int> v; // yep you know what happens here a vector is made with no element
    printvector(v);
    cout<<"Capacity of Vector="<<v.capacity()<<"\n"; //See that capacity of vector is different from size of vector
    cout<<"Size of Vector="<<v.size()<<"\n"; // Size is the number of elements stored and  
    //capacity is number elements that can be currently stored without reallocation
    v.push_back(1); //as you know this is how we can add an element to an existing vector
    printvector(v);
    cout<<"Capacity of Vector="<<v.capacity()<<"\n";
    cout<<"Size of Vector="<<v.size()<<"\n";
    v.push_back(3);
    printvector(v);
    cout<<"Capacity of Vector="<<v.capacity()<<"\n";
    cout<<"Size of Vector="<<v.size()<<"\n";
    v.push_back(2);
    printvector(v);
    cout<<"Capacity of Vector="<<v.capacity()<<"\n";
    cout<<"Size of Vector="<<v.size()<<"\n";
    return;
}
void CapacityCheck2(unsigned int n)
{
    vector<int> v;
    cout<<"Capacity:"<<v.capacity()<<"\n";
    for(int i=0; i<n; i++)
    {
        v.push_back(i+1);
        cout<<"Capacity:"<<v.capacity()<<"\n";
    }
    return;
}
int main()
{
    //CapacityCheck();
    // unsigned int t; cin>>t;
    // CapacityCheck2(t);
    /*  Now so far the most important thing we learnt is that v.size() gives the number of elements stored in the vector
        and v.capacity() gives the number of elements that can be stored without making and reallocation  
    */
   vector<int> v;
   v.push_back(1);
   v.push_back(2);
   v.push_back(3);
   cout<<"Capacity:"<<v.capacity()<<"\n";
   cout<<"Size:"<<v.size()<<"\n";
   cout<<"At index 2 :"<<v.at(2)<<"\n";//v.at(2) and v[2] have a difference that is v.at(2) performs bounds checking
   cout<<"At index 2 :"<<v[2]<<"\n"; // but v[2] does not so you will have undefined behavior
   // v.at(2) is safer.
   // but v[2] is faster.
   cout<<"Front "<<v.front()<<"\n";
   cout<<"Back "<<v.back()<<"\n";
   cout<<"Before using v.pop_back()"<<"\n";
   printvector(v);
   v.pop_back();
   cout<<"After using v.pop_back()"<<"\n";
   printvector(v);
   cout<<"Before clearing the vector \n";
   cout<<"Capacity:"<<v.capacity()<<"\n";
   cout<<"Size:"<<v.size()<<"\n";
   v.clear();
   cout<<"After clearing the vector \n";
   cout<<"Capacity:"<<v.capacity()<<"\n";
   cout<<"Size:"<<v.size()<<"\n";
   cout<<"Now we make a new vector u \n";
   vector<int> u(5,1); //when we inmitialize vector<int> u(5,1) you will have 5 elements all equal to 1
   printvector(u);
   vector<int> w(5); //we can do this and here the compiler automatically sets all values to 0
   printvector(w);
   vector<int> last(u); // Nearly identical to vector<int> last = u; I did not find credible sources, but for the ones I found seems to be true
   printvector(last);
}