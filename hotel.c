#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<io.h>
#include<conio.h>
FILE *fp,*fopen(),*fptr,*tptr;
void roomstat();
void drawrect(int l,int t,int r,int b);
/* structure named cust is created for handling customer*/
struct cust
{
  char name[20];
  char address[50];
  int days,status;
  int room;
  float advance;
};
//MAIN PROGARM STARTS
void main()
{
   void upgrade();//VARIOUS FUNCTIONS USED IN IT ARE DECLARED
   void roomsee();
   void roominfo();
   void roomchange();
   void booking();
   void roomdetail();
   int valid(int x);
   void monrepo();
   void total();
   int menu();
   int pre,ans;
   clrscr();
er:
   pre=menu();
   switch(pre)       //ACCORDING TO MENU RETURN OPERATION HAPPENS
   {
   case 1:
	 {
	   clrscr();
	   booking();  //deals with the customer
	   clrscr();
	   goto er;
	  }
   case 2:
	 {
	 clrscr();
	 roomstat(); //ROOM STATUS
	 drawrect(1,22,80,24);
	 gotoxy(2,23);
	  printf(" WISH TO GO BACK TO MAIN-MENU[Y/N]::>> ");
	  scanf("%s",&ans);
	  textcolor(WHITE);
	  if(ans=='y'||ans=='Y')
	  goto er;
	 break;
	 }
   case 3:
	 {
	  clrscr();
	  roomdetail();  // ROOM DETAIL
	  drawrect(1,22,80,24);
	  gotoxy(2,23);
	  printf(" WISH TO GO BACK TO MAIN-MENU[Y/N]::>> ");
	  scanf("%s",&ans);
	  textcolor(WHITE);
	  if(ans=='y'||ans=='Y')
	    goto er;
	    break;
	 }
   case 4:
	{
	  clrscr();
	  roominfo(); //ROOM INFORMATION
	  clrscr();
	  goto er;
	}
   case 5:
	 {
	  clrscr();
	  total();// COMPUTATION OF BILL
	  drawrect(1,22,80,24);
	  gotoxy(2,23);
	  printf(" WISH TO GO BACK TO MAIN-MENU[Y/N]::>> ");
	  scanf("%s",&ans);
	  textcolor(WHITE);
	  if(ans=='y'||ans=='Y')
	     goto er;
	     break;
	 }
    case 6:
	 {
	 clrscr();
	 monrepo();      //DATE WISE REPORT
	 goto er;
	 }
    case 7:
	 {
	 exit(0);
	 }
    default:
	 {
	 drawrect(1,22,80,24);
	 gotoxy(25,23);
	 printf("*******Invalid Input*******");
	 getch();
	 goto er;
	 }
   }

clrscr();
drawrect(1,10,80,15);
gotoxy(5,12);
printf("  PROGRAM TERMINATED <::> COMPILE AGAIN TO START THE APPLICATION");
getch();
}
// DISPLAY MENU
int menu()
 {
	int pre;
	  clrscr();
	  textcolor(LIGHTGRAY);
	  drawrect(1,1,80,3);
	  textcolor(YELLOW);
	  gotoxy(2,2);
	  cprintf("                    *************MAIN  MENU*************\n");
	  textcolor(BLUE);
	  drawrect(1,5,80,18);
	  textcolor(RED+BLINK);
	  gotoxy(22,6);
	  cprintf("\n%s","     ........................" );
	 gotoxy(22,7);
	 cprintf("\n%s","     |                      | ");
	 gotoxy(22,8);
	 cprintf("\n%s","     |");
	 printf(" (1) CUSTOMER");
	 gotoxy(50,8);
	 cprintf("\n%s","|");
	 gotoxy(22,9);
	 cprintf("\n%s","     |");
	 printf(" (2) ROOM STATUS");
	 gotoxy(50,9);
	 cprintf("\n%s","|");
	 gotoxy(22,10);
	 cprintf("\n%s","     |");
	 printf(" (3) ROOM DETAIL");
	 gotoxy(50,10);
	 cprintf("\n%s","|");
	 gotoxy(22,11);
	 cprintf("\n%s","     |");
	 printf(" (4) ROOM INFORMATION");
	 gotoxy(50,11);
	 cprintf("\n%s","|");
	  gotoxy(22,12);
	 cprintf("\n%s","     |");
	 printf(" (5) BILL GENERATION");
	 gotoxy(50,12);
	 cprintf("\n%s","|");
	 gotoxy(22,13);
	 cprintf("\n%s","     |");
	 printf(" (6) REPORT");
	 gotoxy(50,13);
	 cprintf("\n%s","|");
	 gotoxy(22,14);
	 cprintf("\n%s","     |");
	 printf(" (7) EXIT");
	 gotoxy(50,14);
	 cprintf("\n%s","|");
	 gotoxy(22,15);
	 cprintf("\n%s","     |                      | ");
	  gotoxy(22,16);
	 cprintf("     |......................| ");
	  printf("\n");
	  textcolor(LIGHTGRAY);
	  drawrect(1,22,80,24);
	  textcolor(YELLOW+BLINK);
	  gotoxy(26,23);
	  cprintf("Enter Your Choice[1-7]  ");
	  scanf("%d",&pre);
	  textcolor(WHITE);
	  return(pre);
	}
//THE FUNCTION THAT DEALS WITH THE CUSTOMER STARTS HERE
 void booking()
{
    struct cust c;
    int d,ro,days;
    void roomchange();
    void roomsee();
    void total();
    void deletion();
    char rep='y',ans;
    char choice,ch;
    float t,st,tot;//its used in checkout
    struct dosdate_t de;
    _dos_getdate(&de);
cub: clrscr();
     textcolor(LIGHTGRAY);
     drawrect(1,5,80,21);
     textcolor(RED);
     drawrect(1,22,80,24);
     gotoxy(13,23);
     textcolor(WHITE);
     cprintf("<::> PRESS THE          FOR CORRESPONDING APPLET <::>");
     gotoxy(29,23);
     textcolor(RED);
     cprintf("HOT KEY");
     drawrect(1,1,80,4);
     textcolor(WHITE);
     gotoxy(33,1);
     cprintf("CUSTOMER");
     gotoxy(4,2);
     textcolor(RED);
     cprintf("B");
     textcolor(BLUE);
     cprintf("ooking");
     gotoxy(16,2);
     textcolor(RED);
     cprintf("R");
     textcolor(BLUE);
     cprintf("oomchange");
     gotoxy(30,2);
     textcolor(RED);
     cprintf("T");
     textcolor(BLUE);
     cprintf("otal");
     gotoxy(40,2);
     textcolor(RED);
     cprintf("C");
     textcolor(BLUE);
     cprintf("heckout");
     gotoxy(55,2);
     textcolor(RED);
     cprintf("M");
     textcolor(BLUE);
     cprintf("enu");
     textcolor(WHITE);
     choice=getch();
     choice=toupper(choice);
   /*ACCORDING TO THE HOT KEY STROKE OPERATION IS PERFORMED*/
   switch(choice)
   {
   case 'B':
      {
	rep='y';
	while(rep=='y')
	     {
	      clrscr();
	      textcolor(RED);
	      drawrect(1,1,80,3);
	      textcolor(WHITE);
	      gotoxy(25,2);
	      cprintf("BOOKING     APPLET");
	      drawrect(1,5,80,20);
	      textcolor(RED);
	      drawrect(1,22,80,24);
	      textcolor(WHITE);
	      gotoxy(30,22);
	      cprintf("MESSAGE BOX");
	      textcolor(LIGHTCYAN);
	      gotoxy(30,6);
	      cprintf("FOR BOOKING");
	      textcolor(YELLOW);
	      gotoxy(3,23);
	      cprintf("  NAME SHOULD NOT BE SEPERATED WITH SPACE USE '_'!!");
	      gotoxy(26,10);
	      printf("Enter Name           ");
	      scanf("%s",c.name);
	      flushall();
	      gotoxy(3,23);
	      cprintf("  ADDRESS SHOULD NOT BE SEPERATED WITH SPACE USE '_'!!");
	      gotoxy(26,11);
	      printf("Enter Address        ");
	      scanf("%s",c.address);
	      flushall();
	      gotoxy(3,23);
	      cprintf("  DAYS SHOULD SPECIFY THE NUMBER OF DAY'S STAY   !!");
	      gotoxy(26,12);
	      printf("Enter Dayz of Stay   ");
	      scanf("%d",&c.days);
	      flushall();
	      gotoxy(3,23);
	      cprintf("  SPECIFY THE ADVANCE PAID AT THE COUNTER ....!!");
	      gotoxy(26,13);
	      printf("Enter advance if any  ");
	      scanf("%f",&c.advance);
	      flushall();
	      textcolor(WHITE);
	      clrscr();
	      textcolor(RED);
	      drawrect(1,1,80,3);
	      gotoxy(25,2);
	      printf("WHICH TYPE OF ROOM CUSTOMER WANTS");
	      textcolor(13+BLINK);
	      cprintf("  ?");
	     textcolor(RED);
	     drawrect(1,22,80,24);
	     textcolor(LIGHTGRAY);
	      drawrect(1,8,80,20);
	      textcolor(WHITE);
	      gotoxy(2,9);
	      printf("          | Ordinary | Ordinary | Deluxe | Deluxe | S.Deluxe | S.Deluxe |");
	      gotoxy(2,10);
	      printf("          |    &     |    &     |    &   |    &   |     &    |     &    |");
	      gotoxy(2,11);
	      printf("          |  Single  |  Double  | Single | Double |  Single  |  Double  |");
	      gotoxy(2,12);
	      printf(" ---------|------------------------------------------------------------ |");
	      gotoxy(2,13);
	      printf("  Pressing|          |          |        |        |          |          | ");
	      gotoxy(2,14);
	      printf("    Keys  |     1    |    11    |    2   |    22  |     3    |     33   |");
	      gotoxy(2,15);
	      printf(" =========|=============================================================|");
	      gotoxy(30,22);
	      textcolor(WHITE);
	      cprintf("MESSAGE BOX");
	      gotoxy(19,23);
	      cprintf("ENTER THE NUMBER ACCORDING TO THE TYPE OF ROOM DESIRED");
	      gotoxy(2,16);
	      textcolor(14+BLINK);
	      cprintf("\n\n                           Enter status  ");
	      scanf("%d",&c.status);
	      flushall();
	      textcolor(15);
	      clrscr();
	      textcolor(WHITE);
	      //ACCORDING TO THE ROOM TYPE THAT PARTICULAR PAGE OPENS UP.
	      switch(c.status)
	      {
	      case 1:
		 {
		 printf("                         ORDINARY & SINGLE");
		 printf("\n------------------------------------------------\n");
		 printf("ROOMS UNDER IT:-");
		 printf("\n#### 101  102  103 ## 201  202  203  ####");
		 printf("\n#### 301  302  303 ## 401  402  403  ####");
		 printf("\n        #### 501  502  503 ####");
		 printf("\n                                                             ");
		 printf("\n                                                             ");
		 printf("\n ROOMS OCCUPIED");
		 roomsee();
		 los: printf("\nenter ROOM DESIRED\n");
		 scanf("%d",&ro);
		 d=valid(ro);
		 if(d==0)
		 goto los;
		 else
		  c.room=ro;
		 flushall();
		 break;
		 }
		 case 11:
		 {
		 printf("                       ORDINARY & DOUBLE");
		 printf("\n------------------------------------------------\n");
		 printf("\n ROOMS UNDER IT:-");
		 printf("\n#### 104  105  106  107## 204  205  206  207####");
		 printf("\n#### 304  305  306  307## 404  405  406  407####");
		 printf("\n        #### 504  505  506  507####");
		 printf("\n                                                             ");
		 printf("\n                                                             ");
		 printf("\n ROOMS OCCUPIED");
		 roomsee();
		 los1:
		 printf("\nenter ROOM DESIRED\n");
		 scanf("%d",&ro);
		 d=valid(ro);
		 if(d==0)
		 goto los1;
		 else
		  c.room=ro;
		 flushall();
		 break;
		 }
		 case 2:
		 {
		 printf("                       DELUXE & SINGLE");
		 printf("\n------------------------------------------------\n");
		 printf("\n ROOMS UNDER IT:-");
		 printf("\n#### 108  109  110  ## 208  209  210  ####");
		 printf("\n#### 308  309  310  ## 408  409  410  ####");
		 printf("\n        #### 508  509  510 ####");
		 printf("\n                                                             ");
		 printf("\n                                                             ");
		 printf("\n ROOMS OCCUPIED");
		 roomsee();
		 los2:
		 printf("\nenter ROOM DESIRED\n");
		 scanf("%d",&ro);
		 d=valid(ro);
		 if(d==0)
		 goto los2;
		 else
		  c.room=ro;
		 flushall();
		 break;
		 }
		 case 22:
		 {
		 printf("                       DELUXE & DOUBLE");
		 printf("\n------------------------------------------------\n");
		 printf("\n ROOMS UNDER IT:-");
		 printf("\n#### 111  112  113  114## 211  212  213  214####");
		 printf("\n#### 311  312  313  314## 411  412  413  414####");
		 printf("\n        #### 511  512  513  514 ####");
		 printf("\n                                                             ");
		 printf("\n                                                             ");
		 printf("\n ROOMS OCCUPIED");
		 roomsee();
		 los3:
		 printf("\nenter ROOM DESIRED\n");
		 scanf("%d",&ro);
		 d=valid(ro);
		 if(d==0)
		 goto los3;
		 else
		  c.room=ro;
			 flushall();
		 break;
		 }
		 case 3:
		 {
		 printf("                       S.DELUX & SINGLE");
		 printf("\n------------------------------------------------\n");
		 printf("\n ROOMS UNDER IT:-");
		 printf("\n#### 115  116  117  ## 215  216  217 ####");
		 printf("\n#### 315  316  317  ## 415  416  417 ####");
		 printf("\n        #### 515  516  517 ####");
		 printf("\n                                                             ");
		 printf("\n                                                             ");
		 printf("\n ROOMS OCCUPIED");
		 roomsee();
		 los4:
		 printf("\nenter ROOM DESIRED\n");
		 scanf("%d",&ro);
		 d=valid(ro);
		 if(d==0)
		 goto los4;
		 else
		  c.room=ro;
		 flushall();
		 break;
		 }
		 case 33:
		 {
		 printf("                       S.DELUXE & DOUBLE");
		 printf("\n------------------------------------------------\n");
		 printf("\n ROOMS UNDER IT:-");
		 printf("\n#### 118  119  200## 218  219  300 ####");
		 printf("\n#### 318  319  400## 418  419  500 ####");
		 printf("\n        #### 518  519  600 ####");
		 printf("\n                                                             ");
		 printf("\n                                                             ");
		 printf("\n ROOMS OCCUPIED");
		 roomsee();
	    los5: printf("\nenter ROOM DESIRED\n");
		 scanf("%d",&ro);
		 d=valid(ro);
		 if(d==0)
		 goto los5;
		 else
		  c.room=ro;
		 flushall();
		 break;
		 }
	      }
	      fp=fopen("hotel.dat","a");
	      fprintf(fp,"%s %s %d %f %d %d",c.name,c.address,c.days,c.advance,c.status,c.room);
	      fprintf(fp,"\n");
	      printf("\n any more customers [y/n]::>> ");
	      scanf("%c",&rep);
	      flushall();
	      clrscr();
	      fclose(fp);
	      textcolor(WHITE);
	     }
	     break;
      }
   //THE CUSTOMER CAN CHANGE ITS ROOM
    case 'R':
      {
	 clrscr();
	 textcolor(RED);
	 drawrect(1,22,80,24);
	 gotoxy(30,22);
	 textcolor(WHITE);
	 printf("MESSAGE BOX");
	 gotoxy(2,23);
	 textcolor(YELLOW);
	 printf("        plzzz ENTER THE ROOM NUMBER, AVOID  USING CHARACTERS");
	 roomchange();//printf("test");
	 //getch();
	 break;
      }
    //FOR TOTAL BILL GENERATION
    case 'T':
      {
	 total();
	  break;
      }
    //FOR IMMEDIATE CHECKOUT
    case 'C':
      {   rep='y';
	  clrscr();
	  textcolor(RED);
	  drawrect(1,1,80,3);
	  gotoxy(30,2);
	  textcolor(WHITE);
	  cprintf("----IMMEDIATE CHECK OUT----");
	  textcolor(RED);
	  drawrect(1,7,80,12);
	  gotoxy(2,8);
	  textcolor(WHITE);
	  printf("TOTAL DESIRED FOR HOW MANY DAYS");
	  gotoxy(30,10);
	  printf("ENTER The No.Days:::::>> ");
	  scanf("%d",&days);
	  clrscr();
      while(rep=='y'||rep=='Y')
	{
	 textcolor(RED);
	 drawrect(1,1,80,3);
	 gotoxy(25,2);
	 textcolor(WHITE);
	 cprintf("FOR TOTAL BiLL GENERATION");
	 textcolor(LIGHTGRAY);
	 drawrect(1,4,80,24);
	 gotoxy(2,5);
	 textcolor(RED);
	 cprintf("CUSTOMER TO BE OPERATED BEARING ROOM NUMBER:--");
	 scanf("%d",&ro);
	 clrscr();
	 fp=fopen("hotel.dat","r");
	 fscanf(fp,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
	 textcolor(RED);
	 drawrect(1,1,80,24);
	 textcolor(BLUE);
	 drawrect(2,2,79,23);
	 while(!feof(fp))
	    {
	    if(c.room==ro)
	    {
	    goto bill;
	    }
	    fscanf(fp,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
	    }
	    gotoxy(20,10);
	    textcolor(WHITE);
	    cprintf("*********ROOM IS NOT OCCUPIED*********");
	    goto dw;
      bill: gotoxy(35,3);
	    textcolor(RED);
	    cprintf("                      TOTAL BILL");
	    gotoxy(35,4);
	    cprintf("                    KENILWORTH HOTEL");
	    gotoxy(10,4);
	    textcolor(MAGENTA);
	    cprintf("%d-%d-%d",de.day,de.month,de.year);
	    gotoxy(20,7);
	    printf("CUSTOMER NAME:::::>>>>>>%s",c.name);
	    gotoxy(20,8);
	    printf("CUSTOMER ADDRESS::>>>>>>%s",c.address);
	    gotoxy(20,9);
	    printf("ROOM NO:::::::::::>>>>>>%d",c.room);
	    gotoxy(20,10);
	    switch(c.status)
	     {
	     case 1:
		 {
		 printf("TYPE OF ROOM::::>>>>ORDINARY AND SINGLE");
		 break;
		 }
	    case 11:
		 {
		 printf("TYPE OF ROOM::::>>>>ORDINARY AND DOUBLE");
		 break;
		 }
	   case 2:
		 {
		 printf("TYPE OF ROOM::::>>>>DELUXE AND SINGLE");
		 break;
		 }
	   case 22:
		 {
		 printf("TYPE OF ROOM::::>>>>DELUXE AND DOUBLE");
		 break;
		 }
	 case 3:
		 {
		 printf("TYPE OF ROOM::::>>>>S.DELUXE AND SINGLE");
		 break;
		 }
	 case 33:
		 {
		 printf("TYPE OF ROOM::::>>>>S.DELUXE AND DOUBLE");
		 break;
		 }
	     }
	     gotoxy(20,11);
	 if(c.status==1||c.status==11)
	   {
	   d=100;
	   printf("RENT OF THE ROOM:::::>>>>Rs. 100.00 per day(s)");
	   }
	 if(c.status==2||c.status==22)
	   {
	   d=200;
	   printf("RENT OF THE ROOM:::::>>>>Rs. 200.00 per day(s)");
	   }
	 if(c.status==3||c.status==33)
	  {
	  d=300;
	  printf("RENT OF THE ROOM:::::>>>>Rs. 300.00 per day(s)");
	  }
	  gotoxy(20,12);
	  printf("NO.OF DAYS STAY:::::>>>%d",days);
	  gotoxy(20,13);
	  t=d*days;
	  printf("RENT FOR %d DAY(S) STAY::::>>>>%f",days,t);
	  gotoxy(20,14);
	  printf("LUXURY CHARGES @5percent:::>>>>>Rs.  %f",.05*t);
	  st=(d*days)+(.05*t);
	  gotoxy(20,15);
	  printf("TOTAL AMOUNT DUE::::>>>%f",st);
	  gotoxy(20,16);
	  printf(" LESS:: ADVANCE PAYMENT:::>>>%f",c.advance);
	  tot=st - c.advance;
	  gotoxy(20,18);
	  printf("NET AMOUNT DUE:::::>>>>%f",tot);
	  gotoxy(25,20);
	  textcolor(RED);
	  cprintf("THANKING YOU");
	  gotoxy(25,21);
	  cprintf("DO COME AGAIN KENILWORTH IS ALWAYS AT UR SERVICE");
	  fptr=fopen("monro.dat","a");
	  fprintf(fptr,"%s %s %d %f %f %f %d-%d-%d",c.name,c.address,days,st,c.advance,tot,de.day,de.month,de.year);
	  fprintf(fptr,"\n");
	  gotoxy(20,23);
	  printf("press ENTER for CHECK OUT");
	  getch();
	  clrscr();
	  textcolor(BLUE);
	  drawrect(1,9,80,21);
	  drawrect(2,10,79,20);
	  gotoxy(5,13);
	  textcolor(RED);
	  printf("CHECK OUT CONFIRMATION--[Y/N]::>> ");
	  scanf("%s",&ch);
	  if(ch=='y'||ch=='Y')
	  {
	  deletion();
	  gotoxy(7,15);
	  printf("CHECK OUT OPERATION COMPLETE");
	  }
       dw:fclose(fptr);
	  fclose(fp);
	  gotoxy(5,18);
	  textcolor(WHITE);
	  cprintf("WANT TO EVALUATE FOR ANOTHER CUSTOMER[Y/N]::>> ");
	  scanf("%s",&rep);
	  textcolor(WHITE);
	  clrscr();
	  }
	  break;
	  }
      case 'M':
	    {
	       goto cer;
	    }
    }//switch over
    goto cub;
    cer:  textcolor(WHITE);
    }
   //DISPLAY OF ROOM STATUS
void roomstat()
{
	struct cust c;
	int stat;
	char t;
	int i,j;
	clrscr();
	fp=fopen("hotel.dat","r");
	 fscanf(fp,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
	 textcolor(RED);
	 drawrect(1,1,80,3);
	 gotoxy(30,2);
	 textcolor(WHITE);
	 cprintf("ROOM STATUS");
	 textcolor(LIGHTGRAY);
	 drawrect(1,5,80,24);
	 gotoxy(3,6);
	 printf("DO U WANT TO SEE OCCUPIED ROOMS WITH STATUS[y/n]::>>");
	 scanf("%s",&t);
	 if(t=='n')
	 {
	 gotoxy(3,7);
	 printf("ENTER ROOM BEARING STATUS::>>  ");
	 scanf("%d",&stat);
	 }
	 textcolor(BLUE);
	 i=30;j=8;
	 while(!feof(fp))
	      {
	      if(t=='y')
	      {
	      gotoxy(i,j);
	      cprintf("##%d---status->%d",c.room,c.status);
	      }
	      else
		{
		  if(c.status==stat)
		    {
		     gotoxy(i,j);
		     cprintf("##%d---status->%d",c.room,c.status);
		     }
	      }
	      fscanf(fp,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
	      j++;
	      }
	 fclose(fp);
	 gotoxy(2,j);
 printf("******************************************************************************");
 textcolor(WHITE);
}
//BILL GENERATION PART STARTS HERE
void total()
{
	void deletion();
	int room;
	float d,t,st,tot;
	char rep='y',ans,ch;
	struct cust c;
	struct dosdate_t de;
	_dos_getdate(&de);
	clrscr();
   while(rep=='y'||rep=='Y')
	{
	 textcolor(RED);
	 drawrect(1,1,80,3);
	 gotoxy(25,2);
	 textcolor(WHITE);
	 cprintf("FOR TOTAL BiLL GENERATION");
	 textcolor(LIGHTGRAY);
	 drawrect(1,4,80,24);
	 gotoxy(2,5);
	 textcolor(WHITE);
	cprintf("CUSTOMER TO BE OPERATED BEARING ROOM NUMBER:-- ");
	scanf("%d",&room);
	clrscr();
	fp=fopen("hotel.dat","r");
	fscanf(fp,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
	textcolor(LIGHTGRAY);
	drawrect(1,1,80,24);
	textcolor(RED);
	drawrect(2,2,79,23);
	while(!feof(fp))
	    {
	    if(c.room==room)
	    {
	    goto pay;
	    }
	    fscanf(fp,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
	    }
	    gotoxy(25,10);
	    printf("**********ROOM IS NOT OCCUPIED************");
	    goto den;
       pay:  gotoxy(35,3);
	    textcolor(BLUE);
	    cprintf("                      TOTAL BILL");
	    gotoxy(35,4);
	    cprintf("                    KENILWORTH HOTEL");
	    gotoxy(10,4);
	    textcolor(MAGENTA);
	    cprintf("%d-%d-%d",de.day,de.month,de.year);
	    gotoxy(20,7);
	    textcolor(WHITE);
	    printf("CUSTOMER NAME:::::>>>>>>%s",c.name);
	    gotoxy(20,8);
	    printf("CUSTOMER ADDRESS::>>>>>>%s",c.address);
	    gotoxy(20,9);
	    printf("ROOM NO:::::::::::>>>>>>%d",c.room);
	    gotoxy(20,10);
	    switch(c.status)
	     {
	     case 1:
		 {
		 printf("TYPE OF ROOM::::>>>>ORDINARY AND SINGLE");
		 break;
		 }
	    case 11:
		 {
		 printf("TYPE OF ROOM::::>>>>ORDINARY AND DOUBLE");
		 break;
		 }
	   case 2:
		 {
		 printf("TYPE OF ROOM::::>>>>DELUXE AND SINGLE");
		 break;
		 }
	   case 22:
		 {
		 printf("TYPE OF ROOM::::>>>>DELUXE AND DOUBLE");
		 break;
		 }
	 case 3:
		 {
		 printf("TYPE OF ROOM::::>>>>S.DELUXE AND SINGLE");
		 break;
		 }
	 case 33:
		 {
		 printf("TYPE OF ROOM::::>>>>S.DELUXE AND DOUBLE");
		 break;
		 }
	     }
	     gotoxy(20,11);
	 if(c.status==1||c.status==11)
	   {
	   d=100.00;
	   printf("RENT OF THE ROOM:::::>>>>Rs. 100.00 per day(s)");
	   }
	 if(c.status==2||c.status==22)
	   {
	   d=200.00;
	   printf("RENT OF THE ROOM:::::>>>>Rs. 200.00 per day(s)");
	   }
	 if(c.status==3||c.status==33)
	  {
	  d=300.00;
	  printf("RENT OF THE ROOM:::::>>>>Rs. 300.00 per day(s)");
	  }
	  gotoxy(20,12);
	  printf("NO.OF DAYS STAY:::::>>>%d",c.days);
	  gotoxy(20,13);
	  printf("RENT FOR %d DAY(S) STAY::::>>>>%f",c.days,d*c.days);
	  t=d*c.days;
	  gotoxy(20,14);
	  printf("LUXURY CHARGES @5percent:::>>>>>Rs.  %f",.05*t);
	  st=(d*c.days)+(.05*t);
	  gotoxy(20,15);
	  printf("TOTAL AMOUNT DUE::::>>>%f",st);
	  gotoxy(20,16);
	  printf(" LESS:: ADVANCE PAYMENT:::>>>%f",c.advance);
	  tot=st - c.advance;
	  gotoxy(20,18);
	  printf("NET AMOUNT DUE:::::>>>>%f",tot);
	  gotoxy(25,20);
	  textcolor(RED);
	  cprintf("THANKING YOU");
	  gotoxy(25,21);
	  cprintf("DO COME AGAIN KENILWORTH IS ALWAYS AT UR SERVICE");
	  fptr=fopen("monro.dat","a");
	  fprintf(fptr,"%s %s %d %f %f %f %d-%d-%d",c.name,c.address,c.days,st,c.advance,tot,de.day,de.month,de.year);
	  fprintf(fptr,"\n");
	  gotoxy(20,23);
	  printf("press ENTER for CHECK OUT");
	  getch();
	  clrscr();
	  textcolor(BLUE);
	  drawrect(1,9,80,21);
	  drawrect(2,10,79,20);
	  gotoxy(5,13);
	  textcolor(RED);
	  printf("CHECK OUT CONFIRMATION--[Y/N]");
	  scanf("%s",&ch);
	  if(ch=='y'||ch=='Y')
	  {
	  deletion();
	  gotoxy(7,15);
	  printf("CHECK OUT OPERATION COMPLETE");
	  }
     den: fclose(fptr);
	  fclose(fp);
	  gotoxy(5,18);
	  printf("WANT TO EVALUATE FOR ANOTHER CUSTOMER[Y/N]");
	  scanf("%s",&rep);
	  textcolor(WHITE);
	  clrscr();
	  }
}
//REPORT PREPARATION FOR HOTEL TRANSACTION
void monrepo()
{
   int i,j,dd,mm,t;
   char ch;
   float st,tot;
   struct cust c;
   struct dosdate_t de;
   _dos_getdate(&de);
repo:
   clrscr();
   textcolor(LIGHTGRAY);
   drawrect(1,1,80,3);
   textcolor(RED);
   gotoxy(35,1);
   printf("REPORT");
   gotoxy(5,2);
   cprintf("S");
   gotoxy(6,2);
   textcolor(BLUE);
   cprintf("erial");
   textcolor(RED);
   gotoxy(20,2);
   cprintf("D");
   gotoxy(21,2);
   textcolor(BLUE);
   cprintf("ay");
   textcolor(BLUE);
   gotoxy(33,2);
   cprintf("m nth");
   gotoxy(34,2);
   textcolor(RED);
   cprintf("O");
   textcolor(RED);
   gotoxy(48,2);
   cprintf("M");
   gotoxy(49,2);
   textcolor(BLUE);
   cprintf("enu");
   textcolor(RED);
   drawrect(1,4,80,24);
   ch=getch();
   ch=toupper(ch);
   switch(ch)
   {
   case 'D':
       {
       gotoxy(20,6);
       printf("ENTER THE DAY WHOSE REPORT IS DESIRED::>> ");
       scanf("%d",&dd);
       drawrect(20,21,60,23);
       gotoxy(32,22);
       printf("SINGLE DAY REPORT");
       break;
       }
   case 'O':
       {
       gotoxy(20,6);
       printf("ENTER THE MONTH WHOSE REPORT IS DESIRED::>> ");
       scanf("%d",&mm);
       drawrect(20,21,60,23);
       gotoxy(32,22);
       printf("MONTHLY REPORT");
       break;
       }
   case 'S':
	{
	t=1;
	drawrect(20,21,60,23);
       gotoxy(32,22);
       printf("DAILY REPORT");
	break;
	}
   case 'M':
	 {
	 goto ma;
	 }
     }
   textcolor(LIGHTGRAY);
   drawrect(1,6,80,8);
   gotoxy(2,7);
   printf("   DATE        NAME       ADDRESS       DAYS   TO PAY      ADVANCE      PAID ");
   i=2;j=9;
   fptr=fopen("monro.dat","r");
   fscanf(fptr,"%s %s %d %f %f %f %d-%d-%d",c.name,c.address,&c.days,&st,&c.advance,&tot,&de.day,&de.month,&de.year);
       while(!feof(fptr))
	{
	if(de.day==dd||de.month==mm||t==1)
	{
	gotoxy(i,j);
	printf("%d-%d-%d",de.day,de.month,de.year);
	gotoxy(i+13,j);
	printf("%s",c.name);
	gotoxy(i+26,j);
	printf("%s",c.address);
	gotoxy(i+41,j);
	printf("%d",c.days);
	gotoxy(i+46,j);
	printf("%.1f",st);
	gotoxy(i+59,j);
	printf("%.1f",c.advance);
	gotoxy(i+69,j);
	printf("%.1f",tot);
	j++;
	}
	fscanf(fptr,"%s %s %d %f %f %f %d-%d-%d",c.name,c.address,&c.days,&st,&c.advance,&tot,&de.day,&de.month,&de.year);
	}
       drawrect(1,8,12,j);
       drawrect(13,8,25,j);
       drawrect(26,8,40,j);
       drawrect(41,8,45,j);
       drawrect(46,8,58,j);
       drawrect(59,8,68,j);
       drawrect(69,8,80,j);
       fclose(fptr);
       getch();
       dd=0;
       mm=0;
       t=0;
       goto repo;
     ma:  textcolor(WHITE);
}
//THIS FUNCTION'S USE IS FOR CHECKING THE VALIDITY OF A ROOM WHETHER OCCUPIED OR NOT
int valid(int ro)
  {
  struct cust c;
  int s=1;
  fptr=fopen("hotel.dat","r");
  fscanf(fptr,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
	while(!feof(fptr))
	       {
	       if(c.room==ro)
		{
		printf("  its already occupied");
		s=0;
		goto gate;
		}
	      fscanf(fptr,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
		}
	 printf("   valid entry");
   gate:  return(s);
  }
//THIS PART DEALS WITH THE CONTENTS OF A ROOM
void roomdetail()
{
 struct cust c;
 float d;
 int i,j;
     fptr=fopen("hotel.dat","r");
     fscanf(fptr,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
	  textcolor(LIGHTGRAY);
	  drawrect(1,1,80,3);
	  gotoxy(30,2);
	  textcolor(BLUE);
	  printf("ROOM DETAIL REPORT");
	  i=1;j=8;
	    textcolor(RED);
	    drawrect(1,4,80,6);
	    gotoxy(2,5);
	    textcolor(BLUE+BLINK);
	    cprintf("ROOMNO.---TYPE--------RENT-------STATUS--------CUSTOMER NAME-------ADDRESS");
	    textcolor(WHITE);
	    while(!feof(fptr))
	      {
	      gotoxy(i+1,j);
	       printf("%d",c.room);
	       gotoxy(i+7,j);
	       switch(c.status)
		     {
		     case 1:
			 {
			 printf("ORDINARY AND SINGLE");
			 break;
			 }
		    case 11:
			 {
			 printf("ORDINARY AND DOUBLE");
			 break;
			 }
		   case 2:
			 {
			 printf("DELUXE AND SINGLE");
			 break;
			 }
		   case 22:
			 {
			 printf("DELUXE AND DOUBLE");
			 break;
			 }
		  case 3:
			 {
			 printf("DELUXE AND SINGLE");
			 break;
			 }
		  case 33:
			 {
			printf("DELUXE AND DOUBLE");
			 break;
			 }
		     }
		     gotoxy(i+29,j);
		 if(c.status==1||c.status==11)
		   {
		    printf("Rs. 100.00");
		   }
		 if(c.status==2||c.status==22)
		   {
		   printf("Rs. 200.00");
		   }
		 if(c.status==3||c.status==33)
		  {
		  printf("Rs. 300.00");
		  }
		  gotoxy(i+43,j);
		  printf("%d",c.status);
		  gotoxy(i+49,j);
		  printf("%s",c.name);
		  gotoxy(i+65,j);
		  printf("%s",c.address);
		 j++;
     fscanf(fptr,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
	  }
      textcolor(BLUE);
      drawrect(1,7,5,j);
      drawrect(6,7,27,j);
      drawrect(28,7,40,j);
      drawrect(41,7,47,j);
      drawrect(48,7,63,j);
      drawrect(64,7,80,j);
      textcolor(WHITE);
      fclose(fptr);
   }
//THE FUNCTION DEALS WITH ALL THE ROOM INFORMATION
void roominfo()
{
       int co,cot;
       char d;
       void roomstat();
       void upgrade();
       struct cust c;
       int stat;
       char t;
       int room;
back:  clrscr();
       textcolor(WHITE);
       drawrect(1,1,80,3);
       gotoxy(30,1);
       textcolor(RED);
       cprintf("ROOM INFORMATION");
       textcolor(LIGHTGRAY);
       drawrect(1,5,80,21);
       gotoxy(3,2);
       textcolor(RED);
       cprintf("S");
       textcolor(BLUE);
       cprintf("tatus");
       gotoxy(15,2);
       textcolor(RED);
       cprintf("F");
       textcolor(BLUE);
       cprintf("acilities");
       gotoxy(31,2);
       textcolor(RED);
       cprintf("0");
       textcolor(BLUE);
       cprintf("ccupied");
       gotoxy(45,2);
       textcolor(RED);
       cprintf("C");
       textcolor(BLUE);
       cprintf("harge");
       gotoxy(57,2);
       textcolor(RED);
       cprintf("U");
       textcolor(BLUE);
       cprintf("pgrade");
       gotoxy(71,2);
       textcolor(RED);
       cprintf("M");
       textcolor(BLUE);
       cprintf("enu");
       textcolor(WHITE);
       textcolor(RED);
       drawrect(1,22,80,24);
       gotoxy(13,23);
       textcolor(WHITE);
       cprintf("<::> PRESS THE          FOR CORRESPONDING APPLET <::>");
       gotoxy(29,23);
       textcolor(RED);
       cprintf("HOT KEY");
       textcolor(WHITE);
       d=getch();
       d=toupper(d);
     switch(d)
       {
	case 'S':
	 {
	     gotoxy(25,7);
	     printf("***************ROOM STATUS****************");
	     gotoxy(25,8);
	     printf("press 1. to see ALL ROOM STATUS");
	     gotoxy(25,9);
	     printf("press 2. to see STATUS OF OCCUPIED");
	     gotoxy(25,10);
	     printf("press 3. to see STATUS OF A PARTICULAR ROOM");
	     gotoxy(25,15);
	     printf("ENTER UR CHOICE::>> ");
	     scanf("%d",&co);
	     switch(co)
	     {//inner1
	     case 1:
		  {
		   clrscr();
		   textcolor(RED);
		   drawrect(1,1,80,3);
		   gotoxy(30,2);
		   textcolor(RED+BLINK);
		   cprintf("*****ALL ROOM STATUS*****");
		   textcolor(LIGHTGRAY);
		   drawrect(1,4,80,6);
		   gotoxy(30,4);
		   printf("ORDINARY AND SINGLE");
		   gotoxy(2,5);
		   printf("##101 102 103##201 202 203##301 302 303##401 402 403##501 502 503 ##");
		   drawrect(1,7,80,9);
		   gotoxy(30,7);
		   printf("ORDINARY & DOUBLE");
		   gotoxy(2,8);
		   printf("104 105 106 107#204 205 206 207#304 305 306 307#404 405 406 407#504 505 506 507");
		   drawrect(1,10,80,12);
		   gotoxy(30,10);
		   printf("DELUXE & SINGLE");
		   gotoxy(2,11);
		   printf("##108 109 110##208 209 210##308 309 310##408 409 410##508 509 510 ##");
		   drawrect(1,13,80,15);
		   gotoxy(30,13);
		   printf("DELUXE & DOUBLE");
		   gotoxy(2,14);
		   printf("111 112 113 114#211 212 213 214#311 312 313 314#411 412 413 414#511 512 513 514");
		   drawrect(1,16,80,18);
		   gotoxy(30,16);
		   printf("S.DELUX & SINGLE");
		   gotoxy(2,17);
		   printf("##115 116 117##215 216 217##315 316 317##415 416 417##515 516 517####");
		   drawrect(1,19,80,21);
		   gotoxy(30,19);
		   printf("S.DELUXE & DOUBLE");
		   gotoxy(2,20);
		   printf("##118 119 200##218 219 300##318 319 400##418 419 500##518 519 600####");
		   getch();
		   textcolor(WHITE);
		    break;
		   }
	     case 2:
		  {
		  clrscr();
		  roomstat();
		  getch();
		  break;
		 }
	  case 3:
	      {
	      clrscr();
	      fp=fopen("hotel.dat","r");
	      fscanf(fp,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
	      textcolor(RED);
	      drawrect(1,1,80,3);
	      gotoxy(25,2);
	      textcolor(WHITE);
	      cprintf("*******STATUS ENQUIRY*******");
	      textcolor(RED);
	      drawrect(1,4,80,24);
	      gotoxy(2,5);
	      printf("ENTER THE ROOM WHOSE STATUS IS DESIRED::>> ");
	      scanf("%d",&room);
	      while(!feof(fp))
	       {
		  if(c.room==room)
		    {
		    textcolor(LIGHTGRAY);
		    drawrect(1,4,80,24);
		    textcolor(RED);
		    drawrect(25,7,45,9);
		    gotoxy(27,8);
		    textcolor(WHITE);
		    cprintf("ROOM IS OCCUPPIED");
		    gotoxy(15,12);
		    printf("ITS STATUS IS ");
		    gotoxy(30,12);
		    textcolor(RED+BLINK);
		    cprintf("::>>");
		    textcolor(WHITE);
		    gotoxy(36,12);
		    cprintf("%d",c.status);
		    gotoxy(10,13);
		    printf("*********************************");
		    gotoxy(10,14);
		    printf("CUSTOMER NAME   :-----%s",c.name);
		    gotoxy(10,15);
		    printf("CUSTOMER ADDRESS:-----%s",c.address);
		    gotoxy(10,16);
		    printf("DAYS FOR STAY:-----%d",c.days);
		    gotoxy(10,17);
		    printf("************************************");
		    gotoxy(10,20);
		    printf("ADVANCE PAID :---[  %.1f  ]",c.advance);
		    goto sap;
		    }
		    fscanf(fp,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
		}
		gotoxy(15,11);
		printf("*******************************************");
		gotoxy(25,13);
		printf("ITS NOT OCCUPIED");
		gotoxy(20,15);
		printf("ROOM ##  %d  ## IS EMPTY",room);
		gotoxy(15,17);
		printf("*****************************************");
	     fclose(fp);
	   sap:getch();
	   break;
		}
	     } //inner1over
	     break;
	    }
	     case 'F':
	     {
	     gotoxy(25,8);
	     printf("*************************************");
	     gotoxy(25,9);
	     printf("press 1 for ALL CATEGORY DISPLAY");
	     gotoxy(25,10);
	     printf("press 2 for PARTICULAR CATEGORY");
	     gotoxy(25,13);
	     printf("ENTER UR CHOICE::>> ");
	     scanf("%d",&co);
	     switch(co)
	     {//inner2
	     case 1:
		 {
		 clrscr();
		 textcolor(RED);
		 drawrect(1,1,80,3);
		 gotoxy(30,2);
		 textcolor(WHITE);
		 cprintf("CATEGORY WISE DISPLAY");
		 textcolor(LIGHTGRAY);
		 drawrect(1,4,17,22);
		 drawrect(21,4,29,22);
		 drawrect(30,4,80,22);
		 textcolor(LIGHTCYAN);
		 gotoxy(2,5);
		 cprintf("ORDINARY SINGLE");
		 gotoxy(22,5);
		 printf("Rs. 100");
		 gotoxy(22,6);
		 printf("-------");
		 gotoxy(31,5);
		 printf("FAN------------BATHROOM--T.V.--14Hrs.service");
		 gotoxy(31,6);
		 printf("-------------------------------------------------");
		 gotoxy(2,6);
		 printf("---------------");
		 gotoxy(2,7);
		 cprintf("ORDINARY DOUBLE");
		 gotoxy(22,7);
		 printf("Rs. 100");
		 gotoxy(31,7);
		 printf("FAN--BATHROOM--T.V.--14Hrs.service--PHONE");
		 gotoxy(2,8);
		 printf("---------------");
		 gotoxy(22,8);
		 printf("-------");
		 gotoxy(31,8);
		 printf("-------------------------------------------------");
		 gotoxy(2,9);
		 cprintf("DELUXE SINGLE");
		 gotoxy(2,11);
		 printf("---------------");
		 gotoxy(22,9);
		 printf("Rs. 200");
		 gotoxy(22,11);
		 printf("-------");
		 gotoxy(31,9);
		 printf("AIR COOLER--BATHROOM WITH GEYSER--PHONE--");
		 gotoxy(31,10);
		 printf("C.T.V. WITH CABLE--18Hrs.service--LAUNDRY--");
		 gotoxy(31,11);
		 printf("-------------------------------------------------");
		 gotoxy(2,12);
		 cprintf("DELUXE DOUBLE");
		 gotoxy(2,14);
		 printf("---------------");
		 gotoxy(22,12);
		 printf("Rs. 200");
		 gotoxy(22,14);
		 printf("-------");
		 gotoxy(31,12);
		 printf("AIR COOLER--BATHROOM WITH GEYSER--PHONE--");
		 gotoxy(31,13);
		 printf("C.T.V CABLE--20Hrs.service--LAUNDRY--");
		 gotoxy(31,14);
		 printf("-------------------------------------------------");
		 gotoxy(2,15);
		 cprintf("S.DELUXE SINGLE");
		 gotoxy(2,18);
		 printf("---------------");
		 gotoxy(22,15);
		 printf("Rs. 300");
		 gotoxy(22,18);
		 printf("-------");
		 gotoxy(31,15);
		 printf("AIR CONDITIONED--BATHROOM WITH GEYSER--PHONE--");
		 gotoxy(31,16);
		 printf("C.T.V WITH CABLE--V.C.D--24Hrs.service--LAUNDRY--");
		 gotoxy(31,17);
		 printf("SEASIDE VIEW--CAR");
		 gotoxy(31,18);
		 printf("-------------------------------------------------");
		 gotoxy(2,19);
		 cprintf("S.DELUXE DOUBLE");
		 gotoxy(22,19);
		 printf("Rs. 300");
		 gotoxy(31,19);
		 printf("AIR CONDITIONED--BATHROOM WITH GEYSER--PHONE--");
		 gotoxy(31,20);
		 printf("C.T.V WITH CABLE--V.C.D--24Hrs.service--LAUNDRY--");
		 gotoxy(31,21);
		 printf("SEASIDE VIEW--CAR");
		 textcolor(WHITE);
		  getch();
		 break;
		   }
	       case 2:
		   {
		   clrscr();
	      drawrect(1,1,80,3);
	      gotoxy(25,2);
	      printf("WHICH TYPE OF ROOM CUSTOMER WANTS");
	      textcolor(13+BLINK);
	      cprintf("  ?");
	      textcolor(GREEN);
	      drawrect(1,8,80,20);
	      gotoxy(2,9);
	      printf("          | Ordinary | Ordinary | Deluxe | Deluxe | S.Deluxe | S.Deluxe |");
	      gotoxy(2,10);
	      printf("          |    &     |    &     |    &   |    &   |     &    |     &    |");
	      gotoxy(2,11);
	      printf("          |  Single  |  Double  | Single | Double |  Single  |  Double  |");
	      gotoxy(2,12);
	      printf(" ---------|------------------------------------------------------------ |");
	      gotoxy(2,13);
	      printf("  Pressing|          |          |        |        |          |          | ");
	      gotoxy(2,14);
	      printf("    Keys  |     1    |    11    |    2   |    22  |     3    |     33   |");
	      gotoxy(2,15);
	      printf(" =========|=============================================================|");
	      gotoxy(2,16);
	      textcolor(14+BLINK);
	      gotoxy(30,18);
	      cprintf("Enter status   ");
	      scanf("%d",&co);
	      flushall();
	      textcolor(WHITE);
		      switch(co)
		       {//inner21
		       case 1:
		       {
		      clrscr();
		      drawrect(1,1,80,3);
		      gotoxy(35,2);
		      printf("ORDINARY AND SINGLE");
		      drawrect(1,4,80,20);
		      gotoxy(4,6);
		      printf("THE FACILITIES TO THE ROOM ARE AS FOLLOWS::>>");
		      gotoxy(4,7);
		      printf("                                    1.FAN");
		      gotoxy(4,8);
		      printf("                                    2.BATHROOM");
		      gotoxy(4,9);
		      printf("                                    3.TELEVISION");
		      gotoxy(4,10);
		      printf("                                    4. FOURTEEN HRS.SERVICE");
		      drawrect(30,15,70,17);
		      gotoxy(31,16);
		      printf("RATE OF ROOM::::>>>>Rs. 100 perday");
		      break;
		      }
		      case 11:
		      {
		      clrscr();
		      drawrect(1,1,80,3);
		      gotoxy(35,2);
		      printf("ORDINARY AND DOUBLE");
		      drawrect(1,4,80,20);
		      gotoxy(4,6);
		      printf("THE FACILITIES TO THE ROOM ARE AS FOLLOWS::>>");
		      gotoxy(4,7);
		      printf("                                    1.FAN");
		      gotoxy(4,8);
		      printf("                                    2.BATHROOM");
		      gotoxy(4,9);
		      printf("                                    3.TELEVISION");
		      gotoxy(4,10);
		      printf("                                    4.FOURTEEN HRS.SERVICE");
		      drawrect(30,15,70,17);
		      gotoxy(31,16);
		      printf("RATE OF ROOM::::>>>>Rs. 100 perday");
		      break;
		      }
		      case 2:
		      {
		      clrscr();
		      drawrect(1,1,80,3);
		      gotoxy(35,2);
		      printf("DELUXE AND SINGLE");
		      drawrect(1,4,80,20);
		      gotoxy(4,6);
		      printf("THE FACILITIES TO THE ROOM ARE AS FOLLOWS::>>");
		      gotoxy(4,7);
		      printf("                                    1.AIR COOLER");
		      gotoxy(4,8);
		      printf("                                    2.BATHROOM WITH GEYSER");
		      gotoxy(4,9);
		      printf("                                    3.COLOR TELEVISION");
		      gotoxy(4,10);
		      printf("                                    4.CABLE CONNECTION");
		      gotoxy(4,11);
		      printf("                                    5.EIGHTEEN HRS.SERVICE");
		      gotoxy(4,12);
		      printf("                                    6.LAUNDRY");
		      gotoxy(4,13);
		      printf("                                    7.PHONE");
		      drawrect(30,16,70,18);
		      gotoxy(31,17);
		      printf("RATE OF ROOM::::>>>>Rs. 200 perday");
		      break;
		      }
		      case 22:
		      {
		      clrscr();
		      drawrect(1,1,80,3);
		      gotoxy(35,2);
		      printf("DELUXE AND SINGLE");
		      drawrect(1,4,80,20);
		      gotoxy(4,6);
		      printf("THE FACILITIES TO THE ROOM ARE AS FOLLOWS::>>");
		      gotoxy(4,7);
		      printf("                                    1.AIR COOLER");
		      gotoxy(4,8);
		      printf("                                    2.BATHROOM WITH GEYSER");
		      gotoxy(4,9);
		      printf("                                    3.COLOR TELEVISION");
		      gotoxy(4,10);
		      printf("                                    4.CABLE CONNECTION");
		      gotoxy(4,11);
		      printf("                                    5.TWENTY HRS.SERVICE");
		      gotoxy(4,12);
		      printf("                                    6.LAUNDRY");
		      gotoxy(4,13);
		      printf("                                    7.PHONE");
		      drawrect(30,16,70,18);
		      gotoxy(31,17);
		      printf("RATE OF ROOM::::>>>>Rs. 200 perday");
		      break;
		      }
		      case 3:
		      {
		      clrscr();
		      drawrect(1,1,80,3);
		      gotoxy(35,2);
		      printf("S.DELUXE AND SINGLE");
		      drawrect(1,4,80,20);
		      gotoxy(4,6);
		      printf("THE FACILITIES TO THE ROOM ARE AS FOLLOWS::>>");
		      gotoxy(4,7);
		      printf("                                    1.AIR CONDITIONER");
		      gotoxy(4,8);
		      printf("                                    2.BATHROOM WITH GEYSER");
		      gotoxy(4,9);
		      printf("                                    3.COLOR TELEVISION");
		      gotoxy(4,10);
		      printf("                                    4.CABLE CONNECTION");
		      gotoxy(4,11);
		      printf("                                    5.V.C.D PLAYER");
		      gotoxy(4,12);
		      printf("                                    5.TWENTY HRS.SERVICE");
		      gotoxy(4,13);
		      printf("                                    6.LAUNDRY");
		      gotoxy(4,14);
		      printf("                                    7.SEASIDE VIEW");
		      gotoxy(4,15);
		      printf("                                    8.CAR");
		      gotoxy(4,16);
		      printf("                                    9.PHONE");
		      drawrect(30,17,70,19);
		      gotoxy(31,18);
		      printf("RATE OF ROOM::::>>>>Rs. 300 perday");
		      break;
		      }
		      case 33:
		      {
		      clrscr();
		      drawrect(1,1,80,3);
		      gotoxy(35,2);
		      printf("S.DELUXE AND DOUBLE");
		      drawrect(1,4,80,20);
		      gotoxy(4,6);
		      printf("THE FACILITIES TO THE ROOM ARE AS FOLLOWS::>>");
		      gotoxy(4,7);
		      printf("                                    1.AIR CONDITIONER");
		      gotoxy(4,8);
		      printf("                                    2.BATHROOM WITH GEYSER");
		      gotoxy(4,9);
		      printf("                                    3.COLOR TELEVISION");
		      gotoxy(4,10);
		      printf("                                    4.CABLE CONNECTION");
		      gotoxy(4,11);
		      printf("                                    5.V.C.D PLAYER");
		      gotoxy(4,12);
		      printf("                                    5.TWENTY HRS.SERVICE");
		      gotoxy(4,13);
		      printf("                                    6.LAUNDRY");
		      gotoxy(4,14);
		      printf("                                    7.SEASIDE VIEW");
		      gotoxy(4,15);
		      printf("                                    8.CAR");
		      gotoxy(4,16);
		      printf("                                    9.PHONE");
		      drawrect(30,17,70,19);
		      gotoxy(31,18);
		      printf("RATE OF ROOM::::>>>>Rs. 300 perday");
		     break;
		      }
		   }//inner21over
		   getch();
		   break;
		    }
		 }
		 break;
		 }//case2over//****
	 case 'O':
	 {
	      clrscr();
	      fp=fopen("hotel.dat","r");
	      fscanf(fp,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
	      textcolor(RED);
	      drawrect(1,1,80,3);
	      gotoxy(28,2);
	      textcolor(WHITE);
	      printf("OCCUPIED--[y/n]");
	      textcolor(LIGHTGRAY);
	      drawrect(1,4,80,24);
	      gotoxy(2,5);
	      textcolor(WHITE);
	      printf("ENTER THE ROOM WHOSE OCCUPANT IS DESIRED::>> ");
	      scanf("%d",&room);
	      while(!feof(fp))
	       {
		  if(c.room==room)
		    {
		    textcolor(RED);
		    drawrect(25,7,50,9);
		    gotoxy(29,8);
		    textcolor(WHITE);
		    printf("ROOM IS OCCUPIED");
		    gotoxy(3,10);
		    printf("ITS ROOM IS ::>> %d",c.room);
		    gotoxy(10,11);
		    printf("***********************************");
		    gotoxy(10,13);
		    printf("CUSTOMER NAME   :-----%s",c.name);
		    gotoxy(10,14);
		    printf("CUSTOMER ADDRESS:-----%s",c.address);
		    gotoxy(10,15);
		    printf("DAYS FOR STAY:-----%d",c.days);
		    gotoxy(10,16);
		    printf("STATUS OF THE ROOM:-----%d",c.status);
		    gotoxy(10,17);
		    printf("************************************");
		    gotoxy(10,20);
		    printf("ADVANCE PAID :---%f",c.advance);
		    goto sa;
		    }
		    fscanf(fp,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
		}
		gotoxy(2,7);
		printf("             ****************************************************");
		gotoxy(10,11);
		printf("                  ITS NOT OCCUPIED");
		gotoxy(7,14);
		printf("             ROOM ##  %d  ## IS EMPTY",room);
		gotoxy(2,17);
		printf("             ****************************************************");
	     fclose(fp);
	     sa:getch();
	     break;
	     }//case3 over
       case 'C':
	   {
	   clrscr();
	   textcolor(RED);
	   drawrect(1,1,80,3);
	   textcolor(WHITE+BLINK);
	   gotoxy(20,2);
	   cprintf("******************RATE CHART****************\n");
	   textcolor(BLUE);
	   drawrect(1,8,80,10);
	  gotoxy(2,9);
	  cprintf("  CATEGORY       ####       RATE       ####      STATUS   ####");
	  textcolor(RED);
	  drawrect(1,10,80,19);
	  gotoxy(2,12);
	  textcolor(MAGENTA);
	  cprintf("  ORDINARY& single        :    Rs.100.00    :     1");
	  gotoxy(2,13);
	  cprintf("  ORDINARY& double        :    Rs.100.00    :    11");
	  gotoxy(2,14);
	  cprintf("  DELUXE& single          :    Rs.200.00    :     2");
	  gotoxy(2,15);
	  cprintf("  DELUXE& double          :    Rs.200.00    :    22");
	  gotoxy(2,16);
	  cprintf("  S.DELUXE& single        :    Rs.300.00    :     3");
	  gotoxy(2,17);
	  cprintf("  S.DELUXE& double        :    Rs.300.00    :     33");
	  textcolor(WHITE);
	  getch();
	  break;
	  }
     case 'U':
	  {
	   clrscr();
	   upgrade();
	   break;
	   }
     case 'M':
	  {
	  goto prev;
	  }
      }//outerswitch
      goto back;
      prev:
}
//THIS IS USED TO DELETE THE RECORD WHEN A CUSTOMER CHECKS OUT
void deletion()
{
      struct cust c;
      int room;
      fp=fopen("hotel.dat","r");
      fptr=fopen("trans.dat","a");
      printf(" ENTER ROOM TO BE DELETED::>> ");
      scanf("%d",&room);
      fscanf(fp,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
      while(!feof(fp))
	{
	if(c.room!=room)
	{
	fprintf(fptr,"%s %s %d %f %d %d",c.name,c.address,c.days,c.advance,c.status,c.room);
	fprintf(fptr,"\n");
	}
	fscanf(fp,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
	}
	fclose(fptr);
	fclose(fp);
	remove("hotel.dat");
	rename("trans.dat","hotel.dat");
}
//PART OF THE BOOKING FUNCTION ::PURPOSE TO CHANGE ROOM NUMBER
void roomchange()
{
    int t,room,ro,d;
    struct cust c;
    int i,j;
    t=1;
    fp=fopen("hotel.dat","r");
    tptr=fopen("trans.dat","a");
    textcolor(RED);
    drawrect(1,1,80,3);
    gotoxy(30,2);
    textcolor(WHITE);
    printf("CHANGE ROOM FACILITY");
    textcolor(WHITE);
    drawrect(1,5,80,20);
    gotoxy(2,6);
    printf("ENTER THE ROOM U WANT TO CHANGE::>> ");
    scanf("%d",&ro);
    fscanf(fp,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
    while(!feof(fp))
       {

	if(c.room==ro)
	 {
	 t=0;
	 gotoxy(3,8);
	 printf("ROOM is FOUND ");
	 i=3;j=9;
     sam:printf("  WISH To Change The RoomNumber::>> ");
	 scanf("  %d",&room);
	 gotoxy(i,j);
	 d=valid(room);
	 if(d==0)
	 {
	 j++;
	 goto sam;
	 }
	 else
	  c.room=room;
	 flushall();
	 fprintf(tptr,"%s %s %d %f %d %d\n",c.name,c.address,c.days,c.advance,c.status,c.room);
	 gotoxy(15,19);
	 printf("ROOM CHANGED");
	 goto t;
	}
       fprintf(tptr,"%s %s %d %f %d %d\n",c.name,c.address,c.days,c.advance,c.status,c.room);
     t: fscanf(fp,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
	}
       if(t==1)
       {
       gotoxy(15,17);
       printf("ROOOM NOT FOUND");
       }
	fclose(tptr);
	fclose(fp);
	remove("hotel.dat");
	rename("trans.dat","hotel.dat");
	getch();
}
//FUNCTION TO DRAW RECTANGLES
void drawrect(int l,int t,int r,int b)
     {
	int i=0;
	gotoxy(l,t);
	cprintf("É");
	for(i=l+1;i<=r-1;i++)
	{
		gotoxy(i,t);
		cprintf("Í");
	}
	gotoxy(r,t);
	cprintf("»");
	for(i=1;i<=b-t-1;i++)
	{
		gotoxy(l,t+i);
		cprintf("º");
		gotoxy(r,t+i);
		cprintf("º");
	}
	gotoxy(l,b);
	cprintf("È");
	gotoxy(l+1,b);
	for(i=l+1;i<=r-1;i++)
		cprintf("Í");
	gotoxy(r,b);
	cprintf("¼");
}
//FOR LOCAL USE IN BOOKING FUNCTION
void roomsee()
{
	struct cust c;
	int stat;
	char t;
	fp=fopen("hotel.dat","r");
	 fscanf(fp,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
	 printf("\nDO U WANT TO SEE OCCUPIED ROOMS WITH STATUS[y/n]::>>");
	 scanf("%s",&t);
	 if(t=='n')
	 {
	 printf("ENTER ROOM BEARING STATUS::>>");
	 scanf("%d",&stat);
	 }
	 while(!feof(fp))
	      {
	      if(t=='y')
	      {
	      printf("##%d---status->%d\n",c.room,c.status);
	      }
	      else
		{
		  if(c.status==stat)
		    {
		     printf("##%d---status->%d\n",c.room,c.status);
		     }
	      }
	      fscanf(fp,"%s %s %d %f %d %d",c.name,c.address,&c.days,&c.advance,&c.status,&c.room);
	      }
	 fclose(fp);
	  printf("*********************************************************************");
}
//THIS FUNCTION'S PURPOSE IS TO PUT A CHECK OR MARK FOR UPGRADATION
void upgrade()
{
	struct cust c;
	int room;
	textcolor(LIGHTGRAY);
	drawrect(1,1,80,3);
	gotoxy(30,2);
	textcolor(BLUE);
	printf("UPGRADATION/REPAIRING");
	textcolor(RED);
	drawrect(1,4,80,24);
	gotoxy(3,6);
	printf("ENTER ROOM NO. TO BE UPGRADED OR REPAIRED::>> ");
	scanf("%d",&room);
	strcpy(c.name,"UPGRADED");
	strcpy(c.address,"REPAIRING");
	c.days=0;
	c.advance=00.00;
	c.status=0;
	c.room=room;
	fp=fopen("hotel.dat","a");
	fprintf(fp,"%s %s %d %f %d %d",c.name,c.address,c.days,c.advance,c.status,c.room);
	fclose(fp);
	textcolor(WHITE);
}

