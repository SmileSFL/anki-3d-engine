#ifndef ANKI_UTIL_SINGLETON_H
#define ANKI_UTIL_SINGLETON_H

#ifndef NULL
#	define NULL 0
#endif


namespace anki {


/// This template makes a class singleton
template<typename Type>
class Singleton
{
public:
	typedef Type ValueType;

	static Type& get()
	{
		return *(instance ? instance : (instance = new Type));
	}

protected:
	Singleton();
	~Singleton();

private:
	static Type* instance;
	Singleton(Singleton const&);
	Singleton& operator=(const Singleton&);
};


template <typename Type>
Type* Singleton<Type>::instance = NULL;


} // end namespace


#endif