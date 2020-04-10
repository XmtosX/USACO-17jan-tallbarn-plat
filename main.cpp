/*
The btureforce solution for this porblem is to assign the cows one by one, we see which buildings will save us more time if we 
assign another cow to them, and we do so.
The problem is that K is very big.
But there is a useful observation: let's consider that we assigned x cows to the ith building, let's call a[i]/x-a[i]/(x+1) 
dif(i,x).
at the optimal solution, dif(i,x) for all i such that 0<=i<n is fairly equal, so we can do a binary search on the value of
the dif function.
after that, to know how much cows we need to assign for each building, we can do some mathematical equations to get the sum of 
cows, we compare it to k and iterate the binary search in accordance to it.
*/
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
double k,a[N],b[N];
int n;
set<pair<double,pair<int,long long> > >s;
double dif (double x, double y)
{
    return (x/y)-(x/(y+1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("tallbarn.in","r",stdin);
    freopen("tallbarn.out","w",stdout);
    cin >>n>>k;
    for (int i=0;i<n;i++)
        cin >>a[i];
    double low=0.0000000001,high=1e12,mid,ans;
    pair<double,long long> p;
    while (high-low>=0.000000000001)
    {
        mid= (low+high)/2.0;
        long long cnt=0;
        double cur=0;
        for (int i=0;i<n;i++)
        {
            double ans1= (4*a[i]);
            ans1/=mid;
            ans1++;
            ans1= sqrt(ans1);
            ans1--;
            ans1/=2.0;
            ans1= ceil(ans1);
            long long ans2=ans1;
            cnt+=ans2;
            double x=ans1;
            cur+= (double)((double)(a[i])/(double)(x));
        }
        if (cnt<=k)
        {
            ans=cur;
            p={mid,k-cnt};
            high=mid;
        }
        else
        {
            low=mid;
        }
    }
    ans+=0.5;
    cout <<(long long)ans;
    return 0;
}
