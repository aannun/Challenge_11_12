#include <stdio.h>

int exists(FILE **file, char *filename);

int read_file(char *filename, char *filedata, int size);

int get_file_length(FILE *stream);