#pragma once

#include <iostream>
#include <type_traits>
#include <sstream>

// TODO add allocator
// TODO add iterator
// TODO add move semantics
// TODO add guarantees
template <typename T>
class vector{
public:
	using size_type= size_t;

	using value_type= T;
private:
	T* m_data{nullptr};
	size_type m_size{0};
	size_type m_capacity{0};
	//Alloc m_alloc{};
public:
	vector() = default;

	vector(size_type size){
		m_size = size;
		m_capacity = size;
		m_data = allocate_data(m_capacity);
		construct_data(m_data, m_size);
	}

	vector(size_type size, const T& value)
	:vector(size)
	{
		for (size_type i = 0; i < size; ++i) {
			m_data[i] = value;
		}
	}

	void reserve(size_type new_capacity) noexcept {
		if (m_capacity < new_capacity) {
			T *new_data = allocate_data(new_capacity);
			std::copy(m_data, m_data + m_capacity, new_data);
			deallocate_data(m_data);
			m_data = new_data;
			m_capacity = new_capacity;
		}
	}

	void resize(size_type new_size) {
		if(new_size < m_size){
			// TODO удаляем???
		}else if(new_size == m_size){
			return;
		}else{
			if(m_capacity < new_size){
				reserve(new_size);
			}
			for(size_type i = m_size; i < new_size; ++i) {
				new(m_data + i) T();
			}
		}
		m_size = new_size;
	}

	[[nodiscard]] size_type size() const noexcept {
		return m_size;
	}

	[[nodiscard]] size_type capacity() const noexcept {
		return m_capacity;
	}

	~vector() {
		destroy_data(m_data,m_capacity);
		deallocate_data(m_data);
	}

private:
	T* allocate_data(size_type n) noexcept {
		return reinterpret_cast<T*>(new char[n * sizeof(T)]);
	}

	void construct_data(T* data, size_type n) noexcept {
		for (size_type i = 0; i < n; ++i) {
			new(data + i) T();
		}
	}

	void destroy_data(T* data, size_type n) noexcept {
		for (size_type i = 0; i < n; ++i) {
			data[i].~T();
		}
	}

	void deallocate_data(T* data) noexcept {
		delete[] data;
	}

};