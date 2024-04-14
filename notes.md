## So this is for notes.
#include<bits/stdc++.h> this is a common header file so you don't have to write #include<iostream>, #include<vector> #include<cmath> #include<fstream> etc
I have this problem I don't want to create an .exe file whenever I run a new .cpp file so I paste this in terminal 
g++ -o temp.exe yourfile.cpp && temp.exe && del temp.exe
the above in cmd prompt
g++ yourfile.cpp -o temp.exe; .\temp.exe; Remove-Item temp.exe
In Powershell
g++ yourfile.cpp -o temp.exe && ./temp.exe && rm temp.exe
In git bash

So in programs you see that if you want (l+r)/2 then it might be better to write l+(r-l)/2 that is because sometimes l+r can cause overflow resulting in wrong output