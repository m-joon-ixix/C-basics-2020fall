#include <stdio.h>

int main(){
	int a[3][3], b[3][3], c[3][3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			scanf("%d", &a[i][j]);
			getchar();
		}
	}

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			scanf("%d", &b[i][j]);
			getchar();
		}
	}

	// compute matrix c = a * b
	int entry;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			entry = 0;
			for(int k = 0; k < 3; k++){
				entry += a[i][k] * b[k][j];
			}
			c[i][j] = entry;
		}
	}

	// print the result of multiplication
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%5d ", c[i][j]);
		}
		printf("\n");
	}

	return 0;
}