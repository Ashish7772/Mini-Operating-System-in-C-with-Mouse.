#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>
#include<ballon.h>
#include<qgame.h>
#include<dir.h>
#include<process.h>
void mouseposition();
void folder();
void dater();
void datedisplay();
void date();
void version();
void fun();
void graphics();
void mouseshow();
void getdrive();
void changedir();
void paint();
void get_mouse_pos(int *x,int *y,int *button);
void hide_mouse();
void status();
union REGS in,out;
int main()
{ int x,y=1,a,c,gam;

graphics();
setbkcolor(RED);
settextstyle(4,0,4);
outtextxy(250,150,"Welcome");
outtextxy(290,180,"to");
outtextxy(190,210,"operating system");

delay(2000);
cleardevice();
graphics();
setbkcolor(BLUE);

datedisplay();

gotoxy(18,11);
printf("Ashish Aggarwal");
gotoxy(18,13);
printf("Password ");
scanf("%d",&x);
if(x==1234)
{
 cleardevice();
 gotoxy(35,13);
 printf("Loading");
  gotoxy(30,14);
 while(y<=20)
 {
 printf(":");
 y++;
 delay(200);
 }
 delay(1000);
 cleardevice();
  setbkcolor(RED);
 mouseshow();
 datedisplay();

 gotoxy(1,1);
 printf("Hello,Ashish Aggarwal");
 gotoxy(7,3);
 printf("Choose your choice:");
 gotoxy(8,4);
 printf("1. Date");
 gotoxy(8,5);
 printf("2. Time");
 gotoxy(8,6);
 printf("3. Rename the file");
 gotoxy(8,7);
 printf("4. Getdrive");
 gotoxy(8,8);
 printf("5. Version");
 gotoxy(8,9);
 printf("6.Change Directory");
 gotoxy(8,10);
 printf("7. Search path");
 gotoxy(8,11);
 printf("8. Delete file");
 gotoxy(8,12);
 printf("9.Delete directory");
 gotoxy(8,13);
 printf("10.Copy the file");
 gotoxy(8,14);
 printf("11.Create the folder");
 gotoxy(8,15);
 printf("12.Clear screen");
 gotoxy(8,16);
 printf("13.Paint");
 gotoxy(8,17);
 printf("14.Play Games");
 gotoxy(8,18);
 printf("15.Shutdown the pc");
 gotoxy(8,19);
 printf("16.Restart pc");
 gotoxy(8,20);
 printf("17.Mouse position");
 gotoxy(8,21);
 printf("18.Exit");
 gotoxy(1,23);
 printf("Enter your choice: ");
 scanf("%d",&c);
 switch(c)
 {
 case 1:
 {
 cleardevice();
 gotoxy(1,1);
 date();
 break;
 }
 case 2:
 {
 cleardevice();
 gotoxy(1,1);
 dater();
 break;
 }
 case 4:
 {
 getdrive();
 break;
 }
 case 5:
 {
 cleardevice();
version();
break;
 }
 case 6:
 {
 cleardevice();
 gotoxy(1,1);
 changedir();
 break;
 }
 case 11:
 {
 cleardevice();
 folder();
 break;
 }
 case 12:
 {
 cleardevice();
 gotoxy(23,1);
 printf("Press Enter to Exit");
 break;
 }
 case 13:
 {
 cleardevice();
 paint();
 break;
 }
 case 17:
 {
 mouseposition();
 break;
 }
 case 18:
 {
 exit(1);
 break;
 }

 case 14:
 {
 cleardevice();
    gotoxy(1,1);
 printf("1.Balloon Game.");
 printf("\n2.Quiz Game.");
 printf("\n\nEnter your Choice game:-");
 scanf("%d",&gam);
 switch(gam)
 {
 case 1:
 {
 cleardevice();
 ashish();
 break;
 }
 case 2:
 {
 cleardevice();
 qgame();
 break;
 }
 default :
 {cleardevice();
 printf("You have enter wrong choice press ENTER to exit");
 } }

  }
 }


}
else
{
gotoxy(18,15);
printf("Wrong password");
}

getch();
closegraph();
return 0;
}
void graphics()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\TC\\bgi");
}
void mouseshow()
{in.x.ax=1;
int86(51,&in,&out);}
void hide_mouse()
{
	in.x.ax=2;
	int86(0x33,&in,&out);
}
void get_mouse_pos(int *x,int *y,int *button)
{
	in.x.ax=3;
	int86(0x33,&in,&out);
	*x=out.x.cx;
	*y=out.x.dx;
	*button=out.x.bx&1;
}

 void version()
 {
  gotoxy(2,1);
 printf("OS Version: 1.1");
 printf("\nMade By: Ashish Aggarwal");
 printf("\nContact Us: 9467737772");

 }
 void date()
 {
 struct tm *local,*gm;
time_t t;
t=time(NULL);
local=localtime(&t);
printf("time --> %d:%d:%d\n",local->tm_hour,local->tm_min,local->tm_sec);
printf("date --> %d/%d/%d\n",local->tm_mday,local->tm_mon+1,local->tm_year+1900);
}
void datedisplay()
{
struct tm *local,*gm;
time_t t;
t=time(NULL);
local=localtime(&t);
gotoxy(60,24);
printf("time --> %d:%d:%d\n",local->tm_hour,local->tm_min,local->tm_sec);
gotoxy(60,25);
printf("date --> %d/%d/%d\n",local->tm_mday,local->tm_mon+1,local->tm_year+1900);

}
void dater()
{
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int d,m,y,nd,nm,ny,ndays;
printf("Enter the today Date,Month,Year \n");
scanf("%d%d%d",&d,&m,&y);
gotoxy(1,2);
printf("Today Date is \t\t%d/%d/%d\n",d,m,y);
ndays=month[m-1];
if(m==2)
{
if(y%100==0)
{
if(y%400==0)
ndays=28;
}
else
if(y%4==0)
ndays=29;
}
nd=d+1;
nm=m;
ny=y;
if(nd>ndays)
{
nd=1;
nm++;
}
if(nm>12)
{
nm=1;
ny++;
}
gotoxy(1,3);
printf("Next Days Date is \t %d/%d/%d",nd,nm,ny);
}
void getdrive()
{
char st[80];
clrscr();
getcwd(st,80);
printf("Current Working Directory : %s",st);
}
void changedir()
{
char st[80];
int j;
cleardevice();
printf("Enter path : ");
gets(st);
j=chdir(st);
if(j==0)
printf("Directory Changed");
else
printf("Directory not Changed");
getch();
}
void folder()
{
 int check;
  char *dirname;
  clrscr();
  printf("Enter a directory path and name to be created (C:/name):");
  gets(dirname);
  check = mkdir(dirname);

  if (!check)
  printf("Directory created\n");

 else
 {
   printf("Unable to create directory\n");
   exit(1);  }
  getch();
  system("dir/p");
  getch();
}
void paint()
{
	int gdriver = DETECT, gmode, errorcode,button,x1,y1,x2,y2;
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

	outtextxy(230,400,"Press any key to exit....");
	while(!kbhit())
	{
		mouseshow();
		get_mouse_pos(&x1,&y1,&button);
		x2=x1;
		y2=y1;
		while(button==1)
		{
			hide_mouse();
			line(x1,y1,x2,y2) ;
			x1=x2;
			y1=y2;
			get_mouse_pos(&x2,&y2,&button);
		}
	}
}

void status()
{in.x.ax=0;
int86(51,&in,&out);
}

void mouseposition()
{
 cleardevice();
status();
mouseshow();
in.x.ax=3;
while(!kbhit())
{
int86(51,&in,&out);
switch(out.x.bx)
{
case 1:
{
gotoxy(33,12);
printf("LEFT BUTTON");
gotoxy(35,13);
printf("%d %d",out.x.cx,out.x.dx);
break;
}
case 2:
{
gotoxy(33,12);
printf("RIGHT BUTTON");
gotoxy(35,13);
printf("%d %d",out.x.cx,out.x.dx);
break;
}
case 0:
{
gotoxy(33,12);
printf("NO PRESSED");
gotoxy(35,13);
printf("%d %d",out.x.cx,out.x.dx);
break;
}
}
delay(100);
cleardevice();
}
}