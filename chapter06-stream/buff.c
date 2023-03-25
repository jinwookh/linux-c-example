#include <stdio.h>



int main(int argc, char *argv[]) {

	char buf[10];

	buf[0] = 'a';
	buf[1] = 'b';
	buf[2] = 'b';

	printf("hello!");

	fgets(buf, 15, stdin);

	fputs(buf, stdout);

	

}
