#ifndef __HASH_TABLE_HPP__
#define __HASH_TABLE_HPP__

// Abstract data types
namespace pix::adt
{
	template <typename type_t, unsigned long BUFFER_SIZE = D_BUFFER_SIZE>
	struct hash_item
	{
		char _key[BUFFER_SIZE];
		type_t _value;
	};

	template <typename type_t, unsigned long DIM, unsigned long BUFFER_SIZE = D_BUFFER_SIZE>
	class hash_table
	{
	private:

		hash_item _data[DIM];

	public:
	};
}

// Template file
#include <hash_table.tpp>

#endif // __HASH_TABLE_HPP__
