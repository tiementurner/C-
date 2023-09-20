template <typename T>
Array<T>::Array() :ptr(NULL),
                   number_of_elements(0){}

template <typename T>
Array<T>::~Array()
{
    delete []ptr;
}

template <typename T>
Array<T>::Array(unsigned int n) 
{
    this->number_of_elements =  n;
    this->ptr = new T[number_of_elements];
    for(std::size_t i = 0; i < n; i++)
        ptr[i] = T();
}

template <typename T>
Array<T>::Array(const Array<T> &other) : ptr(NULL)
{
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this == &other)
        return (*this);
    if (this->number_of_elements != other.size())
    {
        if (this->ptr != NULL)
            delete []this->ptr;
            this->ptr = new T[other.size()];
            this->number_of_elements = other.size();
    }
    for (std::size_t i = 0; i < this->number_of_elements; i++)
        this->ptr[i] = other[i];
    return (*this);

}

template <typename T>
size_t  Array<T>::size() const
{
    return (this->number_of_elements);
}

template <typename T>
T& Array<T>::operator[](std::size_t index)
{
    if (index >= number_of_elements || index < 0)
    {
        throw Array::IndexOutOfBoundsException();
    }
    return (this->ptr[index]);
}

template <typename T>
const T& Array<T>::operator[](std::size_t index) const
{
    if (index >= number_of_elements || index < 0)
    {
        throw Array::IndexOutOfBoundsException();
    }
    return (this->ptr[index]);
}