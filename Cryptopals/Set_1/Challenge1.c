/*
 * Challenge1.c
 * Convert hex values to base 64
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char get_base64(int i)
{
	char base64[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	return base64[i];
}

char* hex_2_base64(char* hexVal)
{
	int nums[3];
	int backup[3];
	int results[2];
	for (int i = 0; i < 3; i++)
	{
		if(hexVal[i] <= '9')	
		{
			nums[i] = hexVal[i] - '0';
			backup[i] = nums[i];
		}
		else
		{	
			nums[i] = hexVal[i] - 'a' + 10;
			backup[i] = nums[i];
		}
	}
	
	results[0] = (nums[0] << 2) | (nums[1] >> 2);
	results[1] = ((backup[1] << 4) & '0') | nums[2];
	printf("%s -> %c%c\n", hexVal, get_base64(results[0]), get_base64(results[1]));
	char *newtext = malloc(sizeof(char)*2);
	newtext[0] = get_base64(results[0]);
	newtext[1] = get_base64(results[1]);
	return newtext;
}

int main()
{
	char *base64string = malloc(sizeof(char)*100);
	char* hexstring = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	printf("The string of hex characters is: %s\n", hexstring);
	for(int i = 0; i < strlen(hexstring); i+=3)
	{
		char *temp = malloc(sizeof(char)*3);
		strncpy(temp, &hexstring[i], 1);
		strncat(temp, &hexstring[i+1], 1);
		strncat(temp, &hexstring[i+2], 1);
		strcat(base64string, hex_2_base64(temp));
	}
	printf("Base64 string is: %s\n", base64string);
	free(base64string);
	return 0;
}
