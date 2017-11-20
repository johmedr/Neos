
struct Base
{}; 

template <class C>
struct Mod : Base
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

template <class ...C>
struct Derv : Base, C... // Solution 
{}; 

int main() 
{
	Derv<Mod<char>> dc; 
	Derv<Mod<int>> di;
	Derv<Mod<int>, Mod<char>> dic; 

	dc.f1(3); 
	dc.f2(4); 

	di.f(); 

	dic.f1(3); 
	dic.f2(5); 
	dic.f(); 
}