#include<bits/stdc++.h>
using namespace std;

char in[55][55];
char in2[55][55];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int r,c,q;
		scanf("%d %d %d",&r,&c,&q);
		for(int a=0;a<r;a++) scanf("%s",in[a]);
		int r1,c1;
		for(int q1=0;q1<q;q1++)
		{
			scanf("%d %d",&r1,&c1);
			for(int a=0;a<r1;a++) scanf("%s",in2[a]);
			bool ada = false;
			for(int a=-r1;a<r;a++)
			{
				for(int b=-c1;b<c;b++)
				{
					bool isdiff = false;
					for(int d=0;d<r1;d++)
					{
						for(int e=0;e<c1;e++) 
						{
							if(a+d < 0 || b + e < 0)
							{
								if(in2[d][e] == '*') isdiff = true;
							}
							else if(a + d >= r || b + e >= c)
							{
								if(in2[d][e] == '*') isdiff = true;
							}
							else if(in[a+d][b+e] != in2[d][e] && in2[d][e] == '*') isdiff = true;
						}
					}
					if(isdiff == false) ada = true;
				}
			}
			printf("%s\n",(ada==true)?"Yes":"No");
		}
		printf("\n");
	}
}
