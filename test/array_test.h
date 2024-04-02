#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "array.h"
#include <array>

TEST(array, getRef) {
	int value = 123;
	array<int, 1> arr{};
	ASSERT_NO_THROW(arr.at(0));
	arr[0] = value;
	ASSERT_EQ(arr[0], value);
	ASSERT_THROW(arr.at(1), std::logic_error);
}

TEST(array, getConstRef) {
	const array<int, 1> arr{};
	ASSERT_NO_THROW(arr.at(0));
	ASSERT_THROW(arr.at(1), std::logic_error);
}


