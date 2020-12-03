#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
#define vi vector<int>

using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    int mi[m];
    for(int i=0;i<n;i++)
    {
        int b,c;
        cin>>b>>c;
        a[i]=b*c;
    }
    for(int i=1;i<n;i++)
    a[i]+=a[i-1];
    for(int i=0;i<m;i++)
    cin>>mi[i];
    for(int i=0,j=0;i<m&&j<n;)
    {
        if(mi[i]<=a[j])
        {
            printf("%d\n",j+1);
            i++;
        }
        else j++;
        
    }
}