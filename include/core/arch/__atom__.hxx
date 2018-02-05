#ifndef __ATOM__HXX
#define __ATOM__HXX

#include <core/arch/__config__.hxx>
#include <core/arch/__va_mpl__.hxx>
#include <core/arch/__types__.hxx>
#include <core/arch/__conditions__.hxx>

namespace arch
{
	namespace __core__
	{
		template <typename ...Ms> 
		class __atom__ : 
			CORE_ATOM_VIRTUALITY CORE_ATOM_INHERITANCE Ms...
		{};

		template <typename ...Ms> 
		class __preprocess_valid_Ms__; 

		template <typename ...Ms> 
		class __build_atom__ : 
			build_if<
				(are_derived_from<__core__::__atom__<>, Ms...>::value || is_empty<Ms ...>::value),
				typename __preprocess_valid_Ms__<Ms...>::type >::type 
		{}; 

		template <typename ...Ms> 
		class __preprocess_valid_Ms__ : 
			t_type< 
				typename __va_mpl__::make_unique< __atom__<>, Ms... >::type 
				> 
		{}; 


	};

	using Module = __core__::__atom__<>;

	template <typename ...Ms>
	using Atom = typename build_if< 
		(are_derived_from<__core__::__atom__<>, Ms...>::value || is_empty<Ms ...>::value), 
			typename __va_mpl__::make_unique<__core__::__atom__<>, Ms...>::type >::type; 
};

#endif