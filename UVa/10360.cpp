#include<bits/stdc++.h>
using namespace std;

long long fieldw[2500][2500];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		long long n,d,y,x,r;
		scanf("%lld",&d);
		scanf("%lld",&n);
		memset(fieldw,0,sizeof(fieldw));
		for(int a=0;a<n;a++)
		{
			scanf("%lld %lld %lld",&x,&y,&r);
			fieldw[y+1][x+1] = r;
		}
		for(int a=0;a<=1025;a++)
		{
			for(int b=0;b<=1025;b++)
			{
				if(a==0 ||b==0)
				{
					fieldw[a][b] = 0;
					continue;
				}
				fieldw[a][b]+=fieldw[a-1][b]; 
				fieldw[a][b]+=fieldw[a][b-1];
				fieldw[a][b]-=fieldw[a-1][b-1];
			}
		}
		long long rangw = 2*d+1;
		long long totw = 0;
		long long kx = 0;
		long long tot=0;
		long long ky = 0;
		for(int a=1;a<=1025;a++)
		{
			for(int b=1;b<=1025;b++)
			{
				int aa = a-rangw;
				int bb= b-rangw;
				if(aa<0) aa = 0;
				if(bb<0) bb=0;
				tot = fieldw[a][b]-fieldw[aa][b]-fieldw[a][bb]+fieldw[aa][bb];
				if(totw<tot)
				{
					totw=tot;
					ky = a-d-1;
					kx = b-d-1;
				}
				if(totw==tot)
				{
					if(kx>b-d-1)
					{
						kx = b-d-1;
						ky = a-d-1;
					}
					else if(kx==b-d-1)
					{
						if(ky>a-d-1)
						{
							ky = a-d-1;
						}
					}
				}
			}
		}
		printf("%lld %lld %lld\n",kx,ky,totw);
	}
}
