#ifndef CONFREGISTRY_HXX
#define CONFREGISTRY_HXX 

template <class Spice>
struct Conf
{
	using Requires = List<>; // Required spices
	using Provides = List<>; // Provided spices
	using MemberList = List<>;  
	using MethodList = List<>;   
}; 

template <class H, class ...T> 
struct ConfRegistry : List<>
{}; 

 -------- DRAFT -----------

atom <S1, S2, ...>
{
	mod<S1>
	mod<S2> 
	...
}

mod<S> : atom<S>
{
	requires... 
	narrows... 
	Member...
	Method...
}

-> ajouter un mod 

----->
MySpice : Spice
{}

MyMod :  mod<MySpice>
{
	requires...
	narrows...
	Member...
	Method...
}
----->
<-----
// remove spices 

MyMod : mod
{
	requires...
	narrows...
	members... // W/ modes d'insertion ? (add, rm, replace, ...)
	methods...
}
<-----


=====> 
atom<mod1, mod2, ...> : validity_check<mods_requirement, mods_exclusion>
{
	process 
		for_each<mod1::members> m
			using atom<mod1, mod2, ...>::m; 
		for_each<mod1::methods> m 
			using atom<mod1, mod2, ...>::m; 
}



----> 
pipeline : 
	[definition des modules]
	-> pimp your atom <mods> 
	-> use pimped atoms. 
	nodes'connect, ... 

<=> packages c++ 




#endif