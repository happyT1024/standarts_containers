#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector.h>

TEST(VectorTest, DefaultConstructor) {
	vector<int> v;
	EXPECT_EQ(0, v.size());
}

TEST(VectorTest, SizeConstructor) {
	int size = 5; // TODO parametrize test
	vector<int> v(size);
	EXPECT_EQ(size, v.size());
}

TEST(VectorTest, SizeDefaultValueConstructor) {
	int size = 5; // TODO parametrize test
	int value = 0; // TODO parametrize test
	vector<int> v(size, value);
	EXPECT_EQ(size, v.size());
}
