#include<iostream>
#include<map>
using namespace std;
#define PRINT_MAP(M) \
    for(auto i : M) { \
        std::cout << "(" << i.first << "," << i.second << ") "; \
    } cout<<"\n";
int main()
{
    map<string, int> m;
    m["Dosa"]=10;
    m["Poha"]=0;
    m["Pizza"]=7;
    m["Chicken"]=7;
    PRINT_MAP(m);
    map<int,string> M;
    M[1]="Crow";
    M[2]="Owl";
    M[13]="Eagle";
    PRINT_MAP(M);
    //another way to insert
    M.insert({5,"Hawk"});
    PRINT_MAP(M);
    cout<<"13 present? "<<M.count(13)<<"\n";
    cout<<"-13 present? "<<M.count(-13)<<"\n";
    M.erase(13);
    cout<<"After erasing 13 \n";
    PRINT_MAP(M);
    map<int,string>::iterator it =M.find(5);
    for(map<int,string>::iterator i =it; i!=M.end();i++)
    {
        cout << "(" << (*i).first << "," << (*i).second << ") ";
    }
}