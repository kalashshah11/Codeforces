
// Problem: D. Districts Connection
// Contest: Codeforces - Codeforces Round #677 (Div. 3)
// URL: https://codeforces.com/contest/1433/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define REP(i,a,b) for (auto i = a; i != b; i++)
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
    cin>>T;
    for(int t = 1;t<=T;t++)
    {
        int n;
        cin>>n;
        vector<int> v;
        read(n,v);
        set<int> st(all(v));
        if(st.size() == 1)
        {
        	cout<<"NO"<<endl;
        }
        else
        {
        	cout<<"YES"<<endl;
        	auto it = st.begin();
        	int a = v[0];
        	int b = *it;
        	int first = -1;
        	int second = -1;
        	if(*it == a)
        	{
        		it++;
        	}
        
        	b = *it;
        	
        	for(int i = 0;i<n;i++)
        	{
        		if(v[i] == a)
        		{
        			first = i+1;
        			break;
        		}
        	}
        	for(int i = 0;i<n;i++)
        	{
        		if(v[i] == b)
        		{
        			second = i+1;
        			break;
        		}
        	}
        	for(int i = 1;i<n;i++)
        	{
        		if(v[i] == a)
        		{
        			cout<<i+1<<" "<<second<<endl;
        		}
        		else
        			cout<<i+1<<" "<<first<<endl;
        	}
        	
        }
    }

    return 0;
}
