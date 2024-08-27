#include <graphics.h> 
#include <cmath>
#include<iostream>

void translation()
{ int gd = DETECT,gm,left=100,top=200,right=200,bottom=200,x= 150,y=150,radius=50,degrees=0;
   initgraph(&gd,&gm,NULL);

   rectangle(50,50,150,120);
   delay(2000);
   cleardevice();
   int constant = 200;
   rectangle(50+constant,50+constant,150+constant,120+constant);



   delay(5000);
   closegraph();

}
void scaling()
{ int gd = DETECT,gm,left=100,top=200,right=200,bottom=200,x= 150,y=150,radius=50,degrees=0;
   initgraph(&gd,&gm,NULL);
   rectangle(50,50,150,120);
   delay(500);
   cleardevice();
   
   int constant = 2;
   rectangle(50*constant,50*constant,150*constant,120*constant);
   delay(5000);
   closegraph();

}

using namespace std;
int main()
{
    
  
   while (1)
   {
    cout<<"Choose the choice: 1) Translation 2) scaling 3) exit "<<endl;
    int ch;
    cin>>ch;

    switch (ch)
    {
    case 1:
        translation();
       
        break;
    case 2:
         scaling();
      
        break;
    case 3:
        goto hi;
        break;            
    
    default:
        cout<<"Please provide correct input"<<endl;
        break;
    }
    /* code */
   }

   hi:
   

   return 0;
}