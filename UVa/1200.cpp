#include<bits/stdc++.h>
using namespace std;

bool op(char a)
{
	if(a=='+') return true;
	if(a=='-') return true;
	if(a=='=') return true;
	return false;
}

char in[150000];

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",in);
		int len = strlen(in);
		int xx = 0;
		int yy = 0;
		int multi = 1;
		int ll = 1;
		int val = 0;
		bool isx = false;
		bool isop = true;
		for(int a=0;a<len;a++)
		{
			if(op(in[a]))
			{
				if(isx==false) yy += multi * ll * val;
				isx = false;
				isop = true;
				val = 0;
				if(in[a]=='-') multi = -1;
				if(in[a]=='+') multi = 1;
				if(in[a]=='=') multi = 1,ll = -1;
			}
			else if(in[a]=='x')
			{
				if(isop == true) val = 1;
				isx = true;
				xx += multi * ll * val;
				isop = false;
			}
			else
			{
				val = val*10 + (in[a]-'0');
				isop = false;
			}
		}
		if(isx==false) yy += multi * ll * val;
		if(xx==0 && yy==0) printf("IDENTITY\n");
		else if(xx==0) printf("IMPOSSIBLE\n");
		else printf("%.0lf\n",floor((double)1.0*yy/-xx));
	}
}
