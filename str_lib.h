#ifndef STR_LIB_H
#define STR_LIB_H

// Structure type to hold metadata about the string and 
// a pointer to the string to be dynamically allocated.
// Move this struct do str_lib.c if making this data structure abstract.
// (note unit testing in main then would require this declaration as well 
// since struct members are accessed in the unit tests in main.c.)
struct string_t{
	int len;
	int alloc;
	char *data;
};

typedef struct string_t string_t;

string_t *str_new(char *str_in);
void str_realloc(string_t *str, char *str_in);
void str_del(const string_t *str);
void str_print(const string_t *str);
void str_append(string_t *str, char ch);
void str_appends(string_t *str, char *str_in);
void str_assign(string_t *str, char *str_in);
int str_len(string_t *str);

#endif