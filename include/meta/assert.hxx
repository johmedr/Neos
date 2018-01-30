#ifndef ASSERT_HXX
#define ASSERT_HXX 

#include <meta/base_types.hxx>

struct __Assert__{};

template <bool B, class _A = __Assert__> 
struct Assert 
{
    using result = typename _A::fail;
};

template <> struct Assert<true> 
{
	using result = true_type; 
};
 

#endif