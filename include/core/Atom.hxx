#ifndef ATOM_HXX
#define ATOM_HXX

#include "./Spice.hxx"

template <class ...Spices> 
class Atom : public Mxx_enable_if<Mxx_are_spices<Spices...>, Spice>::type
{

}; 

#endif