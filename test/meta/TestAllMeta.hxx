#ifndef TESTALLMETA_HXX
#define TESTALLMETA_HXX

#include "TestClassAtom.hxx"
#include "TestConditions.hxx"
#include "TestList.hxx"
#include "TestSpiceUtils.hxx"
#include "TestVariadic.hxx"

class TestAllMeta : public TestAtom 
{
public: 
	bool runTests() 
	{
		TestClassAtom tca; 
		TestConditions tc; 
		TestList tl; 
		TestSpiceUtils tsu; 
		TestVariadic tv;

		tca.runTests(); 
		tc.runTests(); 
		tl.runTests(); 
		tsu.runTests(); 
		tv.runTests(); 
	} 
};


#endif