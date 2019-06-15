#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	int tot = 0;
	while(tc--)
	{
		double l,w,d,we;
		cin>>l>>w>>d>>we;
		int ans = 0;
		if( (l <= 56 && w <= 45 && d <= 25 || l + w + d <= 125) && we <= 7) ans = 1;
		cout<<ans<<endl;
		tot+=ans;
	}
	cout<<tot<<endl;
}
