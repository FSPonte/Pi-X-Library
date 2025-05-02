#ifndef _COMPLEX_HPP_
#define _COMPLEX_HPP_

// Mathematical complex number
namespace pix::math
{
	/**
	 * @brief Complex number
	 * @tparam type_t Data type
	*/
	template <typename type_t>
	class complex
	{
	private:

		type_t
			_re, // Real part
			_im; // Imaginary part

	public:

		/**
		 * @brief Default constructor
		*/
		complex(void);

		/**
		 * @brief Parameterized constructor
		 * @param re Real part
		 * @param im Imaginary part
		*/
		complex(type_t, type_t);

		/**
		 * @brief Set real part
		 * @param val Value
		*/
		void set_re(type_t);

		/**
		 * @brief Get real part
		 * @return Value
		*/
		type_t get_re(void) const;

		/**
		 * @brief Set imaginary part
		 * @param val Value
		*/
		void set_im(type_t);

		/**
		 * @brief Get imaginary part
		 * @return Value
		*/
		type_t get_im(void) const;

		/**
		 * @brief Copy operator
		 * @param cpx Complex
		*/
		void operator = (const complex<type_t>&);

		/**
		 * @brief Equality operator
		 * @param cpx Complex
		 * @return True if complex numbers are equal
		*/
		bool operator == (const complex<type_t>&) const;

		/**
		 * @brief Equality operator
		 * @tparam _type_t Data type
		 * @param cpx Complex
		 * @return False
		*/
		template <typename _type_t>
		constexpr bool operator == (const complex<_type_t>&) const;

		/**
		 * @brief Inequality operator
		 * @param cpx Complex
		 * @return True if complex numbers are different
		*/
		bool operator != (const complex<type_t>&) const;

		/**
		 * @brief Inequality operator
		 * @tparam _type_t Data type
		 * @param cpx Complex
		 * @return True
		*/
		template <typename _type_t>
		constexpr bool operator != (const complex<_type_t>&) const;

		/**
		 * @brief Scalar multiplication
		 * @param scl Scalar
		 * @return Scaled complex number
		*/
		complex<type_t> operator * (type_t) const;

		/**
		 * @brief Adition operator
		 * @param cpx Complex
		 * @return Added complex
		*/
		complex<type_t> operator + (const complex<type_t>&) const;

		/**
		 * @brief Subtraction operator
		 * @param cpx Complex
		 * @return Subtracted complex
		*/
		complex<type_t> operator - (const complex<type_t>&) const;

		/**
		 * @brief Multiplication operator
		 * @param cpx Complex
		 * @return Multiplied complex
		*/
		complex<type_t> operator * (const complex<type_t>&) const;
	};
}

// Template file
#include "complex.tpp"

#endif // _COMPLEX_HPP_
