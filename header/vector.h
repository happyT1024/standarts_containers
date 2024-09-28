#pragma once

#include <iostream>
#include <type_traits>
#include <sstream>

// TODO add allocator
// TODO add iterator
// TODO add move semantics
template <typename T>
class vector{
public:
	using size_type= size_t;
private:
	T* m_data{nullptr};
	size_type m_size{0};
	size_type m_capacity{0};
	//Alloc m_alloc{};
public:
	void reserve(size_type new_capacity) noexcept {
		if (m_capacity < new_capacity) {
			T *new_data = reinterpret_cast<T *>(new char[new_capacity * sizeof(T)]);
			std::copy(m_data, m_data + m_capacity, new_data);
			for (size_type i = new_capacity; i < m_size; ++i) {
				m_data[i].~T();
			}
			delete[] m_data;
			m_data = new_data;
		}
	}

	void resize(size_type new_size) {
		if(new_size < m_size){
			// удаляем???
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
	}

	size_type size() const noexcept {
		return m_size;
	}

	size_type capacity() const noexcept {
		return m_capacity;
	}

private:

};