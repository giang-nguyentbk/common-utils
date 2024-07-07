/*
*                                                      _____  _________________       
* ___________________ __________ ________________      __  / / /_  /___(_)__  /_______
* _  ___/  __ \_  __ `__ \_  __ `__ \  __ \_  __ \     _  / / /_  __/_  /__  /__  ___/
* / /__ / /_/ /  / / / / /  / / / / / /_/ /  / / /     / /_/ / / /_ _  / _  / _(__  ) 
* \___/ \____//_/ /_/ /_//_/ /_/ /_/\____//_/ /_/      \____/  \__/ /_/  /_/  /____/  
*                                                                                     
*/

#pragma once

#include <optional>
#include <string>
#include <charconv>

#include <cstring>
#include <sstream>
#include <utility>
// #include <initializer_list>
#include <traceIf.h>

namespace CommonUtils
{

namespace V1
{

namespace StringUtils
{

template<typename T>
std::optional<T> stringToIntegralType(const std::string& str)
{
	static_assert(std::is_integral<T>::value, "expected data type must be an integral type!");
	T res;

	std::string strCpy {str};
	if(str[0] == '+')
	{
		strCpy = str.substr(1);
	}
	const char* last = strCpy.data() + strCpy.size();
	auto [ptr, err] { std::from_chars(strCpy.data(), last, res)};
	if(err == std::errc() && ptr == last)
	{
		return res;
	}

	return std::nullopt;
}

template<typename ... T>
std::string STR(T&& ... args)
{
    std::stringstream ss;
    
    (void)(ss << ... << std::forward<T>(args));
    
    /* Alternative way */
    // (void)std::initializer_list<bool> {(ss << args)...};

    return ss.str();
}

#define SSTR(...) (STR(__VA_ARGS__)).c_str()


} // namespace StringUtils

} // namespace V1

} // namespace CommonUtils