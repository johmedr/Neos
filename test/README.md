# Testing in NEOS

## The good methodology 

**Naming convention** 

The file containing the tests to be run have the extension `.cc`
The name should clearly identify the source file under test. 

**Structure** 

For genericity, a struct inheriting from `TestAtom` 
is defined in the test file. It should implement a function 
`runTests()`. 

The structure declaration and definition is followed by a `main()` function, 
which should only instantiate the `TestAtom` and call the `runTests()` function. 


**Example**

File *TestExample.cc* :
``` C++
#include <necessary_includes_here>

struct TestExample : TestAtom
{
// go in a private scope 
private: 

	// do the convenient declarations there
	const int foo = 3; 
	using bar = MyWeirdClass<blob, blib>; 

	// create tests functions there 
	bool testBarInstanciation() 
	{
		// stuff 
	}  

	// ...

public: 
	virtual bool runTests() override 
	{
		testBarInstanciation(); 
		// ...
	}
}; // end of test struct definition 

int main() 
{
	TestExample te; 
	te.runTests(); 
}

```
