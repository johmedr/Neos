#include <iostream>
#include "../include/core/meta/BaseTypes.hxx"
#include "../include/core/list/List.hxx"

using namespace std; 
using namespace list; 

// https://stackoverflow.com/questions/13827319/eliminate-duplicate-entries-from-c11-variadic-template-arguments

template <class ... Args>
struct process_zipper_args;

template <class ...Args>
struct zipper;

template <class ... ZArgs, class ... Args>
struct process_zipper_args<zipper<ZArgs...>, Args...>
{
	using type = typename process_zipper_args<ZArgs..., Args...>::type;
};

template <class ... LArgs, class ... Args> 
struct process_zipper_args<List<LArgs...>, Args...> 
{
	using type = typename process_zipper_args<LArgs..., Args...>::type; 
}; 

template <> 
struct  process_zipper_args<>
{
	using type = List<>; 
};

template <class LHead, class ... LTail>
struct process_zipper_args<LHead, LTail...>
{
	using type = List<LHead, typename process_zipper_args<LTail...>::type>; 
};

template <class ... Args> 
struct zipper : zipper<typename process_zipper_args<Args...>::type >
{}; 

template <class ... Args>
struct zipper< List< Args... > > : virtual Args...
{};

struct A 
{
	static const bool val = true;
};

struct B
{
	static constexpr bool f() 
	{
		return false;
	}
};

using z1 = zipper<A, B>; 


int main() 
{
	z1 i; 
	cout << boolalpha; 
	cout << i.val << "-" << i.f() << endl;
	return 0; 
}