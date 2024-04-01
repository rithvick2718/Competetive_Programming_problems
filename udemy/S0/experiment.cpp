#include<iostream>
using namespace std;
struct race
{
    int pos1;
    int pos2;
    string startTime;
    double multiplierHorse1,multiplierHorse2,multiplierHorse3;
    race(int p1, int p2, string h, double g1, double e, double g2) 
    {
        pos1=p1;
        pos2=p2;
        startTime=h;
        multiplierHorse1=g1;
        multiplierHorse2=e;
        multiplierHorse3=g2;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"I am fine man";
}