#include<bits/stdc++.h>
#define INF 1e+7
#define mp make_pair
#define ff first
#define ss second
using namespace std;

char ff[305][305];

priority_queue<pair<int,pair<int,int> > > pq;

int px[]={0,0,1,-1};
int py[]={1,-1,0,0};

int val[305][305][4];
pair<int,int> st,fs;

bool validate(int a,int b,int aa,int bb)
{
	if(a>aa) swap(a,aa);
	if(b>bb) swap(b,bb);
	if(a==aa)
	{
		for(int c=b;c<=bb;c++)
			if(ff[a][c]=='#') return false;
	}
	else
	{
		for(int c=a;c<=aa;c++)
		{
			if(ff[c][b]=='#') return false;
		}
	}
	return true;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int r,c;
		scanf("%d %d",&r,&c);
		for(int a=0;a<r;a++)
			for(int b=0;b<c;b++) 
				for(int d=0;d<3;d++) val[a][b][d] = INF;
		for(int a=0;a<r;a++)
		{
			scanf("%s",ff[a]);
			for(int b=0;b<c;b++)
			{
				if(ff[a][b]=='S')
					st = mp(a,b);
				if(ff[a][b]=='E')
					fs = mp(a,b);
			}
		}
		val[st.ff][st.ss][0]=val[st.ff][st.ss][1]=val[st.ff][st.ss][2] = 0;
		pq.push(mp(0,mp(st.ff,st.ss)));
		bool found = false;
		while(!pq.empty())
		{
			int posy = pq.top().ss.ff;
			int posx = pq.top().ss.ss;
			int valw = -pq.top().ff;
			pq.pop();
			if(ff[posy][posx]=='#')  continue;
			if(ff[posy][posx]=='E')
			{
				printf("%d\n",valw);
				found=true;
				break;
			}
			int move = (valw%3);
			for(int a=0;a<4;a++)
			{
				int ppx = posx;
				int ppy = posy;
				if(px[a]<0) ppx= ppx+px[a]-move;
				else if(px[a]>0) ppx+=px[a]+move;
				if(py[a]<0) ppy= ppy+py[a]-move;
				else if(py[a]>0) ppy+=py[a]+move;
				if(ppx<0||ppy<0||ppx>=c||ppy>=r) continue;
				if(validate(posy,posx,ppy,ppx)==false) continue;
				if(val[ppy][ppx][move] > valw+1)
				{
					val[ppy][ppx][move] = valw+1;
					pq.push(mp(-val[ppy][ppx][move],mp(ppy,ppx)));
				}
			}
		}
		if(found ==false) printf("NO\n");
		while(!pq.empty()) pq.pop();
	}
}
