#ifndef _MF_VECTOR_HPP
#define _MF_VECTOR_HPP

#include <limits>
#include "mufise/mfUtils/Core/Assert.h"

namespace mufise
{
	namespace math
	{
		template<typename T>
		class vector2
		{
			typedef vector2<T> _type;

		public:
			vector2(T _x = 0, T _y = 0);
			vector2(const _type& other);
			~vector2() = default;

			/*
			*/
			T dot(const _type& other);
			
			/*
			*/
			_type cross(const _type& other);

		public:
			T x, y;

		public:
			inline _type operator*(const T value)
			{
				return _type(x * value, y * value);
			};

			inline _type operator/(const T value)
			{
				MF_ASSERT(value <= -std::numeric_limits<T>::epsilon()
					|| value >= std::numeric_limits<T>::epsilon());

				return _type(x * value, y * value);
			};

			inline _type operator+(const _type& other)
			{
				return _type(x + other.x, y + other.y);
			};

			inline _type operator-(const _type& other)
			{
				return _type(x - other.x, y - other.y);
			};

			inline _type operator+=(const _type& other)
			{
				x += other.x;
				y += other.y;
				
				return *this;
			};

			inline _type operator-=(const _type& other)
			{
				x -= other.x;
				y -= other.y;

				return *this;
			};

			inline _type& operator=(const _type& other)
			{
				x = other.x;
				y = other.y;

				return *this;
			};
		};

		template<typename T>
		inline vector2<T>::vector2(T _x, T _y)
			: x(_x)
			, y(_y)
		{
		}

		template<typename T>
		inline vector2<T>::vector2(const _type& other)
		{
			operator=(other);
		}

		template<typename T>
		inline T vector2<T>::dot(const _type& other)
		{
			return x * other.x + y * other.y;
		}

		template<typename T>
		inline vector2<T> vector2<T>::cross(const _type& other)
		{
			//MF_ASSERT(0, "cross not implemented yet");
			return _type();
		}


		/*
		**	
		*/
		typedef vector2<short>	vec2s;
		typedef vector2<int>	vec2i;
		typedef vector2<float>	vec2f;
		typedef vector2<double>	vec2d;
	} // math
} // mufise

#endif // !_MF_VECTOR_HPP