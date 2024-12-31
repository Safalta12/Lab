//To read data from the standard input device and write it on the screen
#include<unistd.h>
int main(){
	char buff[20];
	read(0,buff,10); //0 is the file descriptor for standand input(keyboard),read 10 bytes
	write(1,buff,10); //1 is the file descriptor for standand output(screen),print 10 bytes
}