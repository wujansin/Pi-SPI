//********************************
// wiringPi Lib Function Test
//********************************
#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>


using namespace std;

#define LED_RED			5
#define LED_YEL 		6
#define LED_GRN			1
#define LED_ON(n)		digitalWrite(LED_##n, HIGH)
#define LED_OFF(n)		digitalWrite(LED_##n, LOW)

#define BTN_1			4
#define BTN_ON			HIGH
#define BTN_OFF			LOW
#define BTN_READ(n)		digitalRead(BTN_##n)
 
#define SPI_SPEED		1000000 //(1M)   Max: 32,000,000 (32M)
#define SPI_CH0			0
#define SPI_CH1			1

pid_t child_pid = -1;

void kill_child(int sig)
{
    kill(child_pid, SIGKILL);
}

void showCommand(void)
{
	cout <<"\n\n\n";
	cout <<" Winbond SE command\n";
	cout <<"-------------------------\n";
	cout <<"(0):  	\n";
	cout <<"(1):  	\n";
	cout <<"(2):   	\n";
	cout <<"(3):   	\n";
	cout <<"(4):   	\n";
	cout <<"(a):  	\n";
	cout <<"(g): 	\n";
	cout <<"(j): 	\n";
	cout <<"(k):  	\n";
	cout <<"(l):  	list menu\n";
	cout <<"(Q):  	exit program \n";
}

int main (void)
{
	int btn_val;
	struct timeval tv;
	int wstatus, status;
	
	printf("Build Time  :: %s, %s \n", __TIME__, __DATE__ );
	
	/* Set up GPIO */
	wiringPiSetup() ;
	pinMode(BTN_1, INPUT);
	pinMode(LED_RED, OUTPUT);
	pinMode(LED_YEL, OUTPUT);
	pinMode(LED_GRN, OUTPUT);

	child_pid = fork();
	if(child_pid <0)
	{
		perror("fork error");
		exit(0);
	}
	else if(child_pid == 0)
	{
		/* child process */
		//cout << "In Child process, pid =" <<getpid()<<endl;
		
		for(;;)
		{			
			digitalWrite (LED_YEL, HIGH);
			delay(500);
			digitalWrite (LED_YEL, LOW);
			delay(500);		
		}
	}
	else
	{
		/* parent process */
		int ch;
		int spi_fd;
		//cout << "In Parent process, pid =" <<getpid() <<endl;		
		showCommand();
		for (;;)
		{
			ch = getchar();
			switch(ch)
			{
				case '0':
					printf("Press 0\n");
					LED_ON(RED);
					break;
				case '1':
					LED_OFF(RED);
					printf("Press 1\n");
					break;
				case '2':
					printf("Press 2: SPI CH0 Init\n");
					spi_fd = wiringPiSPISetup (SPI_CH0, SPI_SPEED);
					if(spi_fd == -1)
						cout <<"SPI Setup Channel:"<< SPI_CH0 <<" error"<<endl;
					else
						cout <<"SPI Setup Channel:"<< SPI_CH0 <<" OK"<<endl;	
					break;

				case '3':
					printf("Press 3: SPI Send Data\n");
					{
						unsigned char data[] = { 0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99 };
						wiringPiSPIDataRW(SPI_CH0, data, sizeof(data));
					}
					break;		

				case '4':
					printf("Press 4: Write Data to W25Q32\n");
					
					break;

				case '5':
					printf("Press 5: Read Data from W25Q32\n");
					
					break;

				case 'l':

				case 'L':
					showCommand();
					break;	
				case 'q':
				case 'Q':
					break;	
				default:
					break;		
			}
			if(ch == 'Q' || ch == 'q')
				break;
		}
	}

	printf("END program\n");
	int ret = kill(child_pid, SIGKILL);
    if (ret == -1) 
	{
        perror("kill");
        exit(EXIT_FAILURE);
    }

	if (waitpid(child_pid, &wstatus, WUNTRACED | WCONTINUED) == -1) 
	{
    	perror("waitpid");
        exit(EXIT_FAILURE);
    }	
	
	exit(EXIT_SUCCESS);
}
