#include <iostream>
// #include "../include/core/meta/BaseTypes.hxx"
// #include "../include/core/list/List.hxx"

using namespace std; 

// NB : un peu foireux, héritage par couple Inheritor<Head, Inheritor<Head2, Inheritor<Head3, Tail>>>
// Fixe avec un type list beaucoup plus propre 

template <class ... Cs>
struct List
{};

template <class ... Cs> 
struct RegContainer 
{
	using registry = List<Cs...>; 
}; 

template <class ... Cs>
struct Unique 
{
	using type = List<Cs...>;
};

template <class ... Cs> 
struct Inheritor : public Inheritor< typename Unique<Cs...>::type >
{
	using type = Inheritor<List<Cs...>>;
};

template <class ... Cs>
struct Inheritor<List<Cs...>> : public Cs... 
{};

// template <class L>
// struct InheritorBuilder
// {
// 	using type = Inheritor< typename L::Head, typename InheritorBuilder<typename L::Tail>::type >;
// };

// template <>
// struct InheritorBuilder<NIL>
// {
// 	using type = Inheritor<>; 
// };

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

// using Va = RegContainer<A, B>; 
// using In = typename InheritorBuilder<typename RegContainer<A, B>::registry>::type; 

using In = Inheritor<A, B>; 

int main() 
{
	In i; 
	cout << boolalpha; 
	cout << i.val << "-" << i.f() << endl;
	return 0; 
}