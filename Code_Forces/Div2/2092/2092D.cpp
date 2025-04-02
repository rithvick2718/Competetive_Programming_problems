#include<bits/stdc++.h>
using namespace std;
// variables
string s;
int n;
vector<int> val;
vector<int> out;
unordered_map<int, char> ic; // int to char
unordered_map<char, int> ci; // char to int
void initialize_maps();
void correct_ci();
void get_val();
void case1();
void case2();
void case3();
void case4();
void push_cases();
pair<int,int> find_first_con(int p);
void insert_char_to_s(int i);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while (tt--)
    {
        cin>>n;
        cin>>s;
        initialize_maps();
        get_val();
        push_cases();
        // cout<<s<<"\n";
    }
}
void initialize_maps() //fine
{
    ic[0]='L';
    ic[1]='I';
    ic[2]='T';
    ci['L']=0;
    ci['I']=1;
    ci['T']=2;
}
void correct_ci() //fine
{
    for(int i=0; i<3; i++)
    {
        ci[ic[i]]=i;
    }
}
void get_val()
{
    val.clear();
    val={0,0,0};
    for(auto x : s)
    {
        val[ci[x]]++;
    }
    if(val[1]<val[2]){
        swap(val[1],val[2]);
        swap(ic[1],ic[2]);
        correct_ci();
    }// so we are sure val[1]>=val[2]
    if(val[0]>=val[1]){} // do nothing
    else if(val[0]>=val[2]){ //we know val[0]<val[1]
        swap(val[0],val[1]);
        swap(ic[0],ic[1]);
        correct_ci();
    }
    else{ // so a[0]<a[2]
        swap(val[0],val[1]);
        swap(ic[0],ic[1]);
        correct_ci();
        swap(val[1],val[2]);
        swap(ic[1],ic[2]);
        correct_ci();
    }
    // now we have got the exact stuff we want
}
void case1(){ //complete
    //code
    cout<<out.size()<<"\n";
    for(int x : out)
    {
        cout<<x+1<<"\n";
    }
}
void case2(){
    //code
    // do ntg
}
void case3(){
    //code now we have a>b=c and in worst case a increases by b-c so we need to add in total 2b-2c + 2(a+b-c-b)= 2a+2b-4c so suppose a=n-1, b=1 and c= 0 we are still fine
    pair<int,int> a= find_first_con(0);
    int temp=2*(val[0]-val[1]);
    if(a.second==1){
        while(temp--)
        {
            out.push_back(a.first);
            insert_char_to_s(a.first);
        }
    }
    else{
        while(temp--)
        {
            out.push_back(a.first-1);
            insert_char_to_s(a.first-1);
            a.first++;
        }
    }
    case1();
}
void case4() //done // a>b>c goal is to make a>b=c
{
    //so I need to find bc or cb or ba or ab then we do b(ca)c, c(ac)b, b(ac)a, a(ca)b
    // the goal is to find the first appearence of b that is next to a letter that is not b.
    pair<int,int> b= find_first_con(1);
    int temp=2*(val[1]-val[2]);
    if(b.second==1){
        while(temp--)
        {
            out.push_back(b.first);
            insert_char_to_s(b.first);
        }
    }
    else{
        while(temp--)
        {
            out.push_back(b.first-1);
            insert_char_to_s(b.first-1);
            b.first++;
        }
    }
    val[0]+=val[1]-val[2]; //this must come first.
    val[2]+=val[1]-val[2];
    case3();
}
void push_cases()
{
    out.clear();
    // so below we have checked that val works
    // for(int i=0; i<3; i++)
    // {
    //     cout<<ic[i]<<" : "<<val[i]<<" ";
    // }
    // cout<<"\n";
    // for(int i=0; i<3; i++)
    // {
    //     cout<<ic[i]<<" : "<<ci[ic[i]]<<" ";
    // }
    // we already know by get_val
    // val[0]>=val[1]>=val[2]
    if(val[1]==0){ // this implies val[1]=val[2]=0
        cout<<-1<<"\n";
    }
    else if(val[0]==val[1] && val[0]==val[2]){ //a=b=c
        case1();
        return;
    }
    else if(val[0]==val[1]){ //a=b>c
        case4();
        return;
    }
    else if(val[1]==val[2]){ //a>b=c
        case3();
        return;
    }
    else{ //a>b>c
        case4();
        return;
    }
}
pair<int,int> find_first_con(int p)
{
    for(int i=0; i<s.length()-1; i++)
    {
        if(s[i]!=s[i+1] && s[i]==ic[p]) return {i,1};
        else if(s[i]!=s[i+1] && s[i+1]==ic[p]) return {i+1,-1};
    }
    return {-1,-1};
}
void insert_char_to_s(int i)
{
    if(s[i]!=s[i+1])
    {
        for(int j=0; j<3; j++)
        {
            if(ic[j]!=s[i] && ic[j]!=s[i+1])
            {
                s.insert(s.begin()+i+1,ic[j]);
                break;
            }
        }
    }
}