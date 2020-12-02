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
    //cin>>T;
    for(int t = 1;t<=T;t++)
    {
        // cout<<"Case #"<<t<<": ";
        int n;
        cin>>n;
        if(n == 1)
        {
            cout<<1<<endl;
            return 0;
        }
        vector<vector<int>> v(n,vector<int>(n));
        int r,c;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                cin>>v[i][j];
                if(v[i][j] == 0)
                {
                    r = i;
                    c = j;
                }
            }
        }
        ll diag1sum = 0;
        ll diag2sum = 0;
        vector<ll> rowsum(n);
        vector<ll> colsum(n);
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(i == j)
                {
                    diag1sum += v[i][j];
                }
                if(i + j == n-1)
                {
                    diag2sum += v[i][j];
                }
                rowsum[i] += v[i][j];
                colsum[j] += v[i][j];
            }
        }
        unordered_map<ll,int> umap;
        for(int i = 0;i<n;i++)
        {
            umap[rowsum[i]]++;
            umap[colsum[i]]++;
        }
        umap[diag1sum]++;
        umap[diag2sum]++;
        if(umap.size() != 2)
            cout<<-1<<endl;
        else
        {
            int count = 2;
            if(r == c)
            {
                count++;
            }
            if(r + c == n-1)
            {
                count++;
            }
            vector<pair<ll,int>> val(all(umap));
            sort(all(val));
            if(umap[rowsum[r]] != count || umap[colsum[c]] != count)
            {
                cout<<-1<<endl;
            }
            else if(rowsum[r] == val[0].first)
            {
                cout<<val[1].first-val[0].first<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
        
    }

    return 0;
}

