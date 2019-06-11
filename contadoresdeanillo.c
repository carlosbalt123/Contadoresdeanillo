#include<18F4620.h>
# include<stdio.h>
# include<stdlib.h>
#fuses XT, NOMCLR
#USE DELAY (clock = 16000000 )
int contador1=0;
int contador2=0;
int contador3=0;
int contador4=0;
int16 contadoranillo1=1;
int16 contadoranillo2=1;
int16 contadoranillo3=1;
int16 contadoranillo4=1;
#INT_TIMER0 
void TIMER0(){
contador1++;
contador2++;
contador3++;
contador4++;
set_timer0(15536);
}
void main(void)
{
 setup_oscillator(OSC_16MHZ);
   set_tris_a(0x0);
   set_tris_b(0x0);
   set_tris_c(0x0);
   set_tris_d(0x0);
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_8 );
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   set_timer0(15536); 
   while(TRUE){
      if(contador1 == 1){
      contadoranillo1*=2;   
      contador1 = 0;
       if(contador1 ==256){
      contadoranillo1=1;
     }
     output_b(contadoranillo1);
     //--------------------------------
      }
      if(contador2 == 4){
      contadoranillo2*=2;   
      contador2 = 0;
       if(contador2 ==256){
       contadoranillo2=1;
     }
     output_a(contadoranillo2);
     //--------------------------------------
      }
     if(contador3 == 7){
       contadoranillo3*=2;   
       contador3 = 0;
       if(contador3 ==256){
       contadoranillo3=1;
     }
     output_c(contadoranillo3);
     //-----------------------------
      }
     if(contador4 == 10){
       contadoranillo4*=2;   
       contador4 = 0;
       if(contador4 ==256){
       contadoranillo4=1;
     }
     output_d(contadoranillo4);
      }
     
   }
}


