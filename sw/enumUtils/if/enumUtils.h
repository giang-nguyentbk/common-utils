/*
*                                                      _____  _________________       
* ___________________ __________ ________________      __  / / /_  /___(_)__  /_______
* _  ___/  __ \_  __ `__ \_  __ `__ \  __ \_  __ \     _  / / /_  __/_  /__  /__  ___/
* / /__ / /_/ /  / / / / /  / / / / / /_/ /  / / /     / /_/ / / /_ _  / _  / _(__  ) 
* \___/ \____//_/ /_/ /_//_/ /_/ /_/\____//_/ /_/      \____/  \__/ /_/  /_/  /____/  
*                                                                                     
*/

#pragma once

#include <cstdint>
#include <string>

namespace CommonUtils
{

namespace V1
{

namespace EnumUtils
{

template<typename E>
constexpr auto toUnderlyingType(E e) -> typename std::underlying_type<E>::type 
{
   return static_cast<typename std::underlying_type<E>::type>(e);
}

template<typename T>
class EnumType
{
public:
	EnumType(const T& t) : m_value(t) {}
	EnumType(const EnumType& t) : m_value(t.m_value) {}
	virtual ~EnumType() = default;
	
	EnumType& operator=(const EnumType& other)
	{
		if(this != &other)
		{
			this->m_value = other.m_value;
		}

		return *this;
	}

	EnumType& operator=(EnumType&& other) noexcept = default;

	operator T() const
	{
		return m_value;
	}

	T getRawEnum() const
	{
		return m_value;
	}

	void set(const T& newValue)
	{
		m_value = newValue;
	}

	int32_t toS32() const
	{
		return static_cast<int32_t>(m_value);
	}

	uint32_t toU32() const
	{
		return static_cast<uint32_t>(m_value);
	}

	virtual bool operator==(const EnumType<T>& t) const
	{
		return t.m_value == this->m_value;
	}

	// Your own EnumClass should be inherited and define this toString() function
	virtual std::string toString() const = 0;

private:
	T m_value;

};


} // namespace EnumUtils

} // namespace V1

} // namespace CommonUtils