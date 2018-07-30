#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main(){
	 int gdriver = DETECT, gmode, errorcode;
	 int x1,y1,x2,y2,dx,dy,steps,slope,k;
	 float x3,y3,xincrement,yincrement;
	clrscr();
	printf("Enter values of x1 and x2:");
	scanf("%d %d",&x1,&x2);
	printf("\nEnter values of y1 and y2:");
	scanf("%d %d",&y1,&y2);

/* initialize graphics mode */
initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

/* read result of initialization */
errorcode = graphresult();

if (errorcode != grOk)  /* an error occurred */
{
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1);             /* return with error code */
}
	if(x1 < x2){
		x3 = x1;
		y3 = y1;
	}
	else{
		x3 = x2;
		y3 = y2;
	}



	dx = x2 - x1;
	dy = y2 - y1;

	//slope = dy/dx;
	//printf("Slpoe is %d",slope);
	if(abs(dx) > abs(dy)){
		steps = abs(dx);
	}
	else{
		steps = abs(dy);
	}
	xincrement = dx/(float)steps;
	yincrement = dy/(float)steps;

	//setpixel(x,y,15);
	for(k=0; k<steps; k++){
		x3 =x3+xincrement;
		y3 =y3+yincrement;
		putpixel((int)ceil(x3),(int)ceil(y3),15);

	}
getch();
closegraph();
getch();

}
