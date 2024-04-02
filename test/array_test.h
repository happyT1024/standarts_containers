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

using MyTypes = ::testing::Types<int, unsigned int, std::string>;

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

}
