
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy;
   int radius = 25;

	int theta,sx,sy,tx,ty,menu1,x,y,x1,y1,x2,y2,x3,y3,a;



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
   if (errorcode != grOk)  /* an error occurred */
   {
	  printf("Graphics error: %s\n", grapherrormsg(errorcode));
	  printf("Press any key to halt:");
	  getch();
	  exit(1); /* terminate with an error code */
   }

   midx = getmaxx()/2 ;
   midy = getmaxy()/2;
   setcolor(getmaxcolor());

   /* draw the circle */
   circle(midx, midy, radius);
   if(menu1 == 1)
   circle(midx+tx, midy+ty, radius);
   if(menu1 == 2)
   circle(midx*abs(cos(theta))-midy*abs(sin(theta)),midx*sin(theta)+midy*cos(theta),radius);
   if(menu1 == 3)
   circle(midx, midy,radius);



   /* clean up */
   getch();
   closegraph();
   return 0;
}
