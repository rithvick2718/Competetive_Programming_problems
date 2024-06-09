#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void keepMaxMinAndRemoveOthers(std::vector<long long int>& vec) {
    if (vec.empty()) return; // If vector is empty, do nothing

    // Find the maximum and minimum elements in the vector
    auto max_it = std::max_element(vec.begin(), vec.end());
    auto min_it = std::min_element(vec.begin(), vec.end());

    long long int max_val = *max_it;
    long long int min_val = *min_it;

    // Clear the vector
    vec.clear();

    // Add the maximum and minimum elements back to the vector
    vec.push_back(max_val);
    vec.push_back(min_val);
}
long long int vecmax(vector<long long int> &C)
{
    int n=C.size();
    long long int m = C[0];
    for(int i=0; i<n; i++)
    {
        m=max(m,C[i]);
    }
    return(m);
}
long long int maxc (vector<int> &a)
{
    int n =a.size();
    vector<long long int> C; //the possible C
    C.push_back((long long int) 0); //so there is the first C
    for(int i=0; i<n; i++) //for all a[i]
    {
        vector<long long int> toinsert; //this is if we encounter negative C
        for(int j=0; j<C.size(); j++)
        {
            C[j]=C[j]+(long long int)a[i];
            if(C[j]<0)
            toinsert.push_back(-1*C[j]);
        }
        for(int c : toinsert)
        {
            C.push_back(c);
        }
        keepMaxMinAndRemoveOthers(C);
    }
    return(vecmax(C));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n;
    while (t--)
    {
        //code for each test case
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        } //fine
        cout<<maxc(a)<<"\n";
    }
}