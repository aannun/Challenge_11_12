#include "file_manipulator.h"
#include <stdlib.h>

int exists(FILE **stream, char *filename)
{
    if (fopen_s(stream, filename, "r") == 0)
        return 0;
    return 1;
}

int read_file(FILE *stream, char *filename, char *filedata, int size)
{
        fgets(filedata, size + 1, stream);

        fclose(stream);
        return 0;
}

int get_file_length(FILE *stream)
{
    fseek(stream, 0, SEEK_END);
    int size = ftell(stream);
    fseek(stream, 0, SEEK_SET);
    return size;
}
