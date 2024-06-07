#include<bits/stdc++.h>
using namespace std;
vector<int>numb;
void reduce() {
    if (numb.empty()) {
        return; // If the vector is empty, there's nothing to reduce
    }

    int min = std::numeric_limits<int>::max();
    for (int i = 0; i < numb.size(); ++i) {
        if (numb[i] < min) {
            min = numb[i];
        }
    }
    numb.erase(std::remove_if(numb.begin(), numb.end(), [&min](int x) { return x % min == 0; }), numb.end());
}
int main()
{
    int t;
    cin>>t;
    int n;
    int h;
    while(t--)
    {
        cin>>n;
        int min1 = numeric_limits<int>::max(); //setting the max value
        while (n--)
        {
            cin>>h;
            numb.push_back(h);
        }
        //getting array and the least element (fine)
        reduce();
        reduce();
        if(numb.size()==0) cout<<"YES \n";
        else cout<<"NO \n";
        numb.clear();
    }
}