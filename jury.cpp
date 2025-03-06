#include<bits/stdc++.h>
using namespace std;
void print_vvd(vector<vector<double>> &vvd)
{
    for(auto vv : vvd)
    {
        for(auto v : vv)
        {
            cout<<v<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    vector<vector<double>> vvd;
    // if z^4 + 1.5 z^3 + 2.5 z^2 + 3.5 z + 4.5 =0
    // then v = {1, 1.5, 2.5, 3.5, 4.5}
    vector<double> v ={1,-1.2,0.07,0.3,-0.08}; 
    int i,j;
    /* vvd is the jury array */
    vvd.push_back(v); // Store the first row
    reverse(v.begin(),v.end());
    vvd.push_back(v); // Store the second row

    for (i=2;;i+=2)
    {
        v.clear();
        double mult = vvd[i-2][vvd[i-2].size()-1]/vvd[i-2][0]; // This is an/a0 as mentioned in the article.

        for (j=0; j<vvd[i-2].size()-1; j++) // Take the last 2 rows and compute the next row
               v.push_back(vvd[i-2][j] - vvd[i-1][j] * mult);

        vvd.push_back(v);
        reverse(v.begin(), v.end()); // reverse the next row
        vvd.push_back(v);
        if (v.size() == 1) break;
     }

     // Check is done using
     print_vvd(vvd);
     for (i=0; i<vvd.size(); i+=2)
     {
          if (vvd[i][0]<=0) break;
     }

     if (i == vvd.size())
          cout<<"All roots lie inside unit disc ";
     else
          cout<<"no";
}