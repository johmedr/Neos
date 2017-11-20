#ifndef TESTALLMETA_HXX
#define TESTALLMETA_HXX

#include "TestClassAtom.hxx"
#include "TestConditions.hxx"
#include "TestList.hxx"
#include "TestModuleUtils.hxx"
#include "TestVariadic.hxx"

class TestAllMeta : public TestAtom 
{
public: 
	bool runTests() 
	{
		TestClassAtom tca; 
		TestConditions tc; 
		TestList tl; 
		TestModuleUtils tmu; 
		TestVariadic tv;

		tca.runTests(); 
		tc.runTests(); 
		tl.runTests(); 
		tmu.runTests(); 
		tv.runTests(); 
	} 
};


#endif