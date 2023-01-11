# Raspberry Pi SPI Interface 
-
## 2022/01/11 
* WiringPi SPI
    * Before you can use SPI interface, you may need to use the gpio utility to load the SPI drivers into the kernel
    
        gpio load spi

    * allocate a 100KB buffer. (You should rarely need this though, the default is more than enough for most applications).

        gpio load spi 100

* gpio load spi
    * #include <wiringPiSPI.h>
    * int wiringPiSPISetup (int channel, int speed) ;
    * int wiringPiSPIDataRW (int channel, unsigned char *data, int len) ;
    * channel:  0 or 1
    * speed:  500,000 through 32,000,000 
