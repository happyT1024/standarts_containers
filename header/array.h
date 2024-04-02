#pragma once

#include <iostream>
#include <type_traits>
#include <sstream>

template<typename T, std::size_t SIZE>
class array_traits {
public:
	using value_type = T[SIZE];
	using reference = T &;
	using size_type = std::size_t;
	using pointer = T *;

	static constexpr reference get_ref(const value_type &data, size_type index) noexcept {
		return const_cast<reference>(data[index]);
	}

	static constexpr pointer get_ptr(const value_type &data) noexcept {
		return const_cast<pointer>(data);
	}
};

template<typename T>
class array_traits<T, 0> {
public:
	class value_type {};

	using reference = T &;
	using size_type = std::size_t;
	using pointer = T *;

	static constexpr reference get_ref(const value_type &data, size_type index) noexcept {
		return const_cast<reference>(nullptr);
	}

	static constexpr pointer get_ptr(const value_type &data) noexcept {
		return nullptr;
	}
};

template<typename T, std::size_t SIZE>
class array {
public:
	using value_type = T;
	using size_type = std::size_t;
	using reference = value_type &;
	using const_reference = const value_type &;
	using pointer = value_type *;
	using const_pointer = const value_type *;
	using iterator = value_type *;
	using const_iterator = const value_type *;

private:
	using m_array_traits = array_traits<value_type, SIZE>;
	typename m_array_traits::value_type m_data;

public:
	array() = default;
	array(const array & other) = default;
	array& operator=(const_reference other) = default;
	array(array && other) = default;
	array& operator=(array && other) = default;

	reference operator[](size_type index) noexcept {
		return m_array_traits::get_ref(m_data, index);
	}

	const_reference operator[](size_type index) const noexcept {
		return m_array_traits::get_ref(m_data, index);
	}

	reference at(size_type index) {
		if (index < SIZE) {
			return this->operator[](index);
		}
		std::stringstream ss;
		ss << "m_size = " << SIZE << " index = " << index;
		throw std::out_of_range(ss.str());
	}

	const_reference at(size_type index) const {
		if (index < SIZE) {
			return this->operator[](index);
		}
		std::stringstream ss;
		ss << "m_size = " << SIZE << " index = " << index;
		throw std::out_of_range(ss.str());
	}

	constexpr size_type size() const noexcept {
		return SIZE;
	}

	constexpr bool empty() const noexcept {
		return size() == 0;
	}

	constexpr pointer data() noexcept {
		return m_array_traits::get_ptr(m_data);
	}

	constexpr const_pointer data() const noexcept {
		return m_array_traits::get_ptr(m_data);
	}

	constexpr iterator begin() noexcept {
		return iterator(data());
	}

	constexpr const_iterator begin() const noexcept {
		return const_iterator(data());
	}

	constexpr iterator end() noexcept {
		return iterator(data() + SIZE);
	}

	constexpr const_iterator end() const noexcept {
		return const_iterator(data() + SIZE);
	}

	constexpr reference front() noexcept {
		return *begin();
	}

	constexpr const_reference front() const noexcept {
		return m_array_traits::get_ref(m_data, 0);
	}

	constexpr reference back() noexcept {
		if (SIZE) {
			return *(end() - 1);
		}
		return *end();
	}

	constexpr const_reference back() const noexcept {
		if (SIZE) {
			return m_array_traits::get_ref(m_data, SIZE - 1);
		}
		return m_array_traits::get_ref(m_data, SIZE);
	}

	~array() = default;

private:

};