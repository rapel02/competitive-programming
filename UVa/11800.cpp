#include<bits/stdc++.h>
using namespace std;

struct Point{
	double x,y;
}p[6],hull[6];

const double PI = acos(-1);

bool cmp(Point a,Point b)
{
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

double cross(Point a,Point b,Point c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void CHULL()
{
	int k = 0;
	sort(p,p+4,cmp);
	for(int a=0;a<4;a++)
	{
		while(k>=2 && cross(hull[k-2],hull[k-1],p[a]) < 0) k--;
		hull[k++] = p[a];
	}
	int t = k+1;
	for(int a=2;a>=0;a--)
	{
		while(k>=t && cross(hull[k-2],hull[k-1],p[a]) < 0) k--;
		hull[k++] = p[a];
	}
	k--;
}

double sqr(double x)
{
	return x*x;
}

double dist(Point a,Point b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

double angle(Point a,Point b,Point c)
{
	double AB = dist(a,b);
	double AC = dist(a,c);
	double BC = dist(b,c);
	return acos( (sqr(AB) + sqr(BC) - sqr(AC)) / (2*AB*BC));
}

bool compare(Point a,Point b,Point c,Point d)
{
	Point w1,w2;
	w1.x = b.x - a.x;
	w1.y = b.y - a.y;
	w2.x = d.x - c.x;
	w2.y = d.y - c.y;
	if(w1.y * w2.x == w1.x * w2.y) return true;
	return false;
}

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    // See http://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    double val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
 
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false; // Doesn't fall in any of the above cases
}

string ans[]={"Ordinary Quadrilateral","Trapezium","Parallelogram","Rhombus","Rectangle","Square"};

int main()
{
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		for(int a=0;a<4;a++) cin>>hull[a].x>>hull[a].y;
		//CHULL();
		sort(hull,hull+4,cmp);
		int value = 0;
		do
		{
			bool err = false;
			for(int a=0;a<2;a++)
			{
				if(doIntersect(hull[a],hull[(a+1)%4],hull[(a+2)%4],hull[(a+3)%4]) == true) err = true;
			}
			//printf("SAFE\n");
			//for(int a=0;a<4;a++) printf("%lf %lf\n",hull[a].x,hull[a].y);
			if(err==true) continue;
			set<double> len,deg;
			for(int a=0;a<4;a++)
			{
				len.insert(dist(hull[a],hull[(a+1)%4]));
				deg.insert(angle(hull[a],hull[(a+1)%4],hull[(a+2)%4]));
			}
			int le = len.size();
			int de = deg.size();
			if(le==1 && de==1) value = max(value,5);
			else if(le==2 && de==1) value = max(value,4);
			else if(le==1 && de==2) value = max(value,3);
			else if(le==2 && de==2) value = max(value,2);
			else
			{
				bool istr = false;
				if(compare(hull[0],hull[1],hull[2],hull[3]) == true) istr = true;
				if(compare(hull[1],hull[2],hull[3],hull[0]) == true) istr = true;
				if(istr == true) value = max(value,1);
			}
		}while(next_permutation(hull,hull+4,cmp));
		printf("Case %d: ",tc);
		cout<<ans[value]<<endl;
	}
}
