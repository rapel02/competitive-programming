#include<bits/stdc++.h>
using namespace std;

int pos[5][5];
pair<int,int> sq[10];

int main()
{
	int x,y,d;
	int w=0;
	for(int a=1;a>=0;a--) sq[w]=make_pair(2,a),w++;
	for(int a=1;a>=0;a--) sq[w]=make_pair(a,0),w++;
	for(int a=1;a<=2;a++) sq[w]=make_pair(0,a),w++;
	for(int a=1;a<=2;a++) sq[w]=make_pair(a,2),w++;
	while(scanf("%d",&x)!=EOF)
	{
		if(x==-1) break;
		scanf("%d %d",&y,&d);
		for(int a=1;a<=8;a++)
		{
			int xx,yy,stt,vx,vy;
			scanf("%d %d %d",&xx,&yy,&stt);
			if(xx>x) vx=2;
			else if(xx==x) vx=1;
			else vx=0;
			if(yy>y) vy=2;
			else if(yy==y) vy=1;
			else vy=0;
			pos[vy][vx]=stt;
			//printf("%d %d\n",vx,vy);
		}
		d=(d+5)%8;
		while(1)
		{
			if(pos[sq[d].first][sq[d].second]==1)
			{
				printf("%d\n",d);
				break;
			}
			d=(d+1)%8;
		}
		
	}
}
