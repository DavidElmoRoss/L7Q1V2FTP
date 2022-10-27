/*
    Currently this program writes HALT on the 4 digit display then
    scrolls   thE SPrE   . Add to the message so that it scrolls   thE SprEAd
    instead of thE SPrE. Then also adjust the range of the inner 
    for loop     to adjust for the extra 2 characters you have put in your
    character array.            .            
*/

// Include Section
#include "mbed.h"                   
#include "DigitDisplay.h"          

// Hardware definitions
DigitDisplay segment(D2,D3);        

// Global variables
unsigned char mess[]= {0x00,0x00,0x00,0x00,          
                       0x78,0x74,0x79,0x00,0x6D,0x73,0x50,0x79,
                       0x00,0x00,0x00,0x00};          
unsigned short i;

int main(void)
{
    segment.clear();                
    segment.setColon(0);            
    segment.setBrightness(4);       
 
    for(;;)                         
    {                                   
        segment.writeRaw(0,0x74);   
        segment.writeRaw(1,0x77);
        segment.writeRaw(2,0x38);
        segment.writeRaw(3,0x78);  
        wait_ms(500);
      for(i=0;i<=12;++i)             
      {
         segment.writeRaw(&mess[i]); 
         wait_ms(250);
      }
      wait_ms(1000);                
    }
                          
}