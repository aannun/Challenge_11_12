#include "aiv_unit_test.h"
#include "tile.h"

TEST(tile_init)
{
    tile_t *tile;
    init_tile(tile, 0, 1);

    ASSERT_THAT(tile->x == 0);
    ASSERT_THAT(tile->y == 1);
}
int main(int argc, char **argv)
{
	RUN_TEST(tile_init);

	PRINT_TEST_RESULTS();
	return 0;
}