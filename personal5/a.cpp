//chu是除数，yu是余数
//注意只适用于除数两两互质
#include<iostream>  
#include<queue>  
using namespace std;  
typedef long long ll;
ll extended_euclid(ll a, ll b, ll &x, ll &y) {
    ll d;
    if(b == 0) {x = 1; y = 0; return a;}
    d = extended_euclid(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
ll chinese_remainder(ll b[], ll w[], ll len) { 
    ll i, d, x, y, m, n, ret;
    ret = 0; n = 1; 
    for(i=0; i < len ;i++) n *= w[i];
    for(i=0; i < len ;i++) { 
        m = n / w[i];
        d = extended_euclid(w[i], m, x, y);
        ret = (ret + y*m*b[i]) % n;
    }
    return (n + ret%n) % n;
}
ll yu[100],chu[100];
int main()
{
	ll n;
	while(cin>>n)
	{
		for(ll i=0;i<n;i++)
		{
			cin>>chu[i]>>yu[i];
		}
		ll ans=chinese_remainder(yu,chu,n);
		cout<<ans<<endl;
	}
	return 0;
}
