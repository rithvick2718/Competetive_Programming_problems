#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; // test cases
    cin >> t;
    int n;
    string q ="? ";
    string A ="! ";
    bool reply;
    string ans;
    while (t--)
    {
        cin>>n;
        ans ="0";
        cout<<q+ans<<"\n";
        cin>>reply;
        if(reply)
        {
            //two phases, phase 1 is reach an end phase 2 is easier from that point
            //phase 1
            bool breakloop =false;
            while(!breakloop && ans.length()<n)
            {
                cout<<q+ans+"0\n";
                cin>>reply;
                if(reply) ans+="0";
                else
                {
                    cout<<q+ans+"1"<<"\n";
                    cin>>reply;
                    if(reply) ans+="1";
                    else breakloop=true;
                }
            }
            //phase 2
            while(ans.length()<n)
            {
                cout<<q+"1"+ans<<"\n";
                cin>>reply;
                if(reply) ans="1"+ans;
                else ans="0"+ans;
            }
        }
        else //this means there is no 0 in the
        {
            ans="";
            for(int i=0; i<n; i++) ans+="1";
        }
        cout<<A+ans<<"\n";
    }
    cout.flush();
    return 0;
}