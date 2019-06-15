#include<bits/stdc++.h>
using namespace std;

int counts;
int pos[10];
int r,c;
bool canput(int a,int b)
{
	for(int w = 1;w<b;w++)
	{
		if(pos[w]==a || (abs(pos[w] - a) == abs(w - b))) return false;
	}
	return true;
}

void placing(int id)
{
	if(id==9 && pos[r] == c)
	{
		printf("%2d     ",++counts);
		for(int a=1;a<=8;a++)
		{
			printf(" %d",pos[a]);
		}
		printf("\n");
		return ;
	}
	for(int a=1;a<=8;a++)
	{
		if(canput(a,id)==true)
		{
			pos[id] = a;
			placing(id+1);
			pos[id] = 0;
		}
	}
}


int main()
{
	int tc;
	scanf("%d",&tc);
	bool first = true;
	while(tc--)
	{
		scanf("%d %d",&r,&c);
		if(first==false) printf("\n");
		first = false;
		counts = 0;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		placing(1);
	}
}
