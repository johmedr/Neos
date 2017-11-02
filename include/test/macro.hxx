#ifndef TESTMACRO_HXX
#define TESTMACRO_HXX

#define PRINTLN(str) std::cout << str << std::endl; 
#define TEST_ASSERT(expr) 	\
	if(! expr) 				\
	{						\
		PRINTLN(#expr << " : test failed !"); 	\
		exit(0); 			\
	}


#endif