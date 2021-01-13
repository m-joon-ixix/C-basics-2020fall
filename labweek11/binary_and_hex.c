#include <stdio.h>

int main(){
	unsigned int n;
	printf("n: ");
	scanf("%d", &n);
	getchar(); // clear the buffer

	printf("<2진수>\n");
	for(int i = 31; i >= 0; i--){
		printf("%d", (n >> i) & 1);
		if(i % 8 == 0) printf(" ");
	}

	printf("\n\n");
	printf("<16진수>\n");

	for(int i = 7; i >= 0; i--){
		int four_bits = (n >> (4*i)) & 15;
		switch(four_bits){
			case 10:
				printf("a");
				break;
			case 11:
				printf("b");
				break;
			case 12:
				printf("c");
				break;
			case 13:
				printf("d");
				break;
			case 14:
				printf("e");
				break;
			case 15:
				printf("f");
				break;
			default:
				printf("%d", four_bits);
		}
	}

	printf("\n\n");
	return 0;
}