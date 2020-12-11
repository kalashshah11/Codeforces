#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define REP(i,a,b) for (auto i = a; i != b; i++)
#define maxheap priority_queue < ll, std::vector<ll>, std::less<ll> >
#define minheap priority_queue < ll, std::vector<ll>, std::greater<ll> >   // mxheap.push(), mxheap.top(), mxheap.pop()
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define pb push_back
#define SQ(a) (a)*(a)
 
using namespace std;
// using namespace FastIO;
void read(int n,vector<int>& x)
{
    x.clear();
    x.resize(n);
    for(int i = 0;i<n;i++)
    {
        cin>>x[i];
    }
    
}
void read(int n,int m,vector<vector<int>>& x)
{
    x.clear();
    x.resize(n,vector<int>(m));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0 ;j<m;j++)
            cin>>x[i][j];
    }
}
void read(int n,vector<vector<int>>& x)
{
    x.clear();
    x.resize(n+1);
    for(int i = 0;i<n-1;i++)
    {
         int a,b;
         cin>>a>>b;
         x[a].pb(b);
         x[b].pb(a);
    }
}
void read(int n,vector<vector<int>>& x,int m)
{
    x.clear();
    x.resize(n+1);
    for(int i = 0;i<m;i++)
    {
         int a,b;
         cin>>a>>b;
         x[a].pb(b);
         x[b].pb(a);
    }
}
void read(int n,vector<ll>& x)
{
    x.clear();
    x.resize(n);
    for(int i = 0;i<n;i++)
    {
        cin>>x[i];
    }
}
void binary(int l, int r,vector<ll>& pre,set<ll>& st,vector<int>& v) {
    st.insert(pre[r+1] - pre[l]);
    if (v[l] == v[r]) {
        return;
    }
    int mid = (int)(upper_bound(all(v),(v[r] + v[l])/2) - v.begin());
    binary(l,mid - 1,pre,st,v);
    binary(mid,r,pre,st,v);
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    // freopen("mixmilk.in", "r", stdin);
    // freopen("mixmilk.out", "w", stdout);
    cin>>T;
    // cout<<T<<endl;
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        int n,q;
        cin>>n>>q;
        // cout<<n<<endl;
        vector<int> a;
        read(n,a);
        sort(all(a));
        set<ll> vals;        
        vector<ll> pre(n+1);
        for (int i = 0; i < n; i++) {
            pre[i+1] = a[i] + pre[i];
        }
        binary(0, n - 1,pre,vals,a);
        for (int i = 0; i < q; i++) {
            int b;
            cin >> b;
            if (vals.find(b) != vals.end()) 
            {
                cout << "Yes" << '\n';
            } 
            else 
            {
                cout << "No" << '\n';
            }
        }
        // for (auto i : vals) {
        //     cout << i << ' ';
        // }
        // cout<<endl;
        
        
    }

    return 0;
}

