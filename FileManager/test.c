#include "aiv_unit_test.h"
#include "ui.h"
#include "file_manipulator.h"
#include <stdlib.h>
#include <string.h>

TEST(file_not_exists)
{
    FILE *file;
    char *filename = "file_non_esistente";

    ASSERT_THAT(exists(&file, filename) == 1)
}

TEST(file_exists)
{
    FILE *file;
    char *filename = "FileTest.txt";

    ASSERT_THAT(exists(&file, filename) == 0)
}

TEST(file_length)
{
    FILE *stream;
    char *filename = "FileTest.txt";

    exists(&stream, filename);
    
    int size = get_file_length(stream);
    
    ASSERT_THAT(size == 5)
}

TEST(file_read)
{
    FILE *stream;
    char *filename = "FileTest.txt";

    exists(&stream, filename);

    int size = get_file_length(stream);
    char *filedata = malloc(sizeof(char) * size);

    read_file(stream, filename, filedata, size);
    ASSERT_THAT(_strcmpi(filedata, "prova") == 0)
}

int main(int argc, char **argv)
{
	RUN_TEST(file_not_exists);
	RUN_TEST(file_exists);
	RUN_TEST(file_length);
	RUN_TEST(file_read);

	PRINT_TEST_RESULTS();
	return 0;
}