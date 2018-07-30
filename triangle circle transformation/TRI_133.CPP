
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax;
   int theta,sx,sy,tx,ty,menu1,x,y,x1,y1,x2,y2,x3,y3;
   int a;


   printf("Select operations:");
   printf("\n 1. Translation \n 2. Rotation \n 3. Scaling");
   scanf("%d",&menu1);
   switch(menu1)
   {
	case 1:  {
		printf("Enter tx and ty:");
		scanf("%d %d", &tx,&ty);
		break;

 }
	case 2: {
		printf("Enter theta:");
		scanf("%d",&theta);
		theta = (3.14 * theta)/180;
		a = theta;
		break;


	}
	case 3: {
		printf("Enter sx and sy:");
		scanf("%d %d", &sx,&sy);
		break;

	}

 }




   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C:\\TC\\bgi");

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
   xmax = getmaxx();
   ymax = getmaxy();

   /* draw a diagonal line */
   line(100, 50, 50, 200);
   line(50,200,150,200);
   line(100,50,150,200);
   if(menu1==1){

   x1 = 100+tx;
   y1 = 50+ty;
   x2 = 50+tx;
   y2 = 200+ty;
   x3 = 150+tx;
   y3 = 200+ty;

   line(x1,y1,x2,y2);
   line(x2,y2,x3,y3);
   line(x3,y3,x1,y1);
   }
   if(menu1==2){

   x1 = 100*cos(a) - 50*sin(a);
   y1 = 100*sin(a) + 50*cos(a);
   x2 = 50*cos(a) - 200*sin(a);
   y2 = 50*sin(a) + 200*cos(a);
   x3 = 150*cos(a) - 200*sin(a);
   y3 = 150*sin(a) + 200*cos(a);

   line(x1,y1,x2,y2);
   line(x2,y2,x3,y3);
   line(x3,y3,x1,y1);

   }
   if(menu1==3){

   x1 = 100*sx;
   y1 = 50*sy;
   x2 = 50*sx;
   y2 = 200*sy;
   x3 = 150*sx;
   y3 = 200*sy;

   line(x1,y1,x2,y2);
   line(x2,y2,x3,y3);
   line(x3,y3,x1,y1);



   }



   /* clean up */
   getch();
   closegraph();
   return 0;
}
