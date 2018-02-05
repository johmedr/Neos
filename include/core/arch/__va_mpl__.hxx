#ifndef __VA_MPL__HXX
#define __VA_MPL__HXX

#include <core/arch/__types__.hxx>

namespace arch
{
	namespace __va_mpl__
	{
		template < typename TElt, typename TClass >  
		struct is_in : 
			false_type
		{};

		template < typename TElt, typename ...TOthers, 
			template <typename...> typename TClass >
		struct is_in< TElt, TClass<TElt, TOthers...> > : 
			true_type
		{};

		template < typename TElt, typename TFirst, typename ...TOthers, 
			template <typename...> typename TClass >
		struct is_in< TElt, TClass<TFirst, TOthers...> > : 
			is_in< TElt, TClass<TOthers...> >
		{};

		template < typename TClass, typename ...TNew > 
		struct push_front;

		template < template <typename...> typename TClass, 
			typename ...TClassArgs, typename ...TNew >
		struct push_front< TClass<TClassArgs...>, TNew... > : 
			t_type< TClass<TNew..., TClassArgs...> > 
		{};

		template < typename TClass, typename ...TNew > 
		struct push_back;

		template < template <typename...> typename TClass, 
			typename ...TClassArgs, typename ...TNew >
		struct push_back< TClass<TClassArgs...>, TNew... > : 
			t_type< TClass<TClassArgs..., TNew...> > 
		{};

		template < typename TNew, typename TClass, 
			bool TIsIn = is_in< TNew, TClass >::value >
		struct add_unique; 

		template < typename TNew, typename ...TArgs, 
			template <typename...> typename TClass >
		struct add_unique< TNew, TClass<TArgs...>, true > : 
			t_type< TClass<TArgs...> >
		{};

		template < typename TNew, typename ...TArgs, 
			template <typename...> typename TClass >
		struct add_unique< TNew, TClass<TArgs...>, false > : 
			t_type< TClass<TNew, TArgs...> >
		{};

		namespace __helper__ 
		{
			template < template <typename...> typename TClass, 
				typename ...TArgs >
			struct helper_make_unique;

			// End of recursion
			template < template <typename ...> typename TClass >
			struct helper_make_unique< TClass > : 
				t_type< TClass<> >
			{};

			// Recurse and add unique object
			template < template <typename ...> typename TClass, 
				typename THead, typename ...TTail >
			struct helper_make_unique< TClass, THead, TTail... > : 
				t_type< typename add_unique< THead, 
					typename helper_make_unique<TClass, TTail... >::type >::type >
			{}; 
		};

		template < typename ...TArgs > 
		struct make_unique; 

		template < typename ...TClassArgs, typename ...TArgs, 
			template <typename...> typename TClass >
		struct make_unique< TClass<TClassArgs...>, TArgs... > : 
			t_type<  typename __helper__::helper_make_unique< 
				TClass, TClassArgs..., TArgs... >::type >
		{};

		// usage : TClass templated type, ununpack_first_order_args< TClass, Args >::type 
		template < template <typename...> typename TClass, typename ...TArgs >
		struct unpack_first_order_vargs; 

		template < template <typename...> typename TClass >
		struct unpack_first_order_vargs< TClass > : 
			t_type< TClass<> >
		{};

		// namespace __helper__ 
		// {	
		// 	template < template <typename...> typename TClass, typename TArg >
		// 	struct helper_unpack_first_order_arg; 

		// 	template < typename TArg >
		// 	struct helper_unpack_first_order_arg : 
		// 		t_type<TArg>
		// 	{}; 

		// 	template < template <typename...> typename TClass, 	
		// 		typename TArgsHead, typename ...TArgsTail >
		// 	struct helper_unpack_first_order_arg : 
		// 		t_type<TArgsHead, TArgsTail...>
		// 	{};
		// };

		// Have separate Head and Tail guarantees that the class is not empty
		template < template <typename...> typename TClass, 
			typename ...TClassArgs, typename ...TArgs >
		struct unpack_first_order_vargs< TClass, TClass<TClassArgs...>, TArgs... > : 
			t_type< typename push_front< 
				typename unpack_first_order_vargs<TClass, TArgs...>::type, 
					TClassArgs... >::type >
		{};  

		template < template <typename...> typename TClass, 
			typename TArgsHead, typename ...TArgsTail >
		struct unpack_first_order_vargs< TClass, TArgsHead, TArgsTail... > : 
			t_type< typename push_front< 	
				typename unpack_first_order_vargs<TClass, TArgsTail...>::type, 
					TArgsHead >::type >
		{}; 
	}; 
};

#endif