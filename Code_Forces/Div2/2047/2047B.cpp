#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        string s;
        vector<int> c(26,0);
        cin>>n;
        cin>>s;
        for(int i=0; i<n; i++) c[s[i]-'a']++;
        char most_frequent_char;
        char least_frequentr_char;
        vector<int>::iterator it = max_element(c.begin(),c.end());
        *it = 1000;
        for(int i=0; i<26; i++) if(c[i]==0) c[i]=100;
        vector<int>::iterator ot = min_element(c.begin(),c.end());
        most_frequent_char = 'a'+(it - c.begin());
        least_frequentr_char = 'a'+(ot - c.begin());
        for(int i=0; i<n; i++){
            if(s[i] == least_frequentr_char){
                 s[i]=most_frequent_char;
                 break;
            }
        }
        cout<<s<<"\n";
    }
}