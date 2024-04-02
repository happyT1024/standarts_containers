#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "array_test.h"

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	::testing::InitGoogleMock(&argc, argv);

	return RUN_ALL_TESTS();
}
