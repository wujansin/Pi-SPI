#include <string.h>
#include <stdio.h>
#include <stdint.h>

/* unsigned char *str2hex(unsigned char *in, int hexlen, unsigned char *out, int *outlen)
 Function:	change the string value into HEX
 Input:		in -> hex 
            hexlen -> hex code length
 Output:	out -> the result string  (0xAB -->'AB')
            outlen -> length (in bytes ) of string.
 Return:	the pointer to the resulting HEX string.
-----------------------------------------------------------------------*/
unsigned char *hex2str(unsigned char  *in, int hexlen, unsigned char  *out, int *strlen)
{
	int i;
	char str[3];
	unsigned char  inhex;
	for(i=0; i<hexlen;i++)
	{
		inhex = in[i];
		sprintf(str, "%02x", inhex);
		out[i*2]  = (unsigned char)str[0];
		out[i*2+1]= (unsigned char)str[1];
	}	
	*strlen = hexlen*2;
	return out;
}


/*----------------------------------------------------------------------
unsigned char *str2hex(unsigned char *in, int hexlen, unsigned char *out, int *outlen)
 Function:	change the string value into HEX
 Input:		in -> incoming string, it should contain all numeric digits or 'A' - 'F'.
            hexlen -> expected  in string len, if we expect 00 00 10 00
                      8 digits (4 bytes), this value should be 8. this
                      value must longer than the strlen of in buffer.
 Output:	out -> the result HEX string
            outlen -> length (in bytes ) of HEX string.
 Return:	the pointer to the resulting HEX string.
-----------------------------------------------------------------------*/
unsigned char  *str2hex(unsigned char  *in, int hexlen, unsigned char  *out, int *outlen)
{
	int iData;
	int iData1;
	int iData2;
	int j = 0;

	char cData[2];
	memset(out, 0, hexlen/2);
        
	for(int i = 0;i<hexlen;i+=2)
	{
		memset(cData,0,sizeof(cData));
		
		cData[0] = in[i];
		
		switch (cData[0])
		{
			case 'a':
			case 'A':
				iData1 = 10;
				break;
			case 'b':
			case 'B':
				iData1 = 11;
				break;
			case 'c':
			case 'C':
				iData1 = 12;
				break;
			case 'd':
			case 'D':
				iData1 = 13;
				break;
			case 'e':
			case 'E':
				iData1 = 14;
				break;
			case 'f':
			case 'F':
				iData1 = 15;
				break;
			default:
				iData1 = cData[0]-0x30;	//atoi(cData));
				break;
		}

		memset(cData,0,sizeof(cData));

		cData[0] = in[i+1];
		switch (cData[0])
		{
			case 'a':
			case 'A':
				iData2 = 10;
				break;
			case 'b':
			case 'B':
				iData2 = 11;
				break;
			case 'c':
			case 'C':
				iData2 = 12;
				break;
			case 'd':
			case 'D':
				iData2 = 13;
				break;
			case 'e':
			case 'E':
				iData2 = 14;
				break;
			case 'f':
			case 'F':
				iData2 = 15;
				break;
			default:
				iData2 = cData[0]-0x30; //atoi(cData));
				break;
		}

		iData = iData1 * 16 + iData2;
 
		out[j] = iData;

		j++;
	}
	
	*outlen = (hexlen/2);
	return out;
}

void printBinary(unsigned char *input, int inLength)
{
	int i;
	for (i = 0; i < inLength; i++)
	{
		printf("%02X ", input[i]);
		if ((i + 1) % 16 == 0)
			printf("\n");
	}
	printf("\n");
}


void hex_dump(uint8_t *dt, uint32_t n) 
{
  uint16_t clm = 0;
  uint8_t data;
  uint8_t sum;
  uint8_t vsum[16];
  uint8_t total =0;
  uint32_t saddr =0;
  uint32_t eaddr =n-1;
  
  printf("----------------------------------------------------------\n");
  uint16_t i;
  for (i=0;i<16;i++) vsum[i]=0;  
  uint32_t addr;
  for (addr = saddr; addr <= eaddr; addr++) {
    data = dt[addr];
    if (clm == 0) {
      sum =0;
      printf("%05x: ",addr);
    }

    sum+=data;
    vsum[addr % 16]+=data;
    
    printf("%02x ",data);
    clm++;
    if (clm == 16) {
      printf("|%02x \n",sum);
      clm = 0;
    }
  }
  printf("----------------------------------------------------------\n");
  printf("       ");
  for (i=0; i<16;i++) {
    total+=vsum[i];
    printf("%02x ",vsum[i]);
  }
  printf("|%02x \n\n",total);
}