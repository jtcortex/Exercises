/*
 * Challenge2.c
 * XOR two equal-length buffers
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

unsigned int char_parse(char c)
{
	if('0' <= c && c <= '9') return c - '0';
	if('a' <= c && c <= 'f') return 10 + c - 'a';
	if('A' <= c && c <= 'F') return 10 + c - 'A';
}

char get_char(int c)
{
	char hexArray[16] = "0123456789abcdef";
	return hexArray[c];
}

char* hex_string_xor(char* hexVal, char* xorVal)
{
	assert(strlen(hexVal) == strlen(xorVal));
	int d;
	char *temp;
	char *newstring = malloc(sizeof(char)+strlen(hexVal));
	for(int i = 0; i < strlen(hexVal); i++)
	{
		d = char_parse(hexVal[i]) ^ char_parse(xorVal[i]);
		temp = get_char(d);
		strcat(newstring, &temp);
	}
	return newstring;
}

int main()
{
	char* hexstring = "1c0111001f010100061a024b53535009181c";
	char* xorValue = "686974207468652062756c6c277320657965";
	char* result = hex_string_xor(hexstring, xorValue);
	printf("Hex string:  %s\n", hexstring);
	printf("XORd with:   %s\n", xorValue);
	printf("Result:      %s\n", result);
	return 0;
}
