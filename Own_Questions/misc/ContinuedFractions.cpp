#include<bits/stdc++.h>
using namespace std;
int sgn(const int &x) 
{
    return ((x > 0) - (x < 0));
} //same as the function in math but only for integers
vector<int> storecontinuedfractions(const int &p, const int &q)
{
    vector<int> a; //the vector I return
    int m=(int)(p/q)+(int)(((sgn(p)*sgn(q))-1)/(2))+((p*q<0 && p%q==0 )?1:0); //this is basically floor (p/q)
    //was all good until p*q<0 and p%q==0 so I added this ((p*q<0 && p%q==0 )?1:0)
    a.push_back(m);
    // what (int)((sgn(m)-1)/(2)) does is for positive m it gives 0, negative -1 and for m=0 -0.5 truncates to 0
    int num=(p-q*m)*sgn(q);
    int den=q*sgn(q); // now we have both num and den +ve
    //also at this stage num < den
    while(num!=0 && num!=den)
    {
        swap(num, den);
        m=(int)(num/den);
        a.push_back(m);
        num=num-m*den;
    }
    return(a);
}
void printcontinuedfractions(const int &p, const int &q)
{
    int m=(int)(p/q)+(int)(((sgn(p)*sgn(q))-1)/(2))+((p*q<0 && p%q==0 )?1:0);
    cout<<m<<" ";
    // what (int)((sgn(m)-1)/(2)) does is for positive m it gives 0, negative -1 and for m=0 -0.5 truncates to 0
    int num=(p-q*m)*sgn(q);
    int den=q*sgn(q); // now we have both num and den +ve
    //also at this stage num < den
    while(num!=0 && num!=den)
    {
        swap(num, den);
        m=(int)(num/den);
        cout<<m<<" ";
        num=num-m*den;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int p,q;
    while (t--)
    {
        cin>>p>>q;
        printcontinuedfractions(p,q);
        cout<<"\n";
        vector<int> a = storecontinuedfractions(p,q);
        for(auto k: a)
        {
            cout<<k<<" ";
        }
        cout<<"\n";
    }
}