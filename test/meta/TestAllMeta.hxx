#ifndef TESTALLMETA_HXX
#define TESTALLMETA_HXX

#include "TestClassAtom.hxx"
#include "TestConditions.hxx"
#include "TestList.hxx"
#include "TestModule.hxx"
#include "TestVariadic.hxx"

class TestAllMeta : public TestAtom 
{
public: 
	bool runTests() 
	{
		TestClassAtom tca; 
		TestConditions tc; 
		TestList tl; 
		TestModule tmu; 
		TestVariadic tv;

		tca.runTests(); 
		tc.runTests(); 
		tl.runTests(); 
		tmu.runTests(); 
		tv.runTests(); 
	} 
};


#endif