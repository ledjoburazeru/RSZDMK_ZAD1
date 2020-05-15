#include <LiquidCrystal.h>
#include <util/delay.h>

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

byte srce [8] = {
B00000 ,
B00100 ,
B01010 ,
B10001 ,
B01010 ,
B00100 ,
B00000 ,
};

byte list [8] = {
B00100 ,
B01110 ,
B11111 ,
B11111 ,
B01110 ,
B01110 ,
B01110 ,
};

byte detelina [8] = {
B00000 ,
B01111 ,
B01110 ,
B11111 ,
B11111 ,
B01110 ,
B00100 ,
};

byte kocka [8] = {
B00000 ,
B00100 ,
B01010 ,
B10001 ,
B01010 ,
B00100 ,
B00000 ,
};


randomSeed ( analogRead (0) ) ;
char ocitaj_taster()
{
  char taster = 0;
  unsigned char row;
  MCUCR &= ~0x10;
  PORTD = 0x0f; 
  for(row = 0x80; row != 0x08; row >>= 1)
  {
    DDRD = row;
	_delay_ms(2);
    switch(row | ((~PIND) & 0x0f))
    {
      //case 0x88:
      	//taster = '1'; break;
      case 0x84:
      	taster = '2'; break;
      //case 0x82:
      //	taster = '3'; break;
     // case 0x81:
      //	taster = 'A'; break;
	  case 0x48:
      	taster = '4'; break;
      case 0x44:
      	taster = '5'; break;
      case 0x42:
      	taster = '6'; break;
     // case 0x41:
      //	taster = 'B'; break;
	 // case 0x28:
     // 	taster = '7'; break;
      case 0x24:
      	taster = '8'; break;
      //case 0x22:
      //	taster = '9'; break;
     // case 0x21:
      //	taster = 'C'; break;
	  case 0x18:
      	taster = '*'; break;
    //  case 0x14:
      //	taster = '0'; break;
     // case 0x12:
      //	taster = '#'; break;
     // case 0x11:
      //	taster = 'D'; break;
    }
  }
  return taster;
}
int main()
{
  	lcd.begin(16, 2);
  
    lcd.createChar (0 , srce ) ; 
  
  	lcd.createChar (1 , detelina ) ;
  
  	lcd.createChar (2 , list ) ;
  
  	lcd.createChar (3 , kocka ) ;
  
  	unsigned char pritisnut=0,pusten=0;
  
    lcd.setCursor(0,0);
  
    lcd.print("Pritisni *");
  
    _delay_ms(500);
  
	while(1)
    { 
	  char taster = ocitaj_taster();
      if (taster =='*' && pusten==0)   
        
        {
              lcd.clear();
        
              lcd.print("----");
        
        lcd.write( byte (0) ) ;
        
         	  _delay_ms(200);     
        
       		  pritisnut=taster;
    	}
        if(pritisnut==taster)
        	pusten=1;
          else
            pusten=0;     
         }
  	return 0;
}