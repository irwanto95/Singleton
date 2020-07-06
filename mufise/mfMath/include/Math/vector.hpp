#ifndef _MF_VECTOR_HPP
#define _MF_VECTOR_HPP

#include <crtdbg.h>

namespace mufise
{
	namespace math
	{
		template<typename T>
		class vector
		{
			typedef vector<T> _type;

		public:
			vector(T _x = 0, T _y = 0, T _z = 0);
			vector(const _type& other);
			~vector() = default;

			/*
			*/
			T dot(const _type& other);
			
			/*
			*/
			_type cross(const _type& other);

		public:
			T x, y, z;

		public:
			inline _type operator+(const _type& other)
			{
				_type tmp;
				tmp.x = x + other.x;
				tmp.y = y + other.y;
				tmp.z = z + other.z;

				return tmp;
			};

			_type operator-(const _type& other)
			{
				_type tmp;
				tmp.x = x - other.x;
				tmp.y = y - other.y;
				tmp.z = z - other.z;

				return tmp;
			};

			_type& operator=(const _type& other)
			{
				x = other.x;
				y = other.y;
				z = other.z;

				return *this;
			};
		};

		template<typename T>
		inline vector<T>::vector(T _x, T _y, T _z)
			: x(_x)
			, y(_y)
			, z(_z)
		{
		}

		template<typename T>
		inline vector<T>::vector(const _type& other)
		{
			operator=(other);
		}

		template<typename T>
		inline T vector<T>::dot(const _type& other)
		{
			return x * other.x + y * other.y + z * other.z;
		}

		template<typename T>
		inline vector<T> vector<T>::cross(const _type& other)
		{
			_ASSERT_EXPR(0, "cross not implemented yet");
			return _type();
		}


		/*
		**	
		*/
		typedef vector<short>	vecs;
		typedef vector<int>		veci;
		typedef vector<float>	vecf;
		typedef vector<double>	vecd;
	} // math
} // mufise

#endif // !_MF_VECTOR_HPP