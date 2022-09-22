#include <sstream>
#include <stdexcept>
#include <string>

class BaseGenerator {
public:  // TODO
	BaseGenerator() = default;  // TODO
	~BaseGenerator() = default;  // TODO

	template<typename T>
	inline std::string stringify(T t)
	{
		std::ostringstream ss;
		if (!(ss << t))  { throw std::runtime_error("error"); }  // TODO: move into error handler
		return ss.str();
	}
};
