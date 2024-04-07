#include<bits/stdc++.h>

using namespace std;
void print_n_1 (int n)
{
    if (n==0)
    return;
    else
    {
        cout<<n<<" ";
        print_n_1(n-1);
    }
}
void print_1_n (int n)
{
    if (n==0) return;
    print_1_n(n-1);
    cout<<" "<<n;
}
bool Palindrome_string(string &a, int start, int end)
{
    if(start>=end) return true;
    else
    return(a[start]==a[end] && Palindrome_string(a,start+1,end-1));
}
int sumofdigits (int n)
{
    if(n==0) return 0;
    else return(n%10 + sumofdigits(n/10));
}
int maxcuts (int n ,int a, int b, int c)
{
    if(n==0)
    return 0;
    if (n<0) return -1;
    int res = max(maxcuts(n-a,a,b,c),max(maxcuts(n-b,a,b,c),maxcuts(n-c,a,b,c)));
    if(res == -1)
    return -1;
    return (res +1);
}// this is a non dp solution, can be made much faster
void printsubsets (string s, string curr="", int i=0) //the problem is like making a tree and for the leaf nodes we print them
{
    if(i==s.length()) //once you make the tree i is basically the depth of tree
    {
        cout<<" "<<curr; 
        return;
    } //at the ith level you do the desicion of taking s[i] or not
    printsubsets(s,curr,i+1); // you don't take the ith letter
    printsubsets(s,curr+s[i],i+1); // you do take the ith letter
}
void towerofhanoi (int n, string a,string b,string c)
{
    if(n==1)
    {
        cout<<"Move "<<1<<" from "<<a<<" to "<<c<<"\n";
        return;
    } //base case
    towerofhanoi(n-1,a,c,b);
    cout<<"Move "<<n<<" from "<<a<<" to "<<c<<"\n";
    towerofhanoi(n-1,b,a,c);
    return;
}
int josephus_problem_iterative (int n, int k)
{
    vector<bool> t;
    for(int i=0; i<n;i++)
    {
        t.push_back(true);
    }
    int m=0; //first killer
    for (int j = 0; j < n-1; j++) //this where we kill people
    {
        int l=0;
        while(l!=k-1)
        {
            m=(m+1)%n;
            if (t[m])
            {
                l++;
            } //this loop brings from killer to the one to be killed
        }
        t[m]=false; //killing
        while(!t[m])
        {
            m=(m+1)%n; //new killer is the immidiate alive one next to dead one 
        }
    }// since every run we kill exactly one person
    return(m);
}//I wanted to try out an iterative one, I can say it's O(n^2) time and O(n) spacer prettty bad
int josephus_recursion (int n, int k)
{
    if(n==1) return 0; //base case
    return ((josephus_recursion(n-1,k)+k)%n);  
} // wow I've got this
// time complexity is improved (Thetha(n)) from iterative solution but both have same space complexity
int subset_sum_ma (vector<int> t, int n, int s, int m=0) //n is the size of aray
{
    if(n==0)
    {
        if(m==s)
        return 1;
        else 
        return 0;
    } //base case
    return( subset_sum_ma(t,n-1,s,m)+subset_sum_ma(t,n-1,s,m+t[n-1]));
}// my approach
int subset_sum_sa (vector<int> t,int n, int sum)
{
    if(n==0)
    {
        if(sum == 0)
        return(1);
        else 
        return(0);
    }//base case
    return(subset_sum_sa(t,n-1,sum)+subset_sum_sa(t,n-1,sum-t[n-1]));
}
string reduced(string s, int n)
{
    s.erase(n, 1);
    return s;
}
void print_permutations_ma (string s, string c ="")
{
    if(s.length()==0)
    {
        cout<<c<<" ";
        return;
    } //base case
    for(int i=0;i<s.length();i++)
    {
        print_permutations_ma (reduced(s,i),c+s[i]); //here c+s[i] is valid I wrote a seperate function to remove the ith letter and do the calulation
    }
}// time : O(n!) space O(n)
void print_permutations_sa (string s, int i=0)
{
    if(i==s.length()-1)
    {
        cout<<s<<" ";
        return;
    } //base case represents node in tree
    for(int j=i;j<s.length();j++)
    {
        swap(s[i],s[j]);
        print_permutations_sa (s,i+1);
        swap(s[i],s[j]);
    }
}//time  : O(n!)
int main()
{
    print_permutations_sa("abc");
}