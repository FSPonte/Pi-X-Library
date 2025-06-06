#ifndef _SIGNAL_TPP_
#define _SIGNAL_TPP_

namespace pix::math::signal
{
	template <typename type_t>
	void mean_sub(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (arr == nullptr) throw "Pointer to array is null";
		if (DIM == 0) throw "Dimension is null";

		const type_t mean = pix::math::stat::mean(arr, DIM);

		for (unsigned long i = 0; i < DIM; ++i)
			arr[i] -= mean;
	}

	template <typename type_t>
	void norm(type_t arr[], const unsigned long DIM) noexcept(false)
	{
		assert_is_number(type_t);

		if (arr == nullptr) throw "Pointer to array is null";
		if (DIM == 0) throw "Dimension is null";

		const type_t max_val = pix::math::abs(pix::math::stat::max(arr, DIM));

		for (unsigned long i = 0; i < DIM; ++i)
			arr[i] /= max_val;
	}
	
	namespace window
	{
		template <typename type_t>
		void hann(type_t arr[], const unsigned long DIM) noexcept(false)
		{
			assert_is_number(type_t);

			if (arr == nullptr) throw "Pointer to array is null";
			if (DIM == 0) throw "Dimension is null";

			static constexpr const auto PI_2 = static_cast<type_t>(2 * pix::constants::mathematics::PI);

			for (unsigned long i = 0; i < DIM; ++i)
				arr[i] *= 0.5 * (1 - pix::math::trig::cos(PI_2 * i / (DIM - 1)));
		}

		template <typename type_t>
		void hamming(type_t arr[], const unsigned long DIM) noexcept(false)
		{
			assert_is_number(type_t);

			if (arr == nullptr) throw "Pointer to array is null";
			if (DIM == 0) throw "Dimension is null";

			static constexpr const auto PI_2 = static_cast<type_t>(2 * pix::constants::mathematics::PI);

			for (unsigned long i = 0; i < DIM; ++i)
				arr[i] *= 0.54 - 0.46 * pix::math::trig::cos(PI_2 * i / (DIM - 1));
		}

		template <typename type_t>
		void blackman(type_t arr[], const unsigned long DIM) noexcept(false)
		{
			assert_is_number(type_t);

			if (arr == nullptr) throw "Pointer to array is null";
			if (DIM == 0) throw "Dimension is null";
			
			constexpr const auto
				PI_2 = static_cast<type_t>(2 * pix::constants::mathematics::PI),
				PI_4 = PI_2 * 2;

			for (unsigned long i = 0; i < DIM; ++i)
				arr[i] *= 0.42 - 0.5 * pix::math::trig::cos(PI_2 * i / (DIM - 1)) + 0.08 * pix::math::trig::cos(PI_4 * i / (DIM - 1));
		}
	}

	namespace transform
	{
		template <typename type_t>
		void dft
		(
			const type_t TIME[],
			const type_t SIGNAL[],
			const type_t FREQ[],
			type_t transform[],
			const unsigned long DOMAIN_DIM,
			const unsigned long TRANSFORM_DIM
		) noexcept(false)
		{
			assert_is_number(type_t);

			if (TIME == nullptr) throw "Pointer to time array is null";
			if (SIGNAL == nullptr) throw "Pointer to signal array is null";
			if (FREQ == nullptr) throw "Pointer to frequencies array is null";
			if (transform == nullptr) throw "Pointer to transform array is null";
			if (DOMAIN_DIM == 0) throw "Domain dimension is null";
			if (TRANSFORM_DIM == 0) throw "Transform dimension is null";

			constexpr const auto PI_2 = static_cast<type_t>(2 * pix::constants::mathematics::PI);
			type_t
				omega, // Angular frequency
				arg, // Complex angle
				real, // Complex real part
				imag; // Complex imaginary part

			for (unsigned long i = 0; i < TRANSFORM_DIM; ++i)
			{
				omega = PI_2 * FREQ[i];
				real = 0;
				imag = 0;

				for (unsigned long j = 0; j < DOMAIN_DIM; ++j)
				{
					arg = -omega * TIME[j];
					real += SIGNAL[j] * pix::math::trig::cos(arg);
					imag += SIGNAL[j] * pix::math::trig::sin(arg);
				}

				transform[i] = pix::math::root(real * real + imag * imag, static_cast<type_t>(2));
			}
		}
	}
}

#endif // _SIGNAL_TPP_
