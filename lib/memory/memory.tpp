#ifndef _MEMORY_TPP_
#define _MEMORY_TPP_

namespace pix::memory
{
	void* memcpy(const void* src, void* dst, unsigned long size) noexcept(false)
	{
		if (src == nullptr) throw "Pointer to source is null";
		if (dst == nullptr) throw "Pointer to destination is null";
		if (size == 0) throw "Number of bytes equal to zero";

		auto s = reinterpret_cast<const unsigned char*>(src);
		auto d = reinterpret_cast<unsigned char*>(dst);

		// Copy byte-by-byte until destination is aligned
		while (reinterpret_cast<unsigned long>(d) % 8 && size > 0)
		{
			*d++ = *s++;
			--size;
		}

		// Copy 8 bytes at a time
		auto s64 = reinterpret_cast<const unsigned long*>(s);
		auto d64 = reinterpret_cast<unsigned long*>(d);
		
		while (size >= 8)
		{
			*d64++ = *s64++;
			size -= 8;
		}

		// Copy remaining bytes
		s = reinterpret_cast<const unsigned char*>(s64);
		d = reinterpret_cast<unsigned char*>(d64);
		
		while (size--)
			*d++ = *s++;

		return dst;
	}

	template <typename type_t>
	void realloc(type_t* buffer, const unsigned long size) noexcept(false)
	{
		if (buffer != nullptr)
			delete[] buffer;
		
		buffer = new type_t[size];
	}

	template <typename type_t>
	void extend(type_t* buffer, const unsigned long size, const unsigned long new_size) noexcept(false)
	{
		if (buffer == nullptr)
			throw pix::exceptions::null_ptr;

		type_t* temp = new type_t[size];
		memcpy(buffer, temp, size * sizeof(type_t));
		realloc(buffer, new_size);
		memcpy(temp, buffer, size * sizeof(type_t));
	}
}

#endif // _MEMORY_TPP_
