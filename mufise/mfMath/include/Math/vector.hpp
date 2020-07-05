#ifndef _MF_VECTOR_HPP
#define _MF_VECTOR_HPP

#include <assert.h>

namespace mufise
{
	template<unsigned short sz, typename T>
	class vector
	{
		typedef vector<sz, T> _type;

	public:
		vector();
		vector(const _type & other);
		~vector() = default;

	private:
		T m_data[sz];

	public:
		inline _type operator+(const _type& other)
		{
			_type tmp;

			for (short i = 0; i < sz; i++)
			{
				tmp.m_data[i] = m_data[i] + other.m_data[i];
			}

			return tmp;
		};

		_type operator-(const _type& other)
		{
			_type tmp;

			for (short i = 0; i < sz; i++)
			{
				tmp.m_data[i] = m_data[i] - other.m_data[i];
			}

			return tmp;
		};

		_type& operator=(const _type& other)
		{
			for (short i = 0; i < sz; i++)
			{
				m_data[i] = other.m_data[i];
			}

			return *this;
		};

		T & operator[](int id)
		{
			assert(id < sz);
			return m_data[id];
		}
	};

	template<unsigned short sz, typename T>
	inline vector<sz, T>::vector()
	{
		for (short i = 0; i < sz; i++)
		{
			m_data[i] = T(0);
		}
	}

	template<unsigned short sz, typename T>
	inline vector<sz, T>::vector(const _type& other)
	{
		operator=(other);
	}
}

#endif // !_MF_VECTOR_HPP