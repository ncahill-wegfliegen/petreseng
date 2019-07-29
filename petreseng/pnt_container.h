#pragma once

#include <vector>

namespace nhill
{

template<typename T>
struct Pnt;

template<typename T = double>
using Pnt_container = std::vector<Pnt<T>>;

template<typename T = double>
using Pnt_ptr_container = std::vector<typename Pnt<T>::ptr>;

template<typename T = double>
using Pnt_cptr_container = std::vector<typename Pnt<T>::cptr>;

}
