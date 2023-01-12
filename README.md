# Raspberry Pi SPI Interface 
-
## 2022/01/11 
* **WiringPi SPI**
    * Before you can use SPI interface, you may need to use the gpio utility to load the SPI drivers into the kernel
       
        <font color=#FF0000>*gpio load spi* </font> 
       
    * allocate a 100KB buffer. (You should rarely need this though, the default is more than enough for most appl1ications).

        <font color=#FF0000>*gpio load spi 100*</font> 

* **gpio load spi**
    * *#include <wiringPiSPI.h>*
    * *int wiringPiSPISetup (int channel, int speed);*
    * int wiringPiSPIDataRW (int channel, unsigned char *data, int len);
    * channel:  0 or 1
    * speed:  500,000 through 32,000,000 
  
## 2022/02/12
* Delay Function
  * *void delay (unsigned int howLong)*
    * delay ms
  * *void delayMicroseconds (unsigned int howLong)*
    * delay us
* Add W25Q32
   * Add W25Q32 API: W25Q32.cpp .h
   * Ads utility API: utility.cpp .h
