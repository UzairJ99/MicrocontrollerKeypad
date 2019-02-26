#include <hidef.h> 
#include "derivative.h" 
  void setClk(void);
  void delay1ms(unsigned int multiple);

  void main(void) {

   setClk();
   DDRJ = 0x01;
   PTJ = 0x00; 
   DDR1AD = 0xF0; 
   ATDDIEN = 0x000F; 
   PER1AD = 0x0F;
   DDRT = 0xF;
   DDR1AD = 0b11110000;


   /* MILESTONE I CODE GOES INSIDE THE FOR LOOP BELOW*/
   for(;;) {
   
     if(PT1AD == 0b00001110){
       PTJ = 0x01;
       delay1ms(100);
     }

     //ROW 0
     PT1AD = 0b11101111;
     delay1ms(1);

     if(PTI1AD == 0b11111110){
       PTT = 0b0001;
       PTJ = 0b00000001;
       delay1ms(100);
       PTT = 0b0000;
       PTJ = 0b00000000;
     }

     if(PTI1AD == 0b11111101){
       PTT = 0b0010;
       PTJ = 0b00000001; 
       delay1ms(100);
       PTT = 0b0000;
       PTJ = 0b00000000;
     }

     if(PTI1AD == 0b11111011){
       PTT = 0b0011;
       PTJ = 0b00000001;
       delay1ms(100);
       PTT = 0b0000;
       PTJ = 0b00000000;
     }

     if(PTI1AD == 0b11110111){
       PTT = 0b1010;
       PTJ = 0b00000001;
       delay1ms(100);
       PTT = 0b0000;
       PTJ = 0b00000000;
     }

     //ROW 1
     PT1AD = 0b11011111;
     delay1ms(1);

     if(PTI1AD == 0b11111110){
       PTT = 0b0100;
       PTJ = 0b00000001;
       delay1ms(100);
       PTT = 0b0000;
       PTJ = 0b00000000;
     }

     if(PTI1AD == 0b11111101){
       PTT = 0b0101;
       PTJ = 0b00000001;
       delay1ms(100);
       PTT = 0b0000;
       PTJ = 0b00000000;
     }

     if(PTI1AD == 0b11111011){
       PTT = 0b0110;
       PTJ = 0b00000001;
       delay1ms(100);
       PTT = 0b0000;
       PTJ = 0b00000000;
     }

     if(PTI1AD == 0b11110111){
       PTT = 0b1011;
       PTJ = 0b00000001;
       delay1ms(100);
       PTT = 0b0000;
       PTJ = 0b00000000;
     } 

     //ROW 2
     PT1AD = 0b10111111;
     delay1ms(1);

     if(PTI1AD == 0b11111110){
       PTT = 0b0111;
       PTJ = 0b00000001;
       delay1ms(100);
       PTT = 0b0000;
       PTJ = 0b00000000;
     }

     if(PTI1AD == 0b11111101){
       PTT = 0b1000;
       PTJ = 0b00000001;
       delay1ms(100);
       PTT = 0b0000;
       PTJ = 0b00000000;
     }

     if(PTI1AD == 0b11111011){
       PTT = 0b1001;
       PTJ = 0b00000001;
       delay1ms(100);
       PTT = 0b0000;
       PTJ = 0b00000000;
     }

     if(PTI1AD == 0b11110111){
       PTT = 0b1100;
       PTJ = 0b00000001;
       delay1ms(100);
       PTT = 0b0000;
       PTJ = 0b00000000;
     }

     //ROW 3
     PT1AD = 0b01111111;
     delay1ms(1);

     if(PTI1AD == 0b11111110){
       PTT = 0b1110;
       PTJ = 0b00000001;
       delay1ms(100);
       PTT = 0b0000;
       PTJ = 0b00000000;
     }

     if(PTI1AD == 0b11111101){
       PTT = 0b0000;
       PTJ = 0b00000001;
       delay1ms(100);
       PTT = 0b0000;
       PTJ = 0b00000000; 
     }

     if(PTI1AD == 0b11111011){
       PTT = 0b1111;
       PTJ = 0b00000001;
       delay1ms(100);
       PTT = 0b0000;
       PTJ = 0b00000000;
     }

     if(PTI1AD == 0b11110111){
       PTT = 0b1101;
       PTJ = 0b00000001;
       delay1ms(100);
       PTT = 0b0000;
       PTJ = 0b00000000;
     }
    } 
           
  }
  void delay1ms(unsigned int multiple){
     unsigned int i; 
     TSCR1 = 0x80; 
     TSCR2 = 0x01; 
     
     for(i=0;i<multiple;i++) {
       TFLG2 = 0x80; //clear the TOF flag
       while ((TFLG2 &0x80)==0);
     }
  } 
  
  #define initSYNR 0x02 
  #define VCOFRQ 0x40 
  #define initREFDV 0x00 
  #define REFFRQ 0x80 
  void setClk(void){
   CPMUPROT = 0;
   CPMUCLKS = 1;
   CPMUSYNR=initSYNR+VCOFRQ; 
   CPMUREFDIV = initREFDV+REFFRQ;
   CPMUPOSTDIV=0x00;
   CPMUOSC = 0xC0; 
   while (CPMUFLG_LOCK == 0) {} 
   CPMUPLL = CPMUCLKS; 
  }
