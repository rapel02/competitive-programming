#include<bits/stdc++.h>
using namespace std;

int arr[70];
bool stt[10005];
int age[10005];

int main()
{
	int b,s;
	int k = 0;
	while(1)
	{
		k++;
		memset(arr,0,sizeof(arr));
		scanf("%d %d",&b,&s);
		if(b+s==0) break;
		for(int a=0;a<b;a++)
		{
			scanf("%d",&age[a]);
			stt[a] = false;
		}
		for(int a=0;a<s;a++)
		{
			int t;
			scanf("%d",&t);
			arr[t]++;
		}
		sort(age,age+b);
		
		for(int c=b-1;c>=0;c--)
		{
			for(int a=0;a<=60;a++)
			{
				if(stt[c]==true) break;
				if(age[c]+a<=60)
				{
					if(arr[age[c]+a]>0)
					{
						//printf("%d %d\n",age[c],age[c]+a);
						stt[c] = true;
						arr[age[c]+a]--;
						break;
					}
				}
				if(age[c]-a>=0)
				{	
					if(arr[age[c]-a]>0)
					{
						//printf("%d %d\n",age[c],age[c]-a);
						stt[c] = true;
						arr[age[c]-a]--;
						break;
					}
				}
			}
		}
		int ans = 0;
		int t = 0;
		for(int a=0;a<b;a++)
		{
			if(stt[a]==false)
			{
				if(ans==0) ans = age[a];
				ans = min(ans,age[a]);
				t++;
			}
		}
		if(ans!=0) printf("Case %d: %d %d\n",k,t,ans);
		else printf("Case %d: %d\n",k,ans);
	}
}
