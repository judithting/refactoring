#include "gtest/gtest.h"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	::testing::GTEST_FLAG(color) = "yes";

	return RUN_ALL_TESTS();
}
