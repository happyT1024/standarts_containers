#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <array.h>
#include <array>

template<typename T>
class array_test
		: public testing::Test {
public:
	using value_type = T;
	static constexpr std::size_t m_size = 10;

	array<value_type, m_size> m_array{};

	void SetUp() override {
		m_array = array<T, m_size>{};
	}

	void TearDown() override {}
};

using MyTypes = ::testing::Types<int, unsigned int>;

TYPED_TEST_SUITE(array_test, MyTypes);

TYPED_TEST(array_test, getRef) {
	typename TestFixture::value_type value = {};
	ASSERT_NO_THROW(this->m_array.at(0));
	this->m_array[0] = value;
	ASSERT_EQ(this->m_array[0], value);
	ASSERT_THROW(this->m_array.at(this->m_array.size()), std::logic_error);
}

TYPED_TEST(array_test, getConstRef) {
	ASSERT_NO_THROW(this->m_array.at(0));
	ASSERT_THROW(this->m_array.at(this->m_array.size()), std::logic_error);
}

TYPED_TEST(array_test, iterators) {
	int i = 1;
	for(auto & elem: this->m_array){
		elem=i;
		i++;
	}
	ASSERT_EQ(this->m_array.front(), 1);
	ASSERT_EQ(this->m_array.back(), this->m_size);
}

TYPED_TEST(array_test, copyArray) {
	int i = 1;
	for(auto & elem: this->m_array){
		elem=i;
		i++;
	}
	auto copy_array = this->m_array;
	for(i = 0;i<copy_array.size();++i){
		ASSERT_EQ(copy_array[i], this->m_array[i]);
	}
}

TEST(array, emptyArray) {
	array<int, 0> arr{};
	ASSERT_THROW(arr.at(0), std::logic_error);
	ASSERT_EQ(arr.data(), nullptr);
	ASSERT_EQ(arr.begin(), arr.end());
}
