#ifndef _MATRIX_IPP_
#define _MATRIX_IPP_

using namespace pix::adt;

template <typename type_t, size_t N_LIN, size_t N_COL>
matrix<type_t, N_LIN, N_COL>::matrix(void)
{
    is_number_static_assert(type_t);

    static_assert
    (
        N_LIN != 0 && N_COL != 0,
        "Array object cannot have zero lines or columns"
    );

    for (size_t i = 0; i < N_LIN; ++i)
        this->arr[i] = vector<type_t, N_COL>();
}

template <typename type_t, size_t N_LIN, size_t N_COL>
matrix<type_t, N_LIN, N_COL>::matrix(const type_t arr[]) : matrix<type_t, N_LIN, N_COL>()
{
    if (arr == nullptr)
        return;

    for (size_t i = 0; i < N_LIN; ++i)
        this->arr[i] = vector<type_t, N_COL>(arr + i * N_LIN);
}

template <typename type_t, size_t N_LIN, size_t N_COL>
matrix<type_t, N_LIN, N_COL>::matrix(vector<type_t, N_COL> arr[]) : matrix<type_t, N_LIN, N_COL>()
{
    if (arr == nullptr)
        return;

    for (size_t i = 0; i < N_LIN; ++i)
        this->arr[i] = arr[i];
}

template <typename type_t, size_t N_LIN, size_t N_COL>
template <typename _type_t, size_t _N_LIN, size_t _N_COL>
matrix<type_t, N_LIN, N_COL>::matrix(matrix<_type_t, _N_LIN, _N_COL>& mtx)
{ *this = mtx; }

template <typename type_t, size_t N_LIN, size_t N_COL>
vector<type_t, N_COL>& matrix<type_t, N_LIN, N_COL>::operator [] (const size_t ind)
{ return this->arr[ind % N_LIN]; }

template <typename type_t, size_t N_LIN, size_t N_COL>
constexpr const size_t matrix<type_t, N_LIN, N_COL>::n_lin(void) const
{ return N_LIN; }

template <typename type_t, size_t N_LIN, size_t N_COL>
constexpr const size_t matrix<type_t, N_LIN, N_COL>::n_col(void) const
{ return N_COL; }

template <typename type_t, size_t N_LIN, size_t N_COL>
template <typename _type_t, size_t _N_LIN, size_t _N_COL>
void matrix<type_t, N_LIN, N_COL>::operator = (matrix<_type_t, _N_LIN, _N_COL>& mtx)
{
    for (size_t i = 0; i < N_LIN && i < _N_LIN; ++i)
        this->arr[i] = mtx[i];
}

template <typename type_t, size_t N_LIN, size_t N_COL>
template <typename _type_t, size_t _N_LIN, size_t _N_COL>
const bool matrix<type_t, N_LIN, N_COL>::operator == (matrix<_type_t, _N_LIN, _N_COL>& mtx) const
{ return false; }

template <typename type_t, size_t N_LIN, size_t N_COL>
const bool matrix<type_t, N_LIN, N_COL>::operator == (matrix<type_t, N_LIN, N_COL>& mtx) const
{
    for (size_t i = 0; i < N_LIN; ++i)
    {
        if (this->arr[i] != mtx[i])
            return false;
    }

    return true;
}

template <typename type_t, size_t N_LIN, size_t N_COL>
template <typename _type_t, size_t _N_LIN, size_t _N_COL>
const bool matrix<type_t, N_LIN, N_COL>::operator != (matrix<_type_t, _N_LIN, _N_COL>& mtx) const
{ return true; }

template <typename type_t, size_t N_LIN, size_t N_COL>
const bool matrix<type_t, N_LIN, N_COL>::operator != (matrix<type_t, N_LIN, N_COL>& mtx) const
{ return !(*this == mtx); }

template <typename type_t, size_t N_LIN, size_t N_COL>
template <typename _type_t>
matrix<type_t, N_LIN, N_COL> matrix<type_t, N_LIN, N_COL>::operator + (matrix<_type_t, N_LIN, N_COL>& mtx) const
{
    vector<type_t, N_COL> arr[N_LIN];

    for (size_t i = 0; i < N_LIN; ++i)
        arr[i] = this->arr[i] + mtx[i];

    return matrix<type_t, N_LIN, N_COL>(arr);
}

template <typename type_t, size_t N_LIN, size_t N_COL>
template <typename _type_t>
matrix<type_t, N_LIN, N_COL> matrix<type_t, N_LIN, N_COL>::operator - (matrix<_type_t, N_LIN, N_COL>& mtx) const
{
    vector<type_t, N_COL> arr[N_LIN];

    for (size_t i = 0; i < N_LIN; ++i)
        arr[i] = this->arr[i] - static_cast<type_t>(mtx[i]);

    return matrix<type_t, N_LIN, N_COL>(arr);
}

template <typename type_t, size_t N_LIN, size_t N_COL>
template <typename _type_t>
matrix<type_t, N_LIN, N_COL> matrix<type_t, N_LIN, N_COL>::operator * (const _type_t scalar) const
{
    vector<type_t, N_COL> arr[N_LIN];

    for (size_t i = 0; i < N_LIN; ++i)
        arr[i] = this->arr[i] * static_cast<type_t>(scalar);

    return matrix<type_t, N_LIN, N_COL>(arr);
}

template <typename type_t, size_t N_LIN, size_t N_COL>
template <typename _type_t>
matrix<type_t, N_LIN, N_COL> matrix<type_t, N_LIN, N_COL>::operator / (const _type_t scalar) const
{
    vector<type_t, N_COL> arr[N_LIN];

    for (size_t i = 0; i < N_LIN; ++i)
        arr[i] = this->arr[i] / static_cast<type_t>(scalar);

    return matrix<type_t, N_LIN, N_COL>(arr);
}

template <typename type_t, size_t N_LIN, size_t N_COL>
template <typename _type_t, size_t _N_COL>
matrix<type_t, N_LIN, _N_COL> matrix<type_t, N_LIN, N_COL>::operator * (matrix<_type_t, N_COL, _N_COL>& mtx) const
{
    vector<type_t, _N_COL> arr[N_LIN];

    for (size_t i = 0; i < N_LIN; ++i)
    {
        for (size_t j = 0; j < _N_COL; ++j)
        {
            arr[i][j] = 0;

            for (size_t k = 0; k < N_COL; ++k)
                arr[i][j] += this->arr[i][k] * mtx[k][j];
        }
    }

    return matrix<type_t, N_LIN, _N_COL>(arr);
}

#endif // _MATRIX_IPP_