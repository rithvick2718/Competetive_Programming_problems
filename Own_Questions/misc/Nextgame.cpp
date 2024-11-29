#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> games;
    games.push_back("Cuphead");
    games.push_back("Hollow Knight");
    games.push_back("Little Nightmares");
    games.push_back("Outer Wilds");
    games.push_back("Subnautica");
    vector<bool> printed(5,false);
    int print=1,x;
    ofstream cout;
    cout.open("Games_to_play.txt");
    while(print !=6)
    {
        x=rand()%5;
        if(!printed[x]){
            printed[x]=true;
            cout<<print<<". "<<games[x]<<"\n";
            print++;
        }
    }
    cout.close();
}