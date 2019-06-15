#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<double> c,d,e,k;

double Det(vector<double> r1,vector<double> r2,vector<double> r3)
{
	double x1 = r1[0] *r2[1] * r3[2];
	double x2 = r2[0] *r3[1] * r1[2];
	double x3 = r3[0] *r1[1] * r2[2];
	double y1 = r3[0] *r2[1] * r1[2];
	double y2 = r1[0] *r3[1] * r2[2];
	double y3 = r2[0] *r1[1] * r3[2];
	return (x1 + x2 + x3) - (y1 + y2 + y3);
}

char chara(double x)
{
	if(x< 0) return '-';
	return '+';
}

int main()
{
	double Ax,Ay,Bx,By,Cx,Cy;
	while(cin>>Ax>>Ay>>Bx>>By>>Cx>>Cy)
	{
		c.clear(),d.clear(),e.clear(),k.clear();
		c.pb(Ax);
		c.pb(Bx);
		c.pb(Cx);
		d.pb(Ay);
		d.pb(By);
		d.pb(Cy);
		e.pb(1);
		e.pb(1);
		e.pb(1);
		k.pb(-(Ax*Ax + Ay*Ay));
		k.pb(-(Bx*Bx + By*By));
		k.pb(-(Cx*Cx + Cy*Cy));
		double cc = Det(k,d,e) / Det(c,d,e);
		double dd = Det(c,k,e) / Det(c,d,e);
		double ee = Det(c,d,k) / Det(c,d,e);
		double x = cc/2;
		double y = dd/2;
		double re = -ee + x*x + y*y;
		printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n",chara(x),fabs(x),chara(y),fabs(y),sqrt(re));
		printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n\n",chara(cc),fabs(cc),chara(dd),fabs(dd),chara(ee),fabs(ee));
	}
}
