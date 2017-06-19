#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<dos.h>
int r=20,p1=12,p2=12,a[10][10],b[2000],t=0,f=0,m,n,x,y,c,l=6,q=0,p=0,v[2000];
int z=0,s=0,menut=0,esc=0,nr=0,draw=0,time=200,res=0;
 void resume();
 void loadin();
 void menu();
 void glow(int,int);
 void box(int,int);
 void norm_box(int,int);
 void rules();
 void board();
 void cp1(int,int);
 void cp2(int,int);
 void cps();
 int validity();
 void ini_pos();
 int plyr1validity();
 int plyr2validity();
 void movecp(int,int,int,int);
 void replay();
 void gamedriver();

 void loadin()
 {
  int i;
  setcolor(6);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
  outtextxy(110,70,"CHINESE CHECKERS ");
  settextstyle(SMALL_FONT,HORIZ_DIR,3);
  outtextxy(275,280,"Loading");
  for(i=0;i<400;i++)
  {
  setcolor(6);
  if(i%4==0)
  setcolor(4);
  outtextxy(100+i,300,"/");
  outtextxy(95+i,305,"/");
  if(i==130)
  outtextxy(330,280,".");
  if(i==260)
  outtextxy(335,280,".");
  if(i==350)
  outtextxy(340,280,".");
  delay(15);
  }
  delay(300);
  }
  void resume()
  {
  cleardevice();
  int i=0,j=0;
  board();
  for(i=1;i<9;i++)
 for(j=1;j<9;j++)
 {
 if(a[i][j]!=0)
 {
 if(a[i][j]/100==1)
 cp1(29+(i-1)*50,29+(j-1)*50);
 else if(a[i][j]/100==2)
 cp2(29+(i-1)*50,29+(j-1)*50);
 }
 }
 if(res==1)
 glow(m,n);
 else if(res==2)
 glow(x,y);
 }

  void menu()                  //Prints the menu
  {
  void gamedriver(void);
  void main(void);
   clrscr();
   cleardevice();
   p1=12;
   p2=12;
   int ch;
   settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
  outtextxy(110,70,"CHINESE CHECKERS ");
  cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
  cout<<"                      "<<"1. Play Game "<<endl;
  cout<<"                      "<<"2. Exit "<<endl;
  if(esc!=0)
  cout<<"                      "<<"3. Resume"<<endl<<endl<<endl;
  cout<<endl<<endl<<"                      Option : ";
  cin>>ch;
  if(ch==1)
  {
  menut=1;
  p=0;
  main();
  }
  if(ch==2)
  exit(0);
  if(ch==3)
  resume();
   else
  {
  cleardevice();
  menu();
  }
}
 void glow(int m,int n)                               //to highlight a box
{ setcolor(3);
  setlinestyle(SOLID_LINE,1,3);
  rectangle((m-1)*50+4,(n-1)*50+4,m*50+4,n*50+4);
}
void box(int m, int n)                                //to make border colour white
{
 setcolor(15);
 setlinestyle(SOLID_LINE,1,3);
 rectangle((m-1)*50+4,(n-1)*50+4,m*50+4,n*50+4);
 }
void norm_box(int m, int n)                            //to bring a checker box back to normal
{
 glow(m,n);
 setfillstyle(SOLID_FILL,0);
 floodfill((m-1)*50+10,(n-1)*50+10,3);
 box(m,n);
}
void rules()                                      //rules of checkers
{
  int a=getmaxx()/2,b=getmaxy()/2-30;
  int c=a-130;
  setcolor(1);
  setlinestyle(SOLID_LINE,1,3);
  rectangle(a-150,b-200,a+150,a+150);
  setfillstyle(SOLID_FILL,0);
  floodfill(a,b,1);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,0);
  setusercharsize(5,5,5,5);
  outtextxy(a-20,b-190,"RULES");
  outtextxy(c,b-180,"Rule 1:");
  outtextxy(c,b-170,"A player can move in two ways.");
  outtextxy(c,b-160,"A piece can be moved forward, ");
  outtextxy(c,b-150,"diagonally,to the very next dark");
  outtextxy(c,b-140,"square.In some variants,if one");
  outtextxy(c,b-130,"player's piece,the other player's");
  outtextxy(c,b-120,"piece, and an empty square are" );
  outtextxy(c,b-110,"lined up, then the first player");
  outtextxy(c,b-100,"must 'jump' the other player's");
  outtextxy(c,b-90,"square.");
  outtextxy(c,b-70,"Rule 2: ");
  outtextxy(c,b-60,"A player can also use one piece");
  outtextxy(c,b-50,"to make multiple jumps in any one ");
  outtextxy(c,b-40,"single turn, provided each jump ");
  outtextxy(c,b-30,"continues to lead immediately into");
  outtextxy(c,b-20,"the next jump and in a straight");
  outtextxy(c,b-10,"line. Sometimes a player may have");
  outtextxy(c,b,"the option or a choice of which");
  outtextxy(c,b+10,"opponent piece he must jump. In");
  outtextxy(c,b+20,"such cases, he may then choose");
  outtextxy(c,b+30,"which to jump.");
  outtextxy(c,b+50,"Rule 3:");
  outtextxy(c,b+60,"If a player's piece moves into the");
  outtextxy(c,b+70,"King Row on the other player's");
  outtextxy(c,b+80,"side, it becomes a king. It can");
  outtextxy(c,b+90,"move forward and backward. (Regular");
  outtextxy(c,b+100,"pieces can only move forward.)");
  outtextxy(c,b+110,"A king cannot jump out of the King");
  outtextxy(c,b+120,"Row until the next turn.");
  outtextxy(c,b+140,"Rule 4:");
  outtextxy(c,b+150,"The first player who cannot move");
  outtextxy(c,b+160,"loses. So if a player loses all of");
  outtextxy(c,b+170,"his pieces, he loses the game. And");
  outtextxy(c,b+180,"if he cannot move, he loses (even");
  outtextxy(c,b+190,"if he has pieces). A player may");
  outtextxy(c,b+200,"also resign (choose to lose). If");
  outtextxy(c,b+210,"nobody can lose, the game is a draw.");
  outtextxy(c,b+230,"Click any key to begin the game!!");
getch();
}
void board()                                            //to print the checker board
{
 int i,j,g=50,s=4,k=15;
  cleardevice();
  setbkcolor(0);
  setcolor(k);
  setlinestyle(SOLID_LINE,1,3);
  rectangle(427,2,getmaxx()-3,272);
  rectangle(427,277,getmaxx()-3,408);
  rectangle(0,0,408,408);
  setfillstyle(SOLID_FILL,8);
  floodfill(450,200,15);
  setfillstyle(SOLID_FILL,0);
  floodfill(450,400,15);
for(j=0;j<8;j++)
 for(i=0;i<8;i++)
 {
   rectangle(i*g+s,j*g+s,i*g+g+s,j*g+g+s);
    if(j%2!=0)
     {
      if(i%2==0)
       {
	setfillstyle(SOLID_FILL,6);
	floodfill((i*g+s)+5,(j*g+s)+5,k);
	}
  }
     if(j%2==0)
     {
      if(i%2!=0)
       {
	setfillstyle(SOLID_FILL,6);
	floodfill((i*g+s)+5,(j*g+s)+5,k);
	}
      }
}
 settextstyle(0,0,1);
outtextxy(413,27,"1");
outtextxy(413,77,"2");
outtextxy(413,127,"3");
outtextxy(413,177,"4");
outtextxy(413,227,"5");
outtextxy(413,277,"6");
outtextxy(413,327,"7");
outtextxy(413,377,"8");
outtextxy(27,414,"1");
outtextxy(77,414,"2");
outtextxy(127,414,"3");
outtextxy(177,414,"4");
outtextxy(227,414,"5");
outtextxy(277,414,"6");
outtextxy(327,414,"7");
outtextxy(377,414,"8");
}
void cp1(int x,int y)         //player 1's checker piece
{
  int k=1;
  setcolor(k);
  setlinestyle(SOLID_LINE,1,1);
  circle(x,y,r);
  setfillstyle(SOLID_FILL,1);
  circle(x,y,r-10);
  floodfill(x,y,k);
  setfillstyle(INTERLEAVE_FILL,1);
  floodfill(x,y-15,k);
}
void cp2(int x,int y)         //player 2's checker piece
{
  int k=4;
  setcolor(k);
  setlinestyle(SOLID_LINE,1,1);
  circle(x,y,r);
  setfillstyle(SOLID_FILL,4);
  circle(x,y,r-10);
  floodfill(x,y,k);
  setfillstyle(INTERLEAVE_FILL,4);
  floodfill(x,y-15,k);
}
void cps()                     //printing the checker pieces
{int j,i,d=25,g=50,m,l=0;
for(j=1;j<9;j++)
 for(i=0;i<8;i++)
  {
   m=d+(j-1)*g+3;
   if(j<4)
    {
     if(j%2!=0 && i%2==0)
      {
	cp1(d+l*g+3,m);
      }
      else if(j%2==0 && i%2!=0)
      {
       cp1(d+l*g+3,m);
      }

     }
   else if(j>5)
    {
     if(j%2==0 && i%2!=0)
      {
       cp2(d+l*g+3,m);
       }
     else if(j%2!=0 && i%2==0)
      {
       cp2(d+l*g+3,m);
     }

    }
l++;
if(i==7)
 l=0;
 }
}
int validity()                       //checking validity of positions
 {
if(a[x][y]!=0 || a[m][n]==0)
  return 0;
  return 1;
}
void ini_pos()                    //to initialise intial positions
{
  int i=0,j=0;
  a[0][0]=0;
for(i=1;i<10;i++)
 for(j=1;j<10;j++)
 {
  a[i][j]=0;
if(j<4)
  {
  if( ((j%2!=0) && (i%2!=0)) || ((j%2==0) &&(i%2==0)) )
  a[i][j]=100+i*10+j;
  }
else if(j>5)
   {
   if( ((j%2!=0) && (i%2!=0)) || ((j%2==0) &&(i%2==0)) )
   a[i][j]=200+i*10+j;
   }
 }
}
int plyr1validity()    //to check for invalid jumps made by player 1
{
   if(x==m-2 && y==n+2 && a[m-1][n+1]/100==2)
   {

   a[m-1][n+1]=0;
   norm_box(m-1,n+1);
   p2--;
   return 1;
   }
else if(x==m-4 && y==n+4 && a[m-1][n+1]/100==2 && a[m-3][n+3]/100==2 && a[m-2][n+2]==0)
   {
   a[m-1][n+1]=0;
   a[m-3][n+3]=0;
   norm_box(m-1,n+1);
   norm_box(m-3,n+3);
   p2=p2-2;
   return 1;
   }
 else if(x==m-6 && y==n+6 && a[m-1][n+1]/100==2 && a[m-3][n+3]/100==2 && a[m-5][n+5]/100==2 && a[m-2][n+2]==0 && a[m-4][n+4]==0)
   {
   a[m-1][n+1]=0;
   a[m-3][n+3]=0;
   a[m-5][n+5]=0;
   norm_box(m-1,n+1);
   norm_box(m-3,n+3);
   norm_box(m-5,n+5);
   p2=p2-3;
   return 1;
   }
else if(x==m-2 && y==n+6 && a[m-1][n+1]/100==2 && a[m-3][n+3]/100==2 && a[m-3][n+5]/100==2 && a[m-2][n+2]==0 && a[m-4][n+4]==0)
{
a[m-1][n+1]=0;
a[m-3][n+3]=0;
a[m-3][n+5]=0;
norm_box(m-1,n+1);
norm_box(m-3,n+3);
norm_box(m-3,n+5);
p2=p2-3;
   return 1;
}
if(x==m && y==n+4 && a[m-1][n+1]/100==2 && a[m-1][n+3]/100==2 && a[m-2][n+2]==0)
{
a[m-1][n+1]=0;
a[m-1][n+3]=0;
norm_box(m-1,n+1);
norm_box(m-1,n+3);
   p2=p2-2;
   return 1;
}
else if(x==m-2 && y==n+6 && a[m-1][n+1]/100==2 && a[m-1][n+3]/100==2 && a[m-1][n+5]/100==2 && a[m-2][n+2]==0 && a[m][n+4]==0)
{
a[m-1][n+1]=0;
a[m-1][n+3]=0;
a[m-1][n+5]=0;
norm_box(m-1,n+1);
norm_box(m-1,n+3);
norm_box(m-1,n+5);
   p2=p2-3;
   return 1;
}
else if(x==m+2 && y==n+6 && a[m-1][n+1]/100==2 && a[m-1][n+3]/100==2 && a[m+1][n+5]/100==2 && a[m-2][n+2]==0 && a[m][n+4]==0)
{
a[m-1][n+1]=0;
a[m-1][n+3]=0;
a[m+1][n+5]=0;
norm_box(m-1,n+1);
norm_box(m-1,n+3);
norm_box(m+1,n+5);
   p2=p2-3;
   return 1;
}
 else if(x==m+2 && y==n+2 && a[m+1][n+1]/100==2)
   {
   a[m+1][n+1]=0;
   norm_box(m+1,n+1);
   p2--;
   return 1;
   }
else if(x==m+4 && y==n+4 && a[m+1][n+1]/100==2 && a[m+3][n+3]/100==2 && a[m+2][n+2]==0)
   {
    a[m+1][n+1]=0;
   a[m+3][n+3]=0;
   norm_box(m+1,n+1);
   norm_box(m+3,n+3);
   p2=p2-2;
   return 1;
   }
 else if(x==m+6 && y==n+6 && a[m+1][n+1]/100==2 && a[m+3][n+3]/100==2 && a[m+5][n+5]/100==2 && a[m+2][n+2]==0 && a[m+4][n+4]==0)
   {
    a[m+1][n+1]=0;
   a[m+3][n+3]=0;
   a[m+5][n+5]=0;
   norm_box(m+1,n+1);
   norm_box(m+3,n+3);
   norm_box(m+5,n+5);
   p2=p2-3;
   return 1;
   }
else if(x==m+2 && y==n+6 && a[m+1][n+1]/100==2 && a[m+3][n+3]/100==2 && a[m+3][n+5]/100==2 && a[m+2][n+2]==0 && a[m+4][n+4]==0)
{
a[m+1][n+1]=0;
a[m+3][n+3]=0;
a[m+3][n+5]=0;
norm_box(m+1,n+1);
norm_box(m+3,n+3);
norm_box(m+3,n+5);
   p2=p2-3;
   return 1;
}
else if(x==m && y==n+4 && a[m+1][n+1]/100==2 && a[m+1][n+3]/100==2 && a[m+2][n+2]==0)
{
a[m+1][n+1]=0;
a[m+1][n+3]=0;
norm_box(m+1,n+1);
norm_box(m+1,n+3);
   p2=p2-2;
   return 1;
}
else if(x==m-2 && y==n+6 && a[m+1][n+1]/100==2 && a[m+1][n+3]/100==2 && a[m-1][n+5]/100==2 && a[m+2][n+2]==0 && a[m][n+4]==0)
{
a[m+1][n+1]=0;
a[m+1][n+3]=0;
a[m-1][n+5]=0;
norm_box(m+1,n+1);
norm_box(m+1,n+3);
norm_box(m-1,n+5);
   p2=p2-3;
   return 1;
}
else if(x==m+2 && y==n+6 && a[m+1][n+1]/100==2 && a[m+1][n+3]/100==2 && a[m+1][n+5]/100==2 && a[m+2][n+2]==0 && a[m][n+4]==0 && a[m+2][n+6]==0)
{
a[m+1][n+1]=0;
a[m+1][n+3]=0;
a[m+1][n+5]=0;
norm_box(m+1,n+1);
norm_box(m+1,n+3);
norm_box(m+1,n+5);
p2=p2-3;
return 1;
}
else if(x==m-1 && y==n+1)
return 1;
else if(x==m+1 && y==n+1)
return 1;
else
return 0;
}
int plyr2validity()   //to check for invalid jumps made by player 2
{
if(x==m-2 && y==n-2 && a[m-1][n-1]/100==1)
{
a[m-1][n-1]=0;
norm_box(m-1,n-1);
p1--;
return 1;
}
else if(x==m-4 && y==n-4 && a[m-1][n-1]/100==1 && a[m-3][n-3]/100==1 && a[m-2][n-2]==0)
{
a[m-1][n-1]=0;
a[m-3][n-3]=0;
norm_box(m-1,n-1);
norm_box(m-3,n-3);
p1=p1-2;
return 1;
}
if(x==m-6 && y==n-6 && a[m-1][n-1]/100==1 && a[m-3][n-3]/100==1 && a[m-5][n-5]/100==1 && a[m-2][n-2]==0 && a[m-4][n-4]==0)
{
a[m-1][n-1]=0;
a[m-3][n-3]=0;
a[m-5][n-5]=0;
norm_box(m-1,n-1);
norm_box(m-3,n-3);
norm_box(m-5,n-5);
p1=p1-3;
return 1;
}
if(x==m-2 && y==n-6 && a[m-1][n-1]/100==1 && a[m-3][n-3]/100==1 && a[m-3][n-5]/100==1 && a[m-2][n-2]==0 && a[m-4][n-4]==0)
{
a[m-1][n-1]=0;
a[m-3][n-3]=0;
a[m-3][n-5]=0;
norm_box(m-1,n-1);
norm_box(m-3,n-3);
norm_box(m-3,n-5);
p1=p1-3;
return 1;
}
if(x==m && y==n-4 && a[m-1][n-1]/100==1 && a[m-1][n-3]/100==1 && a[m-2][n-2]==0)
{
a[m-1][n-1]=0;
a[m-1][n-3]=0;
norm_box(m-1,n-1);
norm_box(m-1,n-3);
p1=p1-2;
return 1;
}
if(x==m-2 && y==n-6 && a[m-1][n-1]/100==1 && a[m-1][n-3]/100==1 && a[m-1][n-5]/100==1 && a[m-2][n-2]==0 && a[m][n-4]==0)
{
a[m-1][n-1]=0;
a[m-1][n-3]=0;
a[m-1][n-5]=0;
norm_box(m-1,n-1);
norm_box(m-1,n-3);
norm_box(m-1,n-5);
p1=p1-3;
return 1;
}
if(x==m+2 && y==n-6 && a[m-1][n-1]/100==1 && a[m-1][n-3]/100==1 && a[m+1][n-5]/100==1 && a[m-2][n-2]==0 && a[m][n-4]==0)
{
a[m-1][n-1]=0;
a[m-1][n-3]=0;
a[m+1][n-5]=0;
norm_box(m-1,n-1);
norm_box(m-1,n-3);
norm_box(m+1,n-5);
p1=p1-3;
return 1;
}
if(x==m+2 && y==n-2 && a[m+1][n-1]/100==1)
{
a[m+1][n-1]=0;
norm_box(m+1,n-1);
p1--;
return 1;
}
if(x==m+4 && y==n-4 && a[m+1][n-1]/100==1 && a[m+3][n-3]/100==1 && a[m+2][n-2]==0)
{
a[m+1][n-1]=0;
a[m+3][n-3]=0;
norm_box(m+1,n-1);
norm_box(m+3,n-3);
p1=p1-2;
return 1;
}
if(x==m+6 && y==n-6 && a[m+1][n-1]/100==1 && a[m+3][n-3]/100==1 && a[m+5][n-5]/100==1 && a[m+2][n-2]==0 && a[m+4][n-4]==0)
{
  a[m+1][n-1]=0;
  a[m+3][n-3]=0;
  a[m+5][n-5]=0;
  norm_box(m+1,n-1);
  norm_box(m+3,n-3);
  norm_box(m+5,n+5);
  p1=p1-3;
  return 1;
  }
if(x==m+2 && y==n-6 && a[m+1][n-1]/100==1 && a[m+3][n-3]/100==1 && a[m+3][n-5]/100==1 && a[m+2][n-2]==0 && a[m+4][n-4]==0)
  {
  a[m+1][n-1]=0;
  a[m+3][n-3]=0;
  a[m+3][n-5]=0;
  norm_box(m+1,n-1);
  norm_box(m+3,n-3);
  norm_box(m+3,n-5);
  p1=p1-3;
  return 1;
  }
if(x==m && y==n-4 && a[m+1][n-1]/100==1 && a[m+1][n-3]/100==1 && a[m+2][n-2]==0)
  {
  a[m+1][n-1]=0;
  a[m+1][n-3]=0;
  norm_box(m+1,n-1);
  norm_box(m+1,n-3);
  p1=p1-2;
  return 1;
  }
if(x==m+2 && y==n-6 && a[m+1][n-1]/100==1 && a[m+1][n-3]/100==1 && a[m+1][n-5]/100==1 && a[m+2][n-2]==0 && a[m][n-4]==0)
  {
  a[m+1][n-1]=0;
  a[m+1][n-3]=0;
  a[m+1][n-5]=0;
  norm_box(m+1,n-1);
  norm_box(m+1,n-3);
  norm_box(m+1,n-5);
  p1=p1-3;
  return 1;
  }
if(x==m-2 && y==n-6 && a[m+1][n-1]/100==1 && a[m+1][n-3]/100==1 && a[m-1][n-5]/100==1 && a[m+2][n-2]==0 && a[m][n-4]==0)
  {
  a[m+1][n-1]=0;
  a[m+1][n-3]=0;
  a[m-1][n-5]=0;
  norm_box(m+1,n-1);
  norm_box(m+1,n-3);
  norm_box(m-1,n-5);
  p1=p1-3;
  return 1;
  }
  else if(x==m-1 && y==n-1)
  return 1;
  else if(x==m+1 && y==n-1)
  return 1;
  else
  return 0;
}

void movecp(int m,int n, int x, int y) //to move a checker piece
{
char choice;
  void gamedriver(void);
if(validity()==0)
  {
  box(m,n);
  if(draw==1)
  { window(55,6,80,15);
  cout<<"Game is a draw";
  window(55,7,80,15);
  cout<<"Do you wish to";
  window(55,8,80,15);
  cout<<"play again? (y/n) ";
  window(55,9,80,15);
  cin>>choice;
  if(choice=='Y'|| choice=='y')
  { nr=0;
  p=0;
  p1=12;
  p2=12;
  s=0;
  q=0;
  z=0;
  draw=0;
  menu();
  }
  else
  {
  cout<<"press any key to exit ";
  getch();
  exit(0);
  }
  }
  window(55,5,80,15);
  cout<<"Invalid move ";
  gamedriver();
  }
 if(s!=0 && p==0)
{
  if(a[m][n]/100==1 && b[q-1]/100==1)
  {
  window(55,5,80,15);
  cout<<"Player 2's turn!!";
  box(m,n);
  gamedriver();
  }
  if(a[m][n]/100==2 && b[q-1]/100==2)
  {
  window(55,5,80,15);
  cout<<"Player 1's turn!!";
  box(m,n);
  gamedriver();
  }
}
if(a[m][n]/100==1)
 if(plyr1validity()==0)
  {
  window(55,5,80,15);
  cout<<"Illegal jump !! ";
  box(m,n);
  gamedriver();
  }
if(a[m][n]/100==2)
 if(plyr2validity()==0)
  {
  window(55,5,80,15);
  cout<<"Illegal jump !! ";
  box(m,n);
  gamedriver();
  }
if(a[m][n]/100==1 )
{
 cp1(29+(x-1)*50,29+(y-1)*50);
 b[q]=100+m*10+n;
 b[q+1]=100+x*10+y;
 a[m][n]=0;
 a[x][y]=100+x*10+y;
 }
else if(a[m][n]/100==2)
{
 cp2(29+(x-1)*50,29+(y-1)*50);
 b[q]=200+m*10+n;
 b[q+1]=200+x*10+y;
 a[m][n]=0;
 a[x][y]=200+x*10+y;
}
  q=q+2;
  s++;
  norm_box(m,n);
if(a[x][y]/100==1)
{
 if(y==8 && (x==2 || x==4 || x==6 ||x==8))
 {
 norm_box(x,y);
 a[x][y]=0;
 delay(500);
 if(a[1][1]/100!=1)
 {
 x=1;
 y=1;
 cp1(29+(x-1)*50,29+(y-1)*50);
 a[x][y]=100+x*10+y;
 }
 else if(a[3][1]/100!=1)
 {
 x=3;
 y=1;
 cp1(29+(x-1)*50,29+(y-1)*50);
 a[x][y]=100+x*10+y;
 }
 else if(a[5][1]/100!=1)
 {
 x=5;
 y=1;
 cp1(29+(x-1)*50,29+(y-1)*50);
 a[x][y]=100+x*10+y;
 }
 else if(a[7][1]/100!=1)
 {
 x=7;
 y=1;
 cp1(29+(x-1)*50,29+(y-1)*50);
 a[x][y]=100+x*10+y;
 }
 else
 p1--;
 }
}
 if(a[x][y]/100==2)
{
 if(y==1 && (x==1 || x==3 || x==5 || x==7))
 {
 norm_box(x,y);
 a[x][y]=0;
 delay(500);
 if(a[2][8]/100!=2)
 {
 x=2;
 y=8;
 cp2(29+(x-1)*50,29+(y-1)*50);
 a[x][y]=200+x*10+y;
 }
 else if(a[4][8]/100!=2)
 {
 x=4;
 y=8;
 cp2(29+(x-1)*50,29+(y-1)*50);
 a[x][y]=200+x*10+y;
 }
 else if(a[6][8]/100!=2)
 {
 x=6;
 y=8;
 cp2(29+(x-1)*50,29+(y-1)*50);
 a[x][y]=200+x*10+y;
 }
 else if(a[8][8]/100!=2)
 {
 x=8;
 y=8;
 cp2(29+(x-1)*50,29+(y-1)*50);
 a[x][y]=200+x*10+y;
 }
 else
 p2--;
 }
 }
 window(55,3,80,15);
  cout<<s<<" "<<p1<<" "<<p2;
 box(m,n);
 box(x,y);
 gamedriver();
}
void replay()                       //to replay the previous game
{
  void main(void);
  void gamedriver(void);
  nr=1;
  p1=12;
  p2=12;
  p=1;
  int i=0;
  for(i=0;i<=2*s;i++)
  v[i]=b[i];
  s=0;
  cleardevice();
  main();
}
void gamedriver()      // function to run the program indefinitely
{

  void main(void);
  char ch;
  int scroll;
  setfillstyle(SOLID_FILL,8);
  floodfill(450,200,15);
  setfillstyle(SOLID_FILL,0);
  floodfill(450,400,15);
if(p1==0)
{ window(55,4,80,15);
 cout<<" player 2 wins !! ";
 cout<<endl;
  window(55,5,80,15);
 cout<<"Do you wish to";
 window(55,6,80,15);
  cout<<"watch the game?";
  window(55,7,80,15);
   cout<<"(y/n) ,Restart(r) ";
    window(55,8,80,15);
 cin>>ch;
 if(ch=='y' || ch=='Y')
 {if(nr!=0)
  {cout<<"YOU CAN DO THIS ONLY ONCE!!! ";
   delay(700);
   menu();
   }
 replay();
 }
 if(ch=='R' || ch=='r')
 {
 nr=0;
 p=0;
 p1=12;
 p2=12;
 s=0;
 q=0;
 z=0;
 main();
 }
 exit(0);
 }
else if(p2==0)
{  window(55,4,80,15);
  cout<<"player 1 wins !! ";
  cout<<endl;
  if(p==0)
  window(55,5,80,15);
  cout<<"Do you wish to";
   window(55,6,80,15);
   cout<<"watch the game?";
    window(55,7,80,15);
    cout<<"(You can do this ";
     window(55,8,80,15);
     cout<<"only once : y/n)";
      window(55,9,80,15);
      cout<<", Restart(r) ";
       window(55,10,80,15);
  cin>>ch;
  if(ch=='y' || ch=='Y')
  {if(nr!=0)
  {cout<<"YOU CAN DO THIS ONLY ONCE!!! " ;
   delay(700);
   menu();
   }
  replay();
  }
  if(ch=='R' || ch=='r')
  {
  nr=0;
  p=0;
  p1=12;
  p2=12;
  s=0;
  q=0;
  z=0;
  main();
  }
exit(0);
}
if(p==1)
 {
 f=v[z]%100;
 t=v[z+1]%100;
 z=z+2;
 }
 if(p==1)
{
  m=f/10;
  n=f%10;
  glow(m,n);
  delay(time);
  x=t/10;
  y=t%10;
  delay(time);
}

if(p==0)
{
  m=x;
  n=y;
  glow(m,n);
while(p==0)
 {                   //to create a scroll box to obtain the co-ordinates of the position of the piece
  scroll=getch();
if(scroll==13 || scroll==32)
  {if(a[m][n]!=0)
    break;
    }
if(scroll==119 || scroll==87 || scroll==56)
  {
  box(m,n);
  n--;
  }
else if(scroll==115 || scroll==83 || scroll==53)
  {
  box(m,n);
  n++;
  }
else if(scroll==97 || scroll==65 || scroll==52)
  {
  box(m,n);
  m--;
  }
else if(scroll==100 || scroll==68 || scroll==54)
  {
  box(m,n);
  m++;
  }
  if(m==9)
  m=1;
  if(m==0)
  m=8;
  if(n==9)
  n=1;
  if(n==0)
  n=8;
  glow(m,n);
  if(scroll==110 || scroll==78)
{
  window(55,4,80,15);
   cout<<"Opponent wants to ";
  window(55,5,80,15);
   cout<<"draw.. Do you";
  window(55,6,80,15);
   cout<<"agree?(y/n)";
  window(55,7,80,15);
   cin>>ch;
if(ch=='Y' || ch=='y')
 {
  window(55,2,80,15);
  cout<<"DRAW!";
  draw=1;
   window(55,3,80,15);
  cout<<"Do you wish to";
   window(55,4,80,15);
   cout<<"watch the game?";
    window(55,5,80,15);
    cout<<"(You can do this";
     window(55,6,80,15);
     cout<<"only once : y/n)";
      window(55,7,80,15);
    cout<<", Restart(r) ";
   window(55,8,80,15);
  cin>>ch;
if(ch=='y' || ch=='Y')
 {
  if(nr!=0)
  {cout<<"YOU CAN DO THIS ONLY ONCE!!! " ;
   delay(700);
   menu();
   }
  replay();
  }
  if(ch=='R' || ch=='r')
  {
  nr=0;
  p=0;
  p1=12;
  p2=12;
  s=0;
  q=0;
  z=0;
  main();
  }
exit(0);
}
}

 if(scroll==27)
  {
  res=1;
  esc++;
  menu();
  }
 }
  glow(m,n);
  x=m;
  y=n;
  while(p==0)
 {                            //to create a scroll box to obtain the co-ordinates of the destination of the piece
  scroll=getch();
  if(scroll==13 || scroll==32 )
  {
  if(a[m][n]!=0)
  break;
  }
if(scroll==119 || scroll==87 || scroll==56)
  {
  box(x,y);
  y--;
  }
else if(scroll==115 || scroll==83 || scroll==53)
  {
  box(x,y);
  y++;
  }
else if(scroll==97 || scroll==65 || scroll==52)
  {
  box(x,y);
  x--;
  }
else if(scroll==100 || scroll==68 || scroll==54)
  {
  box(x,y);
  x++;
  }

  if(x==9)
  x=1;
  if(x==0)
  x=8;
  if(y==9)
  y=1;
  if(y==0)
  y=8;

  glow(x,y);
  glow(m,n);
  if(scroll==110 || scroll==78)
{
  window(55,4,80,15);
  cout<<"Opponent wants to ";
  window(55,5,80,15);
  cout<<"draw.. Do you";
  window(55,6,80,15);
  cout<<"agree?(y/n)";
  window(55,7,80,15);
  cin>>ch;
if(ch=='Y' || ch=='y')
 {
  window(55,8,80,15);
  cout<<"DRAW!";
  draw=1;
   window(55,3,80,15);
  cout<<"Do you wish to";
   window(55,4,80,15);
  cout<<"watch the game?";
   window(55,5,80,15);
  cout<<"(You can do this";
window(55,6,80,15);
  cout<<"only once : y/n)";
   window(55,7,80,15);
  cout<<", Restart(r) ";
   window(55,8,80,15);
  cin>>ch;
if(ch=='y' || ch=='Y')
 {
  if(nr!=0)
  {cout<<"YOU CAN DO THIS ONLY ONCE!!! " ;
   delay(700);
   menu();
   }
  replay();
  }
  if(ch=='R' || ch=='r')
  {
  nr=0;
  p=0;
  p1=12;
  p2=12;
  s=0;
  q=0;
  z=0;
  main();
  }
exit(0);
}
}

  if(scroll==27)
  {
  res=2;
  esc++;
  menu();
  }
 }
 }
movecp(m,n,x,y);
box(x,y);

}
void main()
{ if(p==0)
  {
  int gdriver=VGA, gmode=VGAHI;
  initgraph(&gdriver,&gmode,"");
  }
  loadin();
  x=4;                  //to initialise the postion of the scroll box
  y=4;
  p1=12;
  p2=12;
  if(menut==0)             //to make sure the menu is displayed only once
  menu();
  if(p!=1)
  {
    board();
    rules();
  }
  setbkcolor(0);
  board();
  cps();
  ini_pos();
  gamedriver();
  cleardevice();
  closegraph();
  getch();

}