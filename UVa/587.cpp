#include<bits/stdc++.h>
using namespace std;

char in[505];

double dist(double a,double b)
{
	return sqrt(a*a + b*b);
}

int main()
{
	int k = 0;
	double px,py;
	while(1)
	{
		k++;
		px = 0;
		py = 0;
		while(1)
		{
			scanf("%[^.,D]",in);
			char tp = getchar();
			if(tp=='D')
			{
				return 0;
			}
			else
			{
				int len = strlen(in);
				int tot = 0;
				bool ch = false;
				for(int a=0;a<len;a++)
				{
					if(in[a]<'0' || in[a]>'9') ch = true;
					if(ch==false)
					{
						tot = tot*10 + (in[a]-'0');
					}
					else
					{
						if(a==len-1)
						{
							if(in[a]=='N')	py += tot;
							else if(in[a]=='S')	py -= tot;
							else if(in[a]=='E')	px += tot;
							else	px -= tot;
							break;
						}
						else
						{
							double multi = 1.0 / sqrt(2);
							if(in[a]=='N') 	py += tot*multi;
							else if(in[a]=='S') py -= tot*multi;
							if(in[a+1] == 'E') px += tot*multi;
							else if(in[a+1]=='W') px -= tot*multi;
							break;
						}
					}
				}
				if(tp=='.')
				{
					printf("Map #%d\n",k);
					printf("The treasure is located at (%.3lf,%.3lf).\n",px,py);
					printf("The distance to the treasure is %.3lf.\n\n",dist(px,py));
					getchar();
					break;
				}
			}
		}
	}
}
