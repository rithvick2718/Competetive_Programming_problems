#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //this is to test a few differences between ponters and references
    int a =6;
    int& c= a;
    int* d =&a;
    c=9;
    cout<<*d;
    return 0;
}