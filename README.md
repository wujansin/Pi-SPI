## Raspberry Pi SPI Interface 
### Log 2022/01/11
* SPI 
    * Using WiringPi Lib
        * #include <wiringPiSPI.h>
        *   int wiringPiSPISetup (int channel, int speed) ;
        *   int wiringPiSPIDataRW (int channel, unsigned char *data, int len) ;
        * channel : 0 or 1
        * Speed: 500,000 through 32,000,000
