#include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>


int main(int argc,char **argv) {

	unsigned char x;
	bool andf0;
	bool or0f;

	for(x=1; x>0; x++) {
		if (x & 0xf0) andf0=true;
		else andf0=false;

		if ((x | 0x0f)==0xff) or0f=true;
		else or0f=false;

		printf(" x=%d=0x%02x andf0=%s, orf0=%s\n",x,x,andf0?"true":"false",or0f?"true":"false");
	}

	return(0);

}
