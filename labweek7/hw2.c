#include <stdio.h>

int count_sosu(int n);

int main(){
	int n = 0;

	scanf("%d", &n);

	printf("Count : %d\n", count_sosu(n));

	return 0;  
}

int count_sosu(int n){
	int count = 0; // number of primes until n
	for(int i = 2; i <= n; i++){
		// check if i is prime
		int is_i_prime = 1; // initial option
		for(int j = 2; j < i; j++){ // check if i % j == 0
			if(i % j == 0){
				is_i_prime = 0;
				break;
			}
		}
		if(is_i_prime){
			printf("%d is sosu\n", i);
			count++;
		}
	}

	return count;
}