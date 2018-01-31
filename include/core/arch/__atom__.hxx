#ifndef __ATOM__HXX
#define __ATOM__HXX

#include <core/arch/__config__.hxx>

namespace core
{
	namespace __core__
	{
		template <class ...Ms> 
		class __atom__ : CORE_ATOM_VIRTUALITY CORE_ATOM_INHERITANCE Ms...
		{};

	};
};

#endif