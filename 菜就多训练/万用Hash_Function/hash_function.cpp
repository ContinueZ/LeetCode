#include<string>
using namespace std;
template<typename T>
inline void hash_combine(size_t& seed, const T& val)
{
	seed ^= hash<T>()(val) +
		0x9e3779b9 +
		(seed << 6) +
		(seed >> 2);
}

template<typename T>
inline void hash_val(size_t& seed, const T& val)
{
	hash_combine(seed, val);
}

template<typename T, typename... Types>
inline void hash_val(size_t& seed, const T& val, const Types&... args)
{
	hash_combine(seed, val);
	hash_val(seed, args...);
}

template<typename... Types>
inline size_t hash_val(const Types&... arg)
{
	size_t seed = 0;
	hash_val(seed, args...);
	return seed;
}



class Customer {
public:
	string fname;
	string lname;
	int no;
};
class CustomerHash {
public:
	std::size_t operator()(const Customer& c)const {
		return hash_val(c.fname, c.lname, c.no);
	}
};