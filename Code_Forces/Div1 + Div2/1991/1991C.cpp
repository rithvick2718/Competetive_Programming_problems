#include<bits/stdc++.h>
using namespace std;
void subtractAndAbs(set<int> &originalSet, int x) 
{
    std::set<int> resultSet;
    for (int element : originalSet) {
        resultSet.insert(std::abs(element - x));
    }
    originalSet=resultSet;
}
int calculateAverageOfSmallestAndLargest(const std::set<int>& mySet) {
    auto smallest = mySet.begin();
    auto largest = std::prev(mySet.end());
    int average = (*smallest + *largest) / 2;
    return average;
}
void printvec (vector<int> a)
{
    for(auto b :a)
    {
        cout<<b<<" ";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        //code
        int n;
        cin>>n;
        set<int> a;
        int h;
        while(n--)
        {
            cin>>h;
            a.insert(h);
        }
        vector<int> x;
        int c=0;
        while(a.size()!=1 && c<40)
        {
            h =calculateAverageOfSmallestAndLargest(a);
            x.push_back(h);
            subtractAndAbs(a,h);
            c++;
        }
        if(a.size()==1 && *a.begin()!=0) x.push_back(*a.begin());
        if(a.size()==1 && x.size()<=40)
        {
            cout<<x.size()<<"\n";
            printvec(x);
            cout<<"\n";
        }
        else cout<<-1<<"\n";
    }
}