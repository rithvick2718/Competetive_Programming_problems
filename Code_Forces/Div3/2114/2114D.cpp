#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000001LL
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        // code
        int n;
        cin>>n;
        vector<pair<ll,ll>> xy(n);
        ll x_mn=INF, y_mn=INF, x_mx=0, y_mx=0;
        for(int i=0; i<n; i++)
        {
            cin>>xy[i].first>>xy[i].second;
            x_mn=min(xy[i].first,x_mn);
            x_mx=max(xy[i].first,x_mx);
            y_mn=min(xy[i].second,y_mn);
            y_mx=max(xy[i].second,y_mx);
        } //takes the pairs and finds x_mn, etc
        int x_mn_c=0; //_c means count
        int x_mx_c=0;
        int y_mn_c=0;
        int y_mx_c=0;
        ll x_mn2=INF, y_mn2=INF, x_mx2=0, y_mx2=0; // second-lowest
        for(auto p : xy){
            if(p.first == x_mn) x_mn_c++;
            else x_mn2=min(p.first,x_mn2);
            if(p.first == x_mx) x_mx_c++;
            else x_mx2=max(p.first,x_mx2);
            if(p.second == y_mn) y_mn_c++;
            else y_mn2=min(p.second,y_mn2);
            if(p.second == y_mx) y_mx_c++;
            else y_mx2=max(p.second,y_mx2);
        }
        ll ans = (x_mx-x_mn+1LL)*(y_mx-y_mn+1LL);

        if (x_mn_c < 2 && x_mn2 != INF) {
            ll nx_mn = INF, nx_mx = 0, ny_mn = INF, ny_mx = 0;
            bool removed = false;
            for (auto &p : xy) {
                if (!removed && p.first == x_mn) { removed = true; continue; }
                nx_mn = min(nx_mn, p.first);
                nx_mx = max(nx_mx, p.first);
                ny_mn = min(ny_mn, p.second);
                ny_mx = max(ny_mx, p.second);
            }
            ll w = nx_mx - nx_mn + 1LL;
            ll h = ny_mx - ny_mn + 1LL;
            ll area = w * h;
            if (area > n-1)       ans = min(ans, area);
            else                  ans = min(ans, area + min(w, h));
        }

        if (x_mx_c < 2 && x_mx2 != 0) {
            ll tx_mn = INF, tx_mx = 0, ty_mn = INF, ty_mx = 0;
            bool removed = false;
            for (auto &p : xy) {
                if (!removed && p.first == x_mx) { removed = true; continue; }
                tx_mn = min(tx_mn, p.first);
                tx_mx = max(tx_mx, p.first);
                ty_mn = min(ty_mn, p.second);
                ty_mx = max(ty_mx, p.second);
            }
            ll w = tx_mx - tx_mn + 1LL;
            ll h = ty_mx - ty_mn + 1LL;
            ll area = w * h;
            if (area > n-1)       ans = min(ans, area);
            else                  ans = min(ans, area + min(w, h));
        }

        // 3) drop the one at y_mn
        if (y_mn_c < 2 && y_mn2 != INF) {
            ll ux_mn = INF, ux_mx = 0, uy_mn = INF, uy_mx = 0;
            bool removed = false;
            for (auto &p : xy) {
                if (!removed && p.second == y_mn) { removed = true; continue; }
                ux_mn = min(ux_mn, p.first);
                ux_mx = max(ux_mx, p.first);
                uy_mn = min(uy_mn, p.second);
                uy_mx = max(uy_mx, p.second);
            }
            ll w = ux_mx - ux_mn + 1LL;
            ll h = uy_mx - uy_mn + 1LL;
            ll area = w * h;
            if (area > n-1)       ans = min(ans, area);
            else                  ans = min(ans, area + min(w, h));
        }

        // 4) drop the one at y_mx
        if (y_mx_c < 2 && y_mx2 != 0) {
            ll vx_mn = INF, vx_mx = 0, vy_mn = INF, vy_mx = 0;
            bool removed = false;
            for (auto &p : xy) {
                if (!removed && p.second == y_mx) { removed = true; continue; }
                vx_mn = min(vx_mn, p.first);
                vx_mx = max(vx_mx, p.first);
                vy_mn = min(vy_mn, p.second);
                vy_mx = max(vy_mx, p.second);
            }
            ll w = vx_mx - vx_mn + 1LL;
            ll h = vy_mx - vy_mn + 1LL;
            ll area = w * h;
            if (area > n-1)       ans = min(ans, area);
            else                  ans = min(ans, area + min(w, h));
        }
        cout<<ans<<"\n";
    }
}