    #include<bits/stdc++.h>
    using namespace std;
    vector<unsigned> nums(5000000);
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        unsigned int a,b,mod,k;
        cin>>a>>b>>mod>>k;
        for( int i=0 ; i<5000000 ; i++ )
    	{
    		a = 31014 * (a & 65535) + (a >> 16);
    		b = 17508 * (b & 65535) + (b >> 16);
    		nums[i] = ((a << 16) + b) % mod;
    	}
        nth_element(nums.begin(),nums.begin()+k-1,nums.end());
        cout<<nums[k-1];
    } 