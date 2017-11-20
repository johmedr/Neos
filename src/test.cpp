#include <iostream>
#include <cstdlib>

#include "../include/meta/conditions.hxx"

struct Module
{}; 


template <class C>
struct Mod : Module
{};

template <>
struct Mod<int> 
{
	static const int n; 
	void f(void) {}
};

template <> 
struct Mod<char>
{
	void f1(int a) {} 
	void f2(char b) {}
};

template <class C1, class ...C> 
struct Atom;

	// Atom< int, char, bool > 
	// : compose_atom<Atom< 
	// 	int, 
	// 	: compose_atom<Atom< 
	// 		char, 
	// 		: compose_atom<
	// 			bool >
	// 		type = bool
	// 	type = Atom<char, bool>
	// type = Atom<int, char, bool> 

template <class H, class ...T> 				  
struct compose_atom : t_type< Atom< H, 
									typename compose_atom<T...>::type
								>
							>
{};

template <class H>
struct compose_atom<H> : t_type<Atom<H>>
{};

template <class H = Module, class ...M> 
struct Atom : enable_if< 
					true,
					H>::type
// struct Atom : conditional<is_empty<M...>::value, Module, typename compose_atom<M...>::type>::type
{};

// template <class ...M>
// struct Atom :  M... // Solution 
// {}; 


struct mayia_static_mod : Module 
{
	struct mayia_static
	{
	public: 
		static void f() 
		{
			std::cout << "Hello Static Mayia ! :)" << std::endl; 
		}
	};
}; 


struct mayia_dynamic_mod : Module 
{
	struct mayia_dynamic_conf
	{
	private:
		const int nb;  
	public: 
		mayia_dynamic_conf() : nb(rand()) {}

		void f() 
		{
			std::cout << "Hello Dynamic Mayia (" << nb << ") ! :)" << std::endl; 
		}
	};

	mayia_dynamic_conf mayia_dynamic; 
}; 

int main() 
{
	Atom<Mod<char>> dc; 
	Atom<Mod<int>> di;
	Atom<Mod<int>, Mod<char>> dic; 

	dc.f1(3); 
	dc.f2(4); 

	di.f(); 

	dic.f1(3); 
	dic.f2(5); 
	dic.f(); 

	using static_atom = Atom<mayia_static_mod>; 
	static_atom::mayia_static::f(); 

	Atom<mayia_dynamic_mod> dynamic_atom1, dynamic_atom2; 
	dynamic_atom1.mayia_dynamic.f(); 
	dynamic_atom2.mayia_dynamic.f(); 

	using hybrid_atom = Atom< mayia_static_mod, mayia_dynamic_mod >; 
	hybrid_atom at; 
	using hybrid_atom2 = Atom< mayia_static_mod, mayia_dynamic_mod >; 
	hybrid_atom2 at2; 

	hybrid_atom::mayia_static::f(); 
	hybrid_atom2::mayia_static::f(); 

	at.mayia_dynamic.f(); 
	at2.mayia_dynamic.f(); 

	std::cout << std::boolalpha; 
	std::cout << equals< hybrid_atom, hybrid_atom2 >::value << std::endl; 
}