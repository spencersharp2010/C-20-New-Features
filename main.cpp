#include <iostream>
//#include <concepts>
#include <type_traits>
#include <string>

/* PLAIN TEMPLATED MOD FUNCTION */
template<typename T1, typename T2>
auto modulo_plain(T1 n, T2 d)
{
	return n % d;
}

void test_modulo_plain()
{
	int n = 9;
	int d = 5;
	std::cout << "using modulo plain: " << std::endl;
	std::cout << n << " mod " << d << " = " << modulo_plain(n, d) << std::endl;
}

/* SFINAE MOD FUNCTION */
template<typename T1, typename T2,
	typename = std::enable_if_t<
	std::is_integral_v<T1> && std::is_integral_v<T2>>
	>

auto modulo_trait(T1 n, T2 d)
{
	return n % d;
}

void test_modulo_trait()
{
	int n = 9;
	int d = 5;
	std::cout << "using modulo trait: " << std::endl;
	std::cout << n << " mod " << d << " = " << modulo_trait(n, d) << std::endl;
}

/* MOD FUNCTION WITH REQUIRES */
template<typename T1, typename T2>
auto modulo_requires(T1 n, T2 d)
requires
requires { n % d; }
{
	return n % d;
}

void test_modulo_requires()
{
	int n = 9;
	int d = 5;
	std::cout << "using modulo requires: " << std::endl;
	std::cout << n << " mod " << d << " = " << modulo_requires(n, d) << std::endl;
}

/* MOD FUNCTION WITH CONCEPT */
template<typename T1, typename T2>
concept bool ModuloSupported = requires (T1 n, T2 d)
{
	n % d;
};

template<typename T1, typename T2>
auto modulo_concept(T1 n, T2 d) 
	requires ModuloSupported<T1, T2>
{
	return n % d;
}

void test_modulo_concept()
{
	int n = 9;
	int d = 5;
	std::cout << "using modulo concept: " << std::endl;
	std::cout << n << " mod " << d << " = " << modulo_concept(n, d) << std::endl;
}

/* MOD FUNCTION WITH CONCEPT, SHORTENED */
//in this case, we have an appropriate type trait which allows us to evaluate each argument independently
template<typename T>
concept bool Integral = std::is_integral_v<T>; 

//replace "typename" with "Integral"
template<Integral T1, Integral T2>
auto modulo_concept2(T1 n, T2 d) 
{
	return n % d;
}

void test_modulo_concept2()
{
	int n = 9;
	int d = 5;
	std::cout << "using modulo concept terse: " << std::endl;
	std::cout << n << " mod " << d << " = " << modulo_concept2(n, d) << std::endl;
}


int main()
{
	//test_modulo_plain();
	//test_modulo_trait();
	//test_modulo_requires();
	//test_modulo_concept();
	test_modulo_concept2();
	return 0;
}