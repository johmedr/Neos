#ifndef MODULE_HXX
#define MODULE_HXX

#include <core/CoreMetaDefaultConfig.hxx>

namespace __core__
{
	template <class ...Ms> 
	class __atom__ : CORE_ATOM_VIRTUALITY CORE_ATOM_INHERITANCE Ms...
	{};
};

using Module = __core__::__atom__<>;


#endif 