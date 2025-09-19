#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "str_lib.h"

/* Creates a new pointer to string struct.
*/
string_t *str_new(char *str_in){
	string_t *str = (string_t *) malloc(sizeof(*str_in));
	assert(str != NULL);

	str->len = strlen(str_in);
	str->alloc = str->len * 2 + 1;
	str->data = (char *) malloc(str->alloc);
	assert(str->data != NULL);

	strcpy(str->data, str_in);
	return str;
}

/* Reallocates memory for a string.
*/
void str_realloc(string_t *str, char *str_in){
	int str_len = strlen(str_in);

	str->len = str->len + str_len;
	str->alloc = str->len * 2 + 1;
	str->data = (char *) realloc(str->data, str->alloc);
	assert(str->data != NULL);

	strcat(str->data, str_in);
}

/* Deletes a string. 
*/
void str_del(const string_t *str){
	free((void *)str->data);
	free((void *)str);
}

/* Prints the contents of the string struct.
*/
void str_print(const string_t *str){
	printf("string length=%d alloc=%d data=%s\n",
			str->len, str->alloc, str->data);
}

/* Appends a single char to the string.
*/
void str_append(string_t *str, char ch){
	if(str->len + 1 < str->alloc){
		str->len++;
		str->data[str->len - 1]= ch;
		str->data[str->len] = '\0';
	}
	else{
		str->alloc = (str->len + 1) * 2 + 1;
		str->data = (char *) realloc(str->data, str->alloc);
		assert(str->data != NULL);

		str->len++;
		str->data[str->len - 1] = ch;
		str->data[str->len] = '\0';
	}
}

/* Appends a string.
*/
void str_appends(string_t *str, char *str_in){
	int str_len = strlen(str_in);

	if((str->len + 1 + str_len) <= str->alloc){
		strcat(str->data, str_in);
		str->len = strlen(str->data);
	}
	else{
		str->alloc = (str->len + str_len + 1) * 2 + 1; 
		str->data = (char *) realloc(str->data, str->alloc);
		assert(str->data != NULL);
		strcat(str->data, str_in);
		str->len = strlen(str->data);
	}
}

/* Assigns a new string by overwriting previous string.
*/
void str_assign(string_t *str, char *str_in){
	int str_len = strlen(str_in);

	if( (str_len + 1) <= str->alloc){
		str->len = str_len;
		strcpy(str->data, str_in);
	}
	else{
		free(str->data);
		str->len = str_len;
		str->alloc = str->len * 2 + 1;
		str->data = (char *) malloc(str->alloc);
		assert(str->data != NULL);

		strcpy(str->data, str_in);
	}
}

/* Get the string length.
*/
int str_len(string_t *str){
	return str->len;
}