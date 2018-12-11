#include "aiv_unit_test.h"
#include "ui.h"
#include "file_manipulator.h"
#include <stdlib.h>

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

TEST(file_open)
{
    char *filename = "FileTest.txt";
    char *filedata = malloc(sizeof(char) * 10);

    ASSERT_THAT(read_file(filename, filedata) == 0)
}

TEST(file_read)
{
    char *filename = "FileTest.txt";
    char *filedata = malloc(sizeof(char) * 10);

    read_file(filename, filedata);
    ASSERT_THAT(filedata == "prova")
}

int main(int argc, char **argv)
{
	RUN_TEST(file_not_exists);
	RUN_TEST(file_exists);
	RUN_TEST(file_open);
	RUN_TEST(file_read);

	PRINT_TEST_RESULTS();
	return 0;
}