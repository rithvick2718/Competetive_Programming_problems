#include <bits/stdc++.h>
using namespace std;

vector<int> a; //global array

int gcd(int num1, int num2)
{
    if (num2 == 0)
        return num1;
    return gcd(num2, num1 % num2);
}
 
int lcm_of_array(int m, vector<int> a)
{
    int lcm = a[0];
    for (int i = 1; i < m; i++) {
        int num1 = lcm;
        int num2 = a[i];
        int gcd_val = gcd(num1, num2);
        lcm = (lcm * a[i]) / gcd_val;
    }
    return lcm;
}

// Function to check if the LCM of the entire array equals the last element (for a sorted array)

bool CheckIfLcmIsLast() //this is for sorted array
{
    int m =(int) a.size();
    if(m==0) return(false);
    for(int i=0; i<m;i++)
    {
        if(a[m-1]%a[i]!=0) return(false);
    }
    return(true);
}

bool works (int m, vector<int> b)
{
    if(m==0) return(true);
    int LCM = lcm_of_array(m,a); //calculate the LCM of sorted array upto m integers
    int x =m-1; //as it is 0 index
    while(x<b.size())
    {
        if(b[x]==LCM) return(false);
        x++;
    }
    return(true);
}
int solver(vector<int> b)
{
    while (CheckIfLcmIsLast())
    {
        a.pop_back();
    }//after this you have good array
    int ans = a.size();
    if(works(ans,b)) return(ans);
    else
    {
        return(ans--);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, h;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> h;
            a.push_back(h);
        }
        sort(a.begin(), a.end());  // Sorting the array
        vector<int> b =a;
        cout<<solver(b)<<"\n";
        a.clear();
    }
    return 0;
}