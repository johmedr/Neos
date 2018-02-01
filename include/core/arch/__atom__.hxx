#ifndef __ATOM__HXX
#define __ATOM__HXX

#include <core/arch/__config__.hxx>
#include <core/arch/__va_mpl__.hxx>

namespace arch
{
	namespace __core__
	{
		template <class ...Ms> 
		class __atom__ : 
			CORE_ATOM_VIRTUALITY CORE_ATOM_INHERITANCE Ms...
		{};	
	};

	using Module = __core__::__atom__<>;

	template <class ...Ms>
	using Atom = typename __va_mpl__::make_unique<__core__::__atom__<Ms...>>::type; 
};

#endif