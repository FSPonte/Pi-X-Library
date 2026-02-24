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
		while ((unsigned long)d % 8 && size > 0)
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
}

#endif // _MEMORY_TPP_
