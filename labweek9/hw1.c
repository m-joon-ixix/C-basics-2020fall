#include <stdio.h>
#include <string.h>

int main(){
	char str[101];
	printf("input string: ");
	scanf("%s", str);
	int l = strlen(str); // length of string
	int is_symmetric = 1;
	// need to compare l/2 times
	for(int i = 0; i < l/2; i++){
		// compare str[i] and str[l - 1 - i]
		if(str[i] != str[l - 1 - i]){
			is_symmetric = 0;
			break;
		}
	}

	printf("%s is ", str);
	if(is_symmetric){
		printf("a symmetrical word\n");
	} else {
		printf("not a symmetrical word\n");
	}

	return 0;
}