#ifndef _MATRIX_IPP_
#define _MATRIX_IPP_

namespace pix::adt
{
    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    matrix<type_t, N_LIN, N_COL>::matrix(void)
    {
        is_number_static_assert(type_t);

        static_assert
        (
            N_LIN != 0 && N_COL != 0,
            "Array object cannot have zero lines or columns"
        );
    }

    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    matrix<type_t, N_LIN, N_COL>::matrix(const type_t arr[]) : matrix<type_t, N_LIN, N_COL>()
    {
        if (arr == nullptr)
            return;

        for (unsigned long i = 0; i < N_LIN; ++i)
            this->arr[i] = vector<type_t, N_COL>(arr + i * N_LIN);
    }

    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    matrix<type_t, N_LIN, N_COL>::matrix(const vector<type_t, N_COL> arr[]) : matrix<type_t, N_LIN, N_COL>()
    {
        if (arr == nullptr)
            return;

        for (unsigned long i = 0; i < N_LIN; ++i)
        {
            for (unsigned long j = 0; j < N_COL; ++j)
                this->arr[i][j] = arr[i].buffer()[j];
        }
    }

    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    matrix<type_t, N_LIN, N_COL>::matrix(const matrix<type_t, N_LIN, N_COL>& mtx) : matrix<type_t, N_LIN, N_COL>()
    {
        for (unsigned long i = 0; i < N_LIN; ++i)
        {
            for(unsigned long j = 0; j < N_COL; ++j)
                this->arr[i][j] = mtx[i][j];
        }
    }

    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    const type_t* matrix<type_t, N_LIN, N_COL>::buffer(void) const
    { return this->arr; }

    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    vector<type_t, N_COL>& matrix<type_t, N_LIN, N_COL>::operator [] (const unsigned long index)
    { return this->arr[index % N_LIN]; }

    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    constexpr const unsigned long matrix<type_t, N_LIN, N_COL>::n_lin(void) const
    { return N_LIN; }

    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    constexpr const unsigned long matrix<type_t, N_LIN, N_COL>::n_col(void) const
    { return N_COL; }

    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    void matrix<type_t, N_LIN, N_COL>::operator = (const matrix<type_t, N_LIN, N_COL>& mtx)
    {
        for (unsigned long i = 0; i < N_LIN; ++i)
            this->arr[i] = mtx.arr[i];
    }

    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    const bool matrix<type_t, N_LIN, N_COL>::operator == (const matrix<type_t, N_LIN, N_COL>& mtx) const
    {
        for (unsigned long i = 0; i < N_LIN; ++i)
        {
            if (this->arr[i] != mtx[i])
                return false;
        }

        return true;
    }

    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    template <typename _type_t, unsigned long _N_LIN, unsigned long _N_COL>
    constexpr const bool matrix<type_t, N_LIN, N_COL>::operator == (const matrix<_type_t, _N_LIN, _N_COL>& mtx) const
    { return false; }

    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    const bool matrix<type_t, N_LIN, N_COL>::operator != (const matrix<type_t, N_LIN, N_COL>& mtx) const
    { return !(*this == mtx); }

    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    template <typename _type_t, unsigned long _N_LIN, unsigned long _N_COL>
    constexpr const bool matrix<type_t, N_LIN, N_COL>::operator != (const matrix<_type_t, _N_LIN, _N_COL>& mtx) const
    { return true; }

    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    matrix<type_t, N_LIN, N_COL> matrix<type_t, N_LIN, N_COL>::operator + (const matrix<type_t, N_LIN, N_COL>& mtx) const
    {
        vector<type_t, N_COL> arr[N_LIN];

        for (unsigned long i = 0; i < N_LIN; ++i)
            arr[i] = this->arr[i] + mtx.arr[i];

        return matrix<type_t, N_LIN, N_COL>(arr);
    }

    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    matrix<type_t, N_LIN, N_COL> matrix<type_t, N_LIN, N_COL>::operator - (const matrix<type_t, N_LIN, N_COL>& mtx) const
    {
        vector<type_t, N_COL> arr[N_LIN];

        for (unsigned long i = 0; i < N_LIN; ++i)
            arr[i] = this->arr[i] - mtx.arr[i];

        return matrix<type_t, N_LIN, N_COL>(arr);
    }

    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    matrix<type_t, N_LIN, N_COL> matrix<type_t, N_LIN, N_COL>::operator * (const type_t scalar) const
    {
        vector<type_t, N_COL> arr[N_LIN];

        for (unsigned long i = 0; i < N_LIN; ++i)
            arr[i] = this->arr[i] * scalar;

        return matrix<type_t, N_LIN, N_COL>(arr);
    }

    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    matrix<type_t, N_LIN, N_COL> matrix<type_t, N_LIN, N_COL>::operator / (const type_t scalar) const
    {
        vector<type_t, N_COL> arr[N_LIN];

        for (unsigned long i = 0; i < N_LIN; ++i)
            arr[i] = this->arr[i] / scalar;

        return matrix<type_t, N_LIN, N_COL>(arr);
    }

    template <typename type_t, unsigned long N_LIN, unsigned long N_COL>
    template <unsigned long _N_COL>
    matrix<type_t, N_LIN, _N_COL> matrix<type_t, N_LIN, N_COL>::operator * (const matrix<type_t, N_COL, _N_COL>& mtx) const
    {
        vector<type_t, _N_COL> arr[N_LIN];

        for (unsigned long i = 0; i < N_LIN; ++i)
        {
            for (unsigned long j = 0; j < _N_COL; ++j)
            {
                arr[i][j] = 0;

                for (unsigned long k = 0; k < N_COL; ++k)
                    arr[i][j] += this->arr[i].buffer()[j] * mtx.arr[k].buffer()[j];
            }
        }

        return matrix<type_t, N_LIN, _N_COL>(arr);
    }
}

#endif // _MATRIX_IPP_