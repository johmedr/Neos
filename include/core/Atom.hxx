#ifndef ATOM_HXX
#define ATOM_HXX

#include "./Spice.hxx"

template <class ...Spices> 
class Atom : public Spice//enable_if<are_spices<Spices...>, Spice>::type
{

}; 

#endif