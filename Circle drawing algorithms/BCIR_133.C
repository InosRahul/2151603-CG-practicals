#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int main(){
	int xc,yc,r,x=0,y;
	int p0;
	int gdriver = DETECT, gmode, errorcode;


	printf("Enter xc,yc and radius:");
	scanf("%d%d%d",&xc,&yc,&r);


   /* initialize graphics mode */
   initgraph(&gdriver, &gmode, "..\\bgi");

   /* read result of initialization */
   errorcode = graphresult();

   if (errorcode != grOk)  /* an error occurred */
   {
	  printf("Graphics error: %s\n", grapherrormsg(errorcode));
	  printf("Press any key to halt:");
	  getch();
	  exit(1);             /* return with error code */
   }


	y=r;
	p0=1-r;
   putpixel(xc+x,yc+y,15);
   putpixel(xc-x,yc+y,15);
   putpixel(xc+y,yc+x,15);
   putpixel(xc-y,yc-x,15);



	while(y>x)
	{
		if(p0<0)
		{
			p0=p0+4*x+6;
		}
		else
		{
			p0=p0+4*(x-y)+10;
			y=y-1;
		}
		x=x+1;
   putpixel(xc+x,yc+y,15);
   putpixel(xc-x,yc+y,15);
   putpixel(xc+x,yc-y,15);
   putpixel(xc-x,yc-y,15);
   putpixel(xc+y,yc+x,15);
   putpixel(xc-y,yc+x,15);
   putpixel(xc+y,yc-x,15);
   putpixel(xc-y,yc-x,15);
   delay(1);
		}




   /* clean up */
   getch();
   closegraph();
   return 0;
}


