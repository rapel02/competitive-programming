#include<bits/stdc++.h>
using namespace std;

struct point{
	double x,y;
}p[950];

double grad(point a,point b)
{
	if(a.x == b.x) return 1e+10;
	return (b.y - a.y) / (b.x - a.x);
}

int main()
{
	int tc;
	cin>>tc;
	getchar();
	getchar();
	string s;
	for(int ntc = 1;ntc<=tc; ntc++)
	{
		if(ntc!=1) printf("\n");
		int n = 0;
		while(getline(cin,s))
		{
			if(s.length() == 0) break;
			stringstream ss(s);
			ss>>p[n].x>>p[n].y;
			n++;
		}
		int maxi = 0;
		for(int a=0;a<n;a++)
		{
			map<double,int> mgrad;
			for(int b=0;b<n;b++)
			{
				if(b==a) continue;
				double dg = grad(p[a],p[b]);
				mgrad[dg]++;
				maxi = max(maxi,mgrad[dg]);
			}
		}
		cout<<maxi+1<<endl;
	}
}
