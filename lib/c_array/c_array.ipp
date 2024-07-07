#ifndef _C_ARRAY_IPP_
#define _C_ARRAY_IPP_

namespace pix::c_array
{
    template <typename type_t>
    inline void swap(type_t& ref_1, type_t& ref_2) noexcept(true)
    {
        const type_t aux = ref_1;
        ref_1 = ref_2;
        ref_2 = aux;
    }
}

#endif // _C_ARRAY_IPP_