#include "project.h"
void point(int x,int y) {
  VDAC8_2_SetValue(y);
  VDAC8_1_SetValue(x);
}
int8_t cosine[]={
    100,100,100,100,100,100,99,99,99,99,98,98,98,97,97,97,96,96,95,95,94,93,93,92,91,91,90,89,88,87,87,86,85,84,83,82,81,80,79,78,77,75,74,73,72,71,69,68,67,66,64,63,62,60,59,57,56,54,53,52,50,48,47,45,44,42,41,39,37,36,34,33,31,29,28,26,24,22,21,19,17,16,14,12,10,9,7,5,3,2,0,-2,-3,-5,-7,-9,-10,-12,-14,-16,-17,-19,-21,-22,-24,-26,-28,-29,-31,-33,-34,-36,-37,-39,-41,-42,-44,-45,-47,-48,-50,-52,-53,-54,-56,-57,-59,-60,-62,-63,-64,-66,-67,-68,-69,-71,-72,-73,-74,-75,-77,-78,-79,-80,-81,-82,-83,-84,-85,-86,-87,-87,-88,-89,-90,-91,-91,-92,-93,-93,-94,-95,-95,-96,-96,-97,-97,-97,-98,-98,-98,-99,-99,-99,-99,-100,-100,-100,-100,-100,-100,-100,-100,-100,-100,-100,-99,-99,-99,-99,-98,-98,-98,-97,-97,-97,-96,-96,-95,-95,-94,-93,-93,-92,-91,-91,-90,-89,-88,-87,-87,-86,-85,-84,-83,-82,-81,-80,-79,-78,-77,-75,-74,-73,-72,-71,-69,-68,-67,-66,-64,-63,-62,-60,-59,-57,-56,-54,-53,-52,-50,-48,-47,-45,-44,-42,-41,-39,-37,-36,-34,-33,-31,-29,-28,-26,-24,-22,-21,-19,-17,-16,-14,-12,-10,-9,-7,-5,-3,-2,0,2,3,5,7,9,10,12,14,16,17,19,21,22,24,26,28,29,31,33,34,36,37,39,41,42,44,45,47,48,50,52,53,54,56,57,59,60,62,63,64,66,67,68,69,71,72,73,74,75,77,78,79,80,81,82,83,84,85,86,87,87,88,89,90,91,91,92,93,93,94,95,95,96,96,97,97,97,98,98,98,99,99,99,99,100,100,100,100,100,100};
int8_t sine[]={0,2,3,5,7,9,10,12,14,16,17,19,21,22,24,26,28,29,31,33,34,36,37,39,41,42,44,45,47,48,50,52,53,54,56,57,59,60,62,63,64,66,67,68,69,71,72,73,74,75,77,78,79,80,81,82,83,84,85,86,87,87,88,89,90,91,91,92,93,93,94,95,95,96,96,97,97,97,98,98,98,99,99,99,99,100,100,100,100,100,100,100,100,100,100,100,99,99,99,99,98,98,98,97,97,97,96,96,95,95,94,93,93,92,91,91,90,89,88,87,87,86,85,84,83,82,81,80,79,78,77,75,74,73,72,71,69,68,67,66,64,63,62,60,59,57,56,54,53,52,50,48,47,45,44,42,41,39,37,36,34,33,31,29,28,26,24,22,21,19,17,16,14,12,10,9,7,5,3,2,0,-2,-3,-5,-7,-9,-10,-12,-14,-16,-17,-19,-21,-22,-24,-26,-28,-29,-31,-33,-34,-36,-37,-39,-41,-42,-44,-45,-47,-48,-50,-52,-53,-54,-56,-57,-59,-60,-62,-63,-64,-66,-67,-68,-69,-71,-72,-73,-74,-75,-77,-78,-79,-80,-81,-82,-83,-84,-85,-86,-87,-87,-88,-89,-90,-91,-91,-92,-93,-93,-94,-95,-95,-96,-96,-97,-97,-97,-98,-98,-98,-99,-99,-99,-99,-100,-100,-100,-100,-100,-100,-100,-100,-100,-100,-100,-99,-99,-99,-99,-98,-98,-98,-97,-97,-97,-96,-96,-95,-95,-94,-93,-93,-92,-91,-91,-90,-89,-88,-87,-87,-86,-85,-84,-83,-82,-81,-80,-79,-78,-77,-75,-74,-73,-72,-71,-69,-68,-67,-66,-64,-63,-62,-60,-59,-57,-56,-54,-53,-52,-50,-48,-47,-45,-44,-42,-41,-39,-37,-36,-34,-33,-31,-29,-28,-26,-24,-22,-21,-19,-17,-16,-14,-12,-10,-9,-7,-5,-3,-2,0};

void circle(uint8_t x,uint8_t y,uint8_t radius)
{
    int xp,yp;
    for(int i=0;i<360;i++)
    {
        xp = cosine[i]*radius/100+x;
        yp = sine[i]*radius/100+y;
        point(xp,yp);
    }
}
void line (int x1,int y1,int x2,int y2, int steps) { // draw a line between 2 points  
  for(int i=0;i<steps;i++) {
     
    point(x1+i*(x2-x1)/steps,y1+i*(y2-y1)/steps);
  }
}


void fullRect()
{
    for(int i = 0 ; i < 140;i++)
    {
        line(i,0,i,140,140);
    }
}

void vertlines(uint8_t step)
{
    for(int i = 0 ; i < 140;i+=step)
    {
       line(i,0,i,140,140);
    }
}

void horizonlines(uint8_t step)
{
    for(int i = 0 ; i < 140;i+=step)
    {
       line(0,i,140,i,140);
    }
}

void squares(uint8_t fill,uint8_t gap)
{
    uint8_t c = 0;
   for(int y = 1 ; y < 140;y++)
   {
        for(int x = 1 ; x < 140;x++)
        {
            point(x,y);
            if(x%fill ==0) 
            {
                x+=gap;
                if(c)
                {
                    point(200,200);
                }
                else
                {
                    point(0,0);
                }
                c=c^1;
            }
        }
        if(y%fill ==0) {y+=gap;point(200,0);}
   }
}
void cicles()
{
    circle(70,70,70);
    circle(70,70,50);
    circle(70,70,40);
    circle(70,70,30);
    circle(70,70,20);
    circle(70,70, 10);
}

void angledline(int angle, int8_t length)
{
    const int8_t radius = 70;
    const int8_t x = 70;
    const int8_t y = 70;
    int xp = cosine[angle]*radius/100+x;
    int yp = sine[angle]*radius/100+y;
    int xk = cosine[angle]*(radius-length)/100+x;
    int yk = sine[angle]*(radius-length)/100+y;
    line(xp,yp,xk,yk,length);
  
}

void clock_face()
{
    const int x = 70;
    const int y = 70;
    const int radius = 70;
    int xp,yp;
    for(int i=0;i<360;i++)
    {
        xp = cosine[i]*radius/100+x;
        yp = sine[i]*radius/100+y;
        point(xp,yp);
        if(i % 6 == 0) {angledline(i,10);}
        if(i % 60 == 0) {angledline(i,15);}
        if(i % 90 == 0) {angledline(i,20);}
    }
}

void minute_pointer(int minute)
{
    const int x = 70;
    const int y = 70;
    const int radius = 50;
    int angle = (minute*6+90)%360;
    int xp = -cosine[angle]*radius/100+x;
    int yp = sine[angle]*radius/100+y;
    line(x,y,xp,yp,radius);
    
}

void hours_pointer(int hour)
{
    const int x = 70;
    const int y = 70;
    const int radius = 40;
    int angle = (hour*30+90)%360;
    int xp = -cosine[angle]*radius/100+x;
    int yp = sine[angle]*radius/100+y;
    line(x,y,xp,yp,radius);
    
}

int seconds = 0;
int minutes = 51;
int hours = 8;
void timer_int(void) //executed every 2.5ms
{
    static int x = 0;
     Timer_1_ReadStatusRegister();
    if(x > 400)
    {
        seconds++;
        if(seconds >60){seconds = 0;minutes++;}
        x=0;
        if(minutes > 60){minutes = 0;hours++;}
        if(hours > 12) {hours =0;}
    }
    x++;
}
void seconds_circle(int second)
{
    const int x = 70;
    const int y = 70;
    const int radius = 70;
    int angle = (second*6+90)%360;
    int xp = -cosine[angle]*radius/100+x;
    int yp = sine[angle]*radius/100+y;
    circle(xp,yp,2);
    
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    VDAC8_1_Start();
    VDAC8_2_Start();
    Timer_1_Start();
    isr_1_Start();
    isr_1_SetVector(timer_int);
    
    for(;;)
    {
        //horizonlines(6);
        //squares(20,20);
        clock_face();
        seconds_circle(seconds);
        minute_pointer(minutes);
        hours_pointer(hours);
       // CyDelay(50);
       
    }
}

/* [] END OF FILE */
