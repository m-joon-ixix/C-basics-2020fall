#include <stdio.h>
#include <string.h>

void swap(char** , char**);
void bubble_sort(char* words[10]);

int main(void) {
	char* words[10] = {"computer", "windows", "window", "linux", "apple", "banana", "time", "help", "game", "money"};
	bubble_sort(words);
	for(int i = 0; i < 10; i++){
		printf("%s\n", words[i]);
	}
}

void swap(char** a, char** b){
	char* tmp = *a;
	*a = *b;
	*b = tmp;	
}

void bubble_sort(char* words[10]){
	// start from beginning, send the big words to right side
	for(int i = 10; i > 1; i--){ // sort the first i elements
		for(int j = 0; j < i - 1; j++){ // compare element # j, j+1
			if(strlen(words[j]) > strlen(words[j + 1])){
				swap(&words[j], &words[j + 1]);
			} else if(strlen(words[j]) == strlen(words[j + 1])){
				if(strcmp(words[j], words[j + 1]) > 0){
					swap(&words[j], &words[j + 1]);
				}
			}
		}
	}
}
