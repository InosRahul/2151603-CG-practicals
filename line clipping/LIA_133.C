#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void main(void)
{
	float x1,x2,xmin,xmax,y1,y2,ymin,ymax,dx=0,dy=0;
	float a=0,b=0,c=0,d=0;
	float u1,u2;
	float p[5],q[5],r[5];
	int i,j,k;
	int gdriver = DETECT, gmode, errorcode;
	clrscr();
	printf("Enter x1,y1,x2 & y2:");
	scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
	printf("Enter xmin, ymin, xmax & ymax:");
	scanf("%f%f%f%f",&xmin,&ymin,&xmax,&ymax);




/* initialize graphics and local variables */
initgraph(&gdriver, &gmode, "..\\bgi");

/* read result of initialization */
errorcode = graphresult();
/* an error occurred */
if (errorcode != grOk)
{
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1);
}

setcolor(getmaxcolor());


/* draw a diagonal line */
line(xmin, ymax, xmax, ymax);
line(xmin, ymax, xmin, ymin);
line(xmin, ymin, xmax, ymin);
line(xmax, ymax, xmax, ymin);
line(x1,y1,x2,y2);





	dx = x2 - x1;
	dy = y2 - y1;

	p[0] = -dx;
	p[1] = dx;
	p[2] = -dy;
	p[3] = dy;

	q[0] = x1 - xmin;
	q[1] = xmax - x1;
	q[2] = y1 - ymin;
	q[3] = ymax - y1;


	for(i=0;i<4;i++){
		r[i] = q[i]/p[i];
		}
	u1 = 0;
	for(i=0;i<4;i++){
		if(p[i] < 0){
			//printf("\nvalues of r %f:",r[i]);
			if(r[i] > u1){
				u1 = r[i];
			}

		}
	}
	u2 = 1;
	for(i=0;i<4;i++){
		if(p[i] > 0){
			//printf("\nValues of r: %f",r[i]);
			if(r[i] < u2){
				u2 = r[i];
			}

		}
	}
	//printf("\n Value of u1 and u2 is %f %f:",u1,u2);

	a = x1 + u1*dx;
	b = y1 + u1*dy;
	c = x1 + u2*dx;
	d = y1 + u2*dy;

	//printf("\n Values of point a and b %f %f",a,b);
	//printf("\n Values of point c and d %f %f",c,d);
clearviewport();
line(xmin, ymax, xmax, ymax);
line(xmin, ymax, xmin, ymin);
line(xmin, ymin, xmax, ymin);
line(xmax, ymax, xmax, ymin);
line(a,b,c,d);

/* clean up */

getch();
closegraph();
getch();
}
