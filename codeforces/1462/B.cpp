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
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(s.size() >= 4)
        {
            if(s[0] == '2' && s[n-1] == '0')
            {
                int flag = 0;
                if(s[1] == '0' && s[2] == '2')
                {
                    flag = 1;
                }
                else if(s[1] == '0' && s[n-2] == '2')
                {
                    flag = 1;
                }
                else if(s[n-3] == '0' && s[n-2] == '2')
                {
                    flag = 1;
                }
                if(flag)
                {
                    cout<<"Yes"<<endl;
                }
                else
                    cout<<"No"<<endl;
            }
            else if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0')
            {
                cout<<"Yes"<<endl;
            }
            else if(s[n-4] == '2' && s[n-3] == '0' && s[n-2] == '2' && s[n-1] == '0')
            {
                cout<<"Yes"<<endl;
            }
            else
                cout<<"No"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    
        
        
    }

    return 0;
}

