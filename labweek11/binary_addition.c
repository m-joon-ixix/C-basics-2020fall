#include <stdio.h>

int main(){
	int input1, input2;
	printf("Input 1 : ");
	scanf("%d", &input1);
	getchar();
	printf("Input 2 : ");
	scanf("%d", &input2);
	getchar();

	int decimal1 = 0, decimal2 = 0;

	int base = 1;
	while(input1 != 0){
		decimal1 += (input1 % 10) * base;
		base *= 2;
		input1 /= 10;
	}

	base = 1;
	while(input2 != 0){
		decimal2 += (input2 % 10) * base;
		base *= 2;
		input2 /= 10;
	}

	int sum = decimal1 + decimal2;
	printf("\nResult: ");

	int didFirstOneComeOut = 0, bit;
	for(int i = 31; i >= 0; i--){
		bit = (sum >> i) & 1;
		if(didFirstOneComeOut == 0 && bit == 1){
			didFirstOneComeOut = 1;
		}
		if(didFirstOneComeOut == 1){
			printf("%d", bit);
		}
	}

	printf(" (%d)\n\n", sum);
	return 0;
}