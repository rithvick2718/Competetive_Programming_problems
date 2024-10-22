//TakeCourse.cpp
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
int main()
{
    long long number_of_voters=9059340817LL;
    std::vector<long long> a(4,0);
    std::map<int,std::string> mp;
    mp[0]="MA-411 Analytical Number Theory";
    mp[1]="MA-414 Differential Geometry";
    mp[2]="MA-415 Financial Risk Management";
    mp[3]="MA-417 Mathematical Image Processing";
    while (number_of_voters--)
    {
        a[(rand())%4]++;
    }
    std::cout<<"The Winner is "<<mp[max_element(a.begin(),a.end())-a.begin()]<<"\n";
    std::cout<<"The Votes share : \n";
    for(int i=0; i<4; i++)
    {
        std::cout<<mp[i]<<" : "<<a[i]<<"\n";
    }
}