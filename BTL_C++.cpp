#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<string>
#include<iostream>
#define PI 3.14582
#define step 1
#define step_v 0.01

// chuy?n trang
void switchpage(int page)
{
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        
}

// Hàm v? m?t nghiêng, v? ô tô và giá d? ô tô, v? ròng r?c
void ve(int &x1,int &y1,int &x2,int &y2,int maxX,int maxY)
{
		
    	
    		// v? m?t ph?ng nghiêng 
		line(450,275,450,625);// v? chi?u cao c?a m?t ph?ng nghiêng
		line(100,625,450,275);// v? c?nh huy?n c?a m?t ph?ng nghiêng
    	/*----------------------*/
    	/* v? ô tô và giá d? c?a nó */
    	line(x1,y1,x2+13,y2+13);// C?nh ng?n ? bên ph?i
    	line(x1-101,y1+99,x2-88,y2+112);// c?nh ng?n ? bên trái
    	line(x1-101,y1+99,x2-50,y2-50);//	c?nh dài ? bên ph?i
    	line(x2+13,y2+13,x2-88,y2+112);// c?nh dài ? du?i
    	line(maxX/2,maxY/2,maxX/2,maxY/2+200);// c?nh bên trái ch?a ô tô
    	line(maxX/2, maxY / 2, maxX, maxY / 2);// du?ng ch?a ô tô
    	line(0, maxY / 2+100+100, maxX, maxY / 2+100+100);// du?ng ch?a m?t ph?ng nghiêng
    	/**********************/
    	/*  V? ròng r?c  */
	    line(662,0,662,15); // V? giá d? ròng r?c
	    line(x1+31,y1+31,632,31);// v? du?ng th?ng n?i t? v?t d?n ròng r?c
	    circle(662,50,35);// v? hình tròn tâm (662,50) bán kính 35 (   )
    	/*------------*/
    	
    	
}



void xe(int &pos_Car) 
{    //v? theo chi?u kim d?ng h? t?i v? trí pos_Car + x
	
	line(pos_Car+375,405,pos_Car+375,350);// c?nh s? 1
	line(pos_Car+375,350,pos_Car+475,350);// c?nh s? 2
	line(pos_Car+475,350,pos_Car+505,380);// c?nh s? 3
	line (pos_Car+505,380,pos_Car+505,405);// c?nh s? 4
	line (pos_Car+505,405,pos_Car+495,405);// c?nh s? 5
	line  (pos_Car+455,405,pos_Car+430,405);// c?nh s? 6
	line (pos_Car+375,405,pos_Car+390,405);// c?nh s? 7
	circle(pos_Car+335+25+25+25,405,20);// v? hình tròn tâm (662,50) bán kính 20
	circle(pos_Car+400+25+25+25,405,20);// v? hình tròn tâm (662,50) bán kính 20
	

}

void vanhxe1(int &x1,int &y1,int &x2,int &y2,int &x3,int &y3,int &x,int centerY)
{	// V? vành xe bên trái
	
		line(x+410,centerY,x1,y1);// v? vành xe
        line(x+410,centerY,x2,y2);// v? vành xe
        line(x+410,centerY,x3,y3);// v? vành xe
        
      
}

void vanhxe2(int &x1,int &y1,int &x2,int &y2,int &x3,int &y3,int &x,int centerY)
{
	// V? vành xe bên ph?i
	line(x+475,centerY,x1,y1) ; //v? vành xe
	line(x+475,centerY,x2,y2) ; //v? vành xe
	line(x+475,centerY,x3,y3) ; //v? vành xe
	
}

void vanhrongroc(int &x1,int &y1,int &x2,int &y2,int &x3,int &y3,int &x4,int &y4)
{
	// V? vành c?a ròng r?c
	line(662,50,x1,y1);
	line(662,50,x2,y2);
	line(662,50,x3,y3);
	line(662,50,x4,y4);
	
}


int main()
{ 

    // T?o c?a s? d? h?a
    DWORD screenwidth=GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenwidth,screenHeight,"",-3);
    int unknowvari=0;
	int x1=150;
	int y1=450;
	int x2=200;
	int y2=500;
	int k=500;
	char p;
	int cnt=0;// ki?m tra phím Enter du?c ?n
	char buffer[50];
	float tmp=0;
	int radius=20;// Bán kính vành xe 
	int r=35;// Bán kính ròng r?c
	double angle = 0; // Góc quay            
    int page=0; // Chuy?n trang
    int n=0; 
	int pos_Car=500; // T?a d? ban d?u
	int x=500,y=400; 	
	int centerX=910,centerY=405; // Ði?m chính gi?a c?a bánh xe
    int maxX = 1500; // Chi?u r?ng màn hình
    int maxY = 850; // Chi?u cao màn hình
    char s[50]="Loading...";

    int x11,y11,x21,y21,x31,y31;
    int x12,y12,x22,y22,y32,x32;
    int xr1,yr1,xr2,yr2,xr3,yr3,xr4,yr4;
    int Car_Color = 15 ;
    //	T?o giao di?n khi b?t d?u
    	
    	while(n==0)
        {
            
            rectangle(550+25,320,700+25,340); // V? hình ch? nh?t lúc m?i ch?y loading
            for(int i=0; i<148; i++)
            {
                setcolor(11);
                line(551+i+25,321,551+i+25,339);
                setcolor(11);
                settextstyle(0,0,2);
                outtextxy(580,350,s);
                delay(10);
            }
            
            setcolor(11);
            settextstyle(0,0,3);
            outtextxy(359,396,const_cast<char*>("Press Any Key To Continue... "));
           getch();
		   n++;
			
        }
        
	while(1)
    {	
  		switchpage(page);//  Hàm xóa trang cu
    
    //----------------- Trang trí----------------------//
	
	//-------------Thông tin thành viên----------//
		setcolor(11);
		line(40,35,350,35);
		line(40,35,40,185);
		line(40,185,350,185);
		line(350,185,350,35);
		settextstyle(4,0,1);
		outtextxy(46,40,const_cast<char*>(" C++ Project - Group 3"));
		settextstyle(3,0,1);
		setcolor(12);
		outtextxy(55,70,const_cast<char*>("Trinh Quang Lam"));
		outtextxy(55,96,const_cast<char*>("Nguyen Duc Dat"));
		outtextxy(55,122,const_cast<char*>("Luu Minh Hien"));
		setcolor(YELLOW);
		outtextxy(55,148,const_cast<char*>("Topic: Physics experiment"));
	//------------------------------------------------//
	
			//------------------ Nút di chuy?n ----------------//
			
			 	//-------------- Sang trái -------------------//
			 	
			 		setcolor(10);
			 		line(600,675,700,675);
			 		line(600,675,600,725);
			 		line(600,725,700,725);
			 		line(700,725,700,675);
			 		line(625,700,675,700);
			 		line(625,700,635,710);
			 		line(625,700,635,690);
			 		
				//---------------------------------------//	 	
			 
			 	//-------------- Sang ph?i ------------------//
			 	
			 		setcolor(10);
			 		line(800,675,900,675);
			 		line(800,675,800,725);
			 		line(800,725,900,725);
			 		line(900,725,900,675);
			 		line(825,700,875,700);
			 		line(875,700,865,690);
			 		line(875,700,865,710);
			 		
				//---------------------------------------//
				
				settextstyle(4,0,1);
				setcolor(YELLOW);
			 	outtextxy(610,750,const_cast<char*>("Click to move the Car!"));
			 	outtextxy(630,770,const_cast<char*>("Press Alt + F4 to exit."));
			 	
			
			//-------------------------------------------------//
	
	
	//----------Thông s? v?n t?c c?a xe--------//
			
			setcolor(11);
			rectangle(609,126,709,221); // V? ra hình ch? nh?t ch?a thông s? v?n t?c
			settextstyle(1,0,1);
			setcolor(10);
			outtextxy(618,130,const_cast<char*>("Speed"));
			setcolor(WHITE);
			outtextxy(638,190,const_cast<char*>("m/s"));
	
	//-------------------------------------------------------//
	
	//-------------------Chú thích d?i màu-------------------------//
	
	settextstyle(3,0,1);
	setcolor(WHITE);
   	line(1100,450,1100,600);
   	setcolor(15);
   	outtextxy(800,451,const_cast<char*>("1: Change to Bright White color")); 
   	setcolor(14);
   	outtextxy(800,481,const_cast<char*>("2: Change to Light Yellow color"));
   	setcolor(13);
   	outtextxy(800,511,const_cast<char*>("3: Change to Light Purple color"));
   	setcolor(12);
   	outtextxy(800,541,const_cast<char*>("4: Change to Light Red color"));
   	setcolor(11);
   	outtextxy(800,571,const_cast<char*>("5: Change to Light Aqua color"));
   	
   	
   	setcolor(10);
   	outtextxy(1150,451,const_cast<char*>("6: Change to Light Green color"));
   	setcolor(9);
   	outtextxy(1150,481,const_cast<char*>("7: Change to Light Blue color"));
   	setcolor(8);
   	outtextxy(1150,511,const_cast<char*>("8: Change to Grey color"));
   	setcolor(6);
   	outtextxy(1150,541,const_cast<char*>("9: Change to Yellow color"));
   	setcolor(3);
   	outtextxy(1150,571,const_cast<char*>("0: Change to Aqua color"));
	//------------------------------------------------------//
	
	//-------------------------------------------------//
	


		/* Thay d?i v? trí c?a vành xe bên trái */
		// T?a d? các di?m trên vành xe theo chi?u kim d?ng h?
		// Vì x,y là tâm,ch? c?n cho kho?ng cách t? tâm d?n 1 di?m b?ng r thì thu?c du?ng tròn
    	 x11=x+410+radius*cos(angle);
		 y11=centerY+radius*sin(angle);
		 x21=x+410+radius*cos(angle+2*PI/3);
		 y21=centerY+radius*sin(angle+2*PI/3);
		 x31=x+410+radius*cos(angle+4*PI/3);
		 y31=centerY+radius*sin(angle+4*PI/3);
		 /*******/
		
		
		 /* Thay d?i v? trí c?a vành xe bên ph?i */
		// T?a d? các di?m trên vành xe theo chi?u kim d?ng h?
		// Vì x,y là tâm,ch? c?n cho kho?ng cách t? tâm d?n 1 di?m b?ng r thì thu?c du?ng tròn
		 x12=x+475+radius*cos(angle);         
		 y12=centerY+radius*sin(angle);
		 x22=x+475+radius*cos(angle+2*PI/3);
		 y22=centerY+radius*sin(angle+2*PI/3);
		 x32=x+475+radius*cos(angle+4*PI/3);
		 y32=centerY+radius*sin(angle+4*PI/3);
		 
		 

		  /*****************/
		  
		  
		  
		  /* Thay d?i v? trí c?a vành ròng r?c  */
		  
		 xr1=662+r*cos(angle);
		 yr1=50+r*sin(angle);
		 xr2=662+r*cos(angle+PI/2);
		 yr2=50+r*sin(angle+PI/2);
		 xr3=662+r*cos(angle+PI);
		 yr3=50+r*sin(angle+PI);
		 xr4=662+r*cos(angle+3*PI/2); 
		 yr4=50+r*sin(angle+3*PI/2); 
		 // B?m các phím d? d?i màu
		  if(GetAsyncKeyState('1'))
        {
        	Car_Color=15;
        	
		}
		if(GetAsyncKeyState('2'))
		{
			Car_Color=14;
		}
		if(GetAsyncKeyState('3'))
		{
			Car_Color=13;
		}
		if(GetAsyncKeyState('4'))
		{
			Car_Color=12;
		}
        if(GetAsyncKeyState('5'))
        {
        	Car_Color=11;
		}
		if(GetAsyncKeyState('6'))
		{
			Car_Color=10;
		}
		if(GetAsyncKeyState('7'))
		{
			Car_Color=9;
		}
		if(GetAsyncKeyState('8'))
		{
			Car_Color=8;
		}
		if(GetAsyncKeyState('9'))
		{
			Car_Color=6;
		}
		if(GetAsyncKeyState('0'))
		{
			Car_Color=3;
		}
		  
		  /********************/
		 /* V? trí xe m?i */
		 // S?a màu m?i cho xe 
    	setcolor(Car_Color);
    	xe(pos_Car); 
    	vanhxe1(x11,y11,x21,y21,x31,y31,x,centerY);
    	vanhxe2(x12,y12,x22,y22,x32,y32,x,centerY);
    	setcolor(Car_Color);
    	vanhrongroc(xr1,yr1,xr2,yr2,xr3,yr3,xr4,yr4);
    	circle(662,50,35);  // V? l?i hình tròn ròng r?c
    	ve(x1,y1,x2,y2,maxX,maxY);
    	line(pos_Car+410,325,662+29,30); // V? dây nôi t? ròng r?c d?n ô tô
    	line(pos_Car+410,350,pos_Car+410,325);// V? c?t d?c trên ô tô
    	circle(pos_Car+410,325,6);//	Hình tròn trên dây n?i v?i ô tô
		// Delay 10 ms
    	delay(10);
    	
    	/*------------------------*/
    	
		//
     	page=1-page;
     	
     	int check=0;// Ki?m tra n?u ngu?i dùng không b?m phím di chuy?n thì v?n t?c c?p nh?t v? 0
     	if(GetAsyncKeyState(VK_LEFT)) // Ki?m tra n?u b?m phím bên trái
     	   if(GetAsyncKeyState(VK_RIGHT)) // Ki?m tra n?u b?m phím bên ph?i
     	   {
     	   	// N?u b?m c? 2 nút thì d?i màu và xe d?ng yên, khi dó v?n t?c c?p nh?t v? 0
     	   	tmp=0;
     	   	setcolor(7);
			outtextxy(650,160,const_cast<char*>("0"));
			setcolor(12);
        	line(600,675,700,675);
			line(600,675,600,725);
			line(600,725,700,725);
			line(700,725,700,675);
			line(625,700,675,700);
			line(625,700,635,710);
			line(625,700,635,690);
			
			line(800,675,900,675);
			line(800,675,800,725);
			line(800,725,900,725);
			line(900,725,900,675);
			line(825,700,875,700);
			line(875,700,865,690);
			line(875,700,865,710);
			n++;
			continue;
			}
     	 
     	if(GetAsyncKeyState(VK_LEFT))
        {
			check=1; // Ngu?i dùng b?m phím
			// Ð?i màu cho nút b?m
        	setcolor(12);
        	line(600,675,700,675);
			line(600,675,600,725);
			line(600,725,700,725);
			line(700,725,700,675);
			line(625,700,675,700);
			line(625,700,635,710);
			line(625,700,635,690);
			n++;
			
			/* C?p nh?t t?a d? m?i cho xe*/
			if(x2-88>100) // Ki?m tra n?u v?t chua ch?m m?c bên trái. x2-88 là t?a d? mép trái góc du?i c?a v?t
			{
				x1-=step;
	     		y1+=step;
	     		x2-=step;
	     		y2+=step;
	     		pos_Car-=step;
	     		angle-=0.05;
     			x-=step;
     			tmp+=step_v; 
				// Chuy?n tmp thành string d? in màn hình b?ng l?nh outtextxy. 
				sprintf(buffer,"%.2f",tmp); 
				setcolor(7);
				outtextxy(641,160,buffer); 
			}
			
			// Khi v?t ch?m m?c bên trái thì dua ra dòng c?nh báo
			if(x2-88==100) // Khi dó v?t ch?m m?c du?i c?a m?t ph?ng nghiêng
			{
				setcolor(7);
				outtextxy(641,160,buffer);
				tmp=0; // Khi dó v?n t?c m?i s? b?t d?u t? 0
				setcolor(12);
				outtextxy(616,250,const_cast<char*>(" Warning!"));
				outtextxy(563,280,const_cast<char*>("Please turn on the right!"));
				
			}
        }
        
        else
        {
			// N?u ngu?i dùng không b?m n?a thì phím chuy?n thành màu xanh ban d?u và v?n t?c c?p nh?t v? 0
        	setcolor(7);
			outtextxy(650,160,const_cast<char*>("0"));
        	setcolor(10);
			line(600,675,700,675);
			line(600,675,600,725);
			line(600,725,700,725);
			line(700,725,700,675);
			line(625,700,675,700);
			line(625,700,635,710);
			line(625,700,635,690);
		}

        if(GetAsyncKeyState(VK_RIGHT)) // B?m nút sang ph?i
        {
        	check=1; 
        	n++;
			setcolor(12);
            line(800,675,900,675);
			line(800,675,800,725);
			line(800,725,900,725);
			line(900,725,900,675);
			line(825,700,875,700);
			line(875,700,865,690);
			line(875,700,865,710);
			
			/* T?c d? di chuy?n c?a xe và t?c d? quay c?a vành xe*/
			if(x2+13<450){// Khi v?t chua ch?m d?n mép trên c?a m?t ph?ng nghiêng thì ti?p t?c c?p nh?t t?a d?. 
				x1+=step;
		     	y1-=step;
		    	x2+=step;
		    	y2-=step;
		    	pos_Car+=step;
		        angle+=0.05;
	     	    x+=step;	 
				tmp+=step_v; 
				// Chuy?n tmp thành string d? in ra màn hình b?ng hàm outtextxy
				sprintf(buffer,"%.2f", tmp); 
				setcolor(7);
				outtextxy(641,160,buffer); 
			}
			
			// C?nh báo n?u v?t ch?m d?n góc trên c?a m?t ph?ng nghiêng
			if(x2+13==450)
			{
				setcolor(7);
				outtextxy(641,160,buffer);
				tmp=0;
				setcolor(12);
				outtextxy(616,250,const_cast<char*>(" Warning!"));
				outtextxy(563,280,const_cast<char*>("Please turn on the left!"));
				
			}
        }
        
        else
        {
			// N?u ngu?i dùng không b?m phím dó n?a thì phím thành màu xanh và v?n t?c c?p nh?t v? 0
        	setcolor(10);
			line(800,675,900,675);
			line(800,675,800,725);
			line(800,725,900,725);
			line(900,725,900,675);
			line(825,700,875,700);
			line(875,700,865,690);
			line(875,700,865,710);
			
		}
		delay(1);
		if(check==0) tmp=0;
		// Bi?n check d? ki?m tra n?u không b?m thì v?n t?c s? c?p nh?t v? 0
		
	}
     	
    getch();
    closegraph();
    return 0;
}

