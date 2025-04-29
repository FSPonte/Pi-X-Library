#ifndef _IMAGE_HPP_
#define _IMAGE_HPP_

// Dependencies
#include <rgb.hpp>

namespace pix::graphics
{
	/**
	 * @brief Image
	 * @tparam W_DIM Width
	 * @tparam H_DIM Height
	*/
	template <unsigned long W_DIM, unsigned long H_DIM>
	class image
	{
	private:

		rgb** _data;

	public:

		/**
		 * @brief Constructor
		*/
		image(void);

		/**
		 * @brief Destructor
		*/
		~image(void);

		/**
		 * @brief Get data
		 * @return Pointer to data
		*/
		rgb** data(void);

		/**
		 * @brief Get pixel
		 * @param y Vertical coordinate
		 * @param x Horizontal coordinate
		 * @throw Y coordinate is out of bounds
		 * @throw X coordinate is out of bounds
		*/
		rgb& get(unsigned long, unsigned long) noexcept(false);

		/**
		 * @brief Get width
		 * @return Width
		*/
		constexpr unsigned long width(void) const;

		/**
		 * @brief Get height
		 * @return Height
		*/
		constexpr unsigned long height(void) const;

		/**
		 * @brief Get resolution
		 * @return Number of pixels
		*/
		constexpr unsigned long resolution(void) const;

		/**
		 * @brief Size of image
		 * @return Number of bytes
		 * @note This is the size of the image object, not the final image file
		*/
		constexpr unsigned long size(void) const;

		/**
		 * @brief Copy a image
		 * @param img Image
		*/
		void operator = (const image<W_DIM, H_DIM>&);
	};
}

// Template file
#include "image.tpp"

#endif // _IMAGE_HPP_
