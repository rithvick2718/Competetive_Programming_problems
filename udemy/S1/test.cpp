#include<bits/stdc++.h>
#include<typeinfo>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[]= {11,22,33,44,55,66,77,88,99};
    bool p = binary_search(arr, arr+8, 23);
    if (binary_search(arr, arr+8, 23)) cout<<"yes bro";
    else cout<<"nope man nope";
    return 0;
}