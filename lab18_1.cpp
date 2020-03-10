#include<iostream>
#include<cmath>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect,Rect);

Rect R1 ,R2 ;
//Rect R1[4], R2[4];
int main(){
	cout << "Please input Rect 1 (x y w h): ";
	cin >> R1.x >> R1.y >> R1.w >> R1.h ;
	/*for (int i = 0; i < 4; i++){
		cin >> R1[i] ; 
	}*/
	cout << "Please input Rect 2 (x y w h): ";
	cin >> R2.x >> R2.y >> R2.w >> R2.h ;
	/*for (int j = 0; j < 4; j++){
		cin >> R2[j] ; 
	}*/
	cout << "Overlap area = " << overlap(R1,R2) ;	
	return 0;
}


double overlap(Rect a, Rect b){
//	return ((a.y+a.h)-((b.y+b.h)));
	Rect lap;
	double wNew, hNew, xNew , yNew ; 
	// ( (a.x)(a.y)    , (a.x+a.w)(a.y))         ( (b.x)(b.y)    , (b.x+b.w)(b.y))
	// ( (a.x)(a.y+a.h), (a.x+a.w)(a.y+a.h)      ( (b.x)(b.y+b.h), (b.x+b.w)(b.y+b.h)
	// 
	//============ w overlap ================
	// ขอบเขตล่างของ x = max(x1,x2)
	// ขอบเขตบนของ x = min(x1+w1, x2+w2)
	//============ h overlap ================
	// ขอบเขตล่างของ y = max(y1,y2)
	// ขอบเขตบนของ y = min(y1+h1, y2+h2)
	  
if (b.x < a.x+a.w)
{
	//บน
//จุด แรก
if (a.x<b.x){ lap.x = b.x ; } else { lap.x = a.x ;}
//จุด สอง 
if ((a.x+a.w)<(b.x+b.w)) { wNew = a.x+a.w ;} else { wNew = b.x+b.w ;}
xNew=wNew-lap.x;

//ข้าง (แกน y)
//จุด แรก
if (a.y<b.y){ lap.y = a.y ; } else { lap.y = b.y ;}
//จุด สอง 
if ((a.y-a.h)<(b.y-b.h)) { hNew = b.y-b.h ;} else { hNew = a.y-a.h ;}
yNew=hNew-lap.y;

return abs(xNew*yNew);
} else
{
	return 0;
}




}