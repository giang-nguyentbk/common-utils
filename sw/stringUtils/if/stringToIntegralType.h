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
	if(err = std::errc() && ptr == last)
	{
		return res;
	}

	return std::nullopt;
}

} // namespace StringUtils

} // namespace V1

} // namespace CommonUtils