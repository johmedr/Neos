#ifndef MODULE_HXX
#define MODULE_HXX

namespace __core__
{
	template <class ...Ms> 
	class __atom__ : public Ms...
	{};
};

using Module = __core__::__atom__<>;

#endif 