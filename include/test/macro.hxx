#ifndef TESTMACRO_HXX
#define TESTMACRO_HXX

#include <iostream>

#define PRINTLN(str) std::cerr << str << std::endl; 
#define TEST_ASSERT(expr) 						\
	if(! (expr) )									\
	{											\
		PRINTLN(#expr << " : test failed !"); 	\
		exit(1); 								\
	}


#endif