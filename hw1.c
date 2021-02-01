#define _CRT_SECURE_NO_WARNINGS    
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int GetMultiplyValue(int num) {
	if (num == 0)
		return 1;
	else
		return GetMultiplyValue(num-1) * 9;
}

int main() {

    int result_num = 0;
    char * prev_num = malloc(sizeof(int)*9);

    fscanf(stdin,"%s",prev_num);    
	int current_num = 0;
    	for (int i = 0; i < strlen(prev_num); i++) {
		int positionNum = strlen(prev_num) - i - 1;
		current_num = prev_num[i] - '0';
		if (current_num < 4);
		else
			current_num--;
		result_num += current_num * GetMultiplyValue(positionNum);
	}
  //}
    fprintf(stdout,"%d",result_num);

    return 0;

}