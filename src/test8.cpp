template <class T> class Allocator (sizeof(Allocator) == 1)
{
	 public :
        static T* allocate(int n)
            {
            return ((T*) operator new(n * sizeof(T)));
            }
        static void deallocate(void* p)
            {
            operator delete(p);
            }
        }; 

int main()
{
	
}