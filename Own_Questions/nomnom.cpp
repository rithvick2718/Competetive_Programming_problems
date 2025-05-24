#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll ans=0LL;
    for(ll i1=1LL; i1<=10LL; i1++){ //1
        ans+=i1;
        for(ll i2=i1+1; i2<=10LL; i2++){ //2
            for(ll i3=i2+1; i3<=10LL; i3++){ //3
                ans+=i1*i2*i3;
                for(ll i4=i3+1; i4<=10LL; i4++){ //4
                    for(ll i5=i4+1; i5<=10LL; i5++){ //5
                        ans+=i1*i2*i3*i4*i5;
                        for(ll i6=i5+1; i6<=10LL; i6++){
                            for(ll i7=i6+1; i7<=10LL; i7++){
                                ans+=i1*i2*i3*i4*i5*i6*i7;
                                for(ll i8=i7+1; i8<=10LL; i8++){
                                    for(ll i9=i8+1; i9<=10LL; i9++){
                                        ans+=i1*i2*i3*i4*i5*i6*i7*i8*i9;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    ll fact=1LL*2LL*3LL*4LL*5LL*6LL*7LL*8LL*9LL*10LL*11LL;
    cout<<fact<<endl;
    cout<<ans*2LL;
}
// #include<bits/stdc++.h>
// using namespace std;
// bool has_odd (int n){
//     int a=0;
//     while(n>0){
//         if(n&1) a++;
//         n>>=1;
//     }
//     return a&1;
// }
// int main()
// {
//     int n =1<<10;
//     double p[10],q[10];
//     for(int i=0; i<10; i++){
//         p[i]=1.0/(i+2);
//         q[i]=(i+1.0)/(i+2);
//     }
//     for(int i=0; i<10; i++){
//         cout<<q[i]<<endl;
//     }
//     double total_probability = 0;
//     int j;
//     double partial_probability=1;
//     for(int i=0; i<n; i++)
//     {
//         if(has_odd(i)){
//             j=i;
//             partial_probability=1;
//             for(int i2 = 0; i2<10; i2++){
//                 if(j&1) partial_probability*=p[i2];
//                 else partial_probability*=q[i2];
//                 j>>=1;
//             }
//             total_probability+=partial_probability;
//         }
//     }
//     cout<<total_probability;
// }