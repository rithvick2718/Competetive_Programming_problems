#include<iostream>
#include<array> // This is the header file required for this data structure
using namespace std;
int main()
{
	int basic[3] ={1,2,3}; //basic array we have used till now
	array<int,4> a = {1,2,3,4}; //This is the STL Array, this is a static array that's why we do not use in Competetive Programming
	int size =a.size(); // to find the size, similar to vector
	cout<<a[3]<<"\t"; // We can access the elements in O(1) time complexity
    cout<<a.at(2)<<"\n"; //another way to access the element //O(1)
    cout<<"The array is empty "<<a.empty()<<"\n"; //this a.empty() is a boolean variable.
    cout<<"The first element can be accesed using a.front() "<<a.front()<<"\n"; //O(1)
    cout<<"The last element can be accesed using a.back() "<<a.back()<<"\n"; //O(1)
    cout<<"This is an array that's all folks!";
}