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

int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    // freopen("mixmilk.in", "r", stdin);
    // freopen("mixmilk.out", "w", stdout);
    cin>>T;
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        map<ll,ll> mp;
        ll n;
        cin>>n;
        ll num = n;
        ll k = 0;
        while (n % 2 == 0)  
        {  
            mp[2]++;  
            n = n/2;  
        }  
        for (int i = 3; i <= sqrt(n); i = i + 2)  
        {  
            // While i divides n, print i and divide n  
            while (n % i == 0)  
            {  
                mp[i]++;  
                n = n/i;  
            }  
        }    
        if (n > 2)  
            mp[n]++; 
        map<ll,ll> mp1;
        for(auto it : mp)
        {
            // cout<<it.first<<" "<<it.second<<endl;
            if(mp1[it.second] == 0)
                mp1[it.second] = 1;
            mp1[it.second] = it.first * mp1[it.second];
            k = max(k,it.second);
        }
        // cout<<k<<endl;
        vector<ll> v(k+1);
        // for(auto it : mp1)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for(int i = k;i>0;i--)
        {
            if(i != k)
                v[i] = v[i+1];
            else
                v[i] = 1;
            ll temp = mp1[i];
            if(temp != 0)
            {
                v[i] = v[i]*temp;
            }
        }
        cout<<k<<endl;
        for(int i=k;i>0;i--)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

