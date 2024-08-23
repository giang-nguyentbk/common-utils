#include <iostream>
#include <string>

#include "enumUtils.h"

using namespace CommonUtils::V1::EnumUtils;

enum class CommandResultCodeEnumRaw
{
	CMD_ERROR = 0x1,
	CMD_INVALID_ARGUMENTS = 0x2,
	CMD_SUCCESS = 0x3,
	UNDEF = 0xFF
};

class CommandResultCodeEnum : public EnumType<CommandResultCodeEnumRaw>
{
public:
	explicit CommandResultCodeEnum(const CommandResultCodeEnumRaw& raw) : EnumType<CommandResultCodeEnumRaw>(raw) {}

	std::string toString() const override
	{
		switch (getValue())
		{
		case CommandResultCodeEnumRaw::CMD_ERROR:
			return "CMD_ERROR";

		case CommandResultCodeEnumRaw::CMD_INVALID_ARGUMENTS:
			return "CMD_INVALID_ARGUMENTS";

		case CommandResultCodeEnumRaw::CMD_SUCCESS:
			return "CMD_SUCCESS";

		default:
			return "Unknown EnumType: " + toS32();
		}
	}

	CommandResultCodeEnumRaw convertToEnum(const std::string& str)
	{
		if(str == "CMD_ERROR")
		{
			return CommandResultCodeEnumRaw::CMD_ERROR;
		}
		else if(str == "CMD_INVALID_ARGUMENTS")
		{
			return CommandResultCodeEnumRaw::CMD_INVALID_ARGUMENTS;
		}
		else if(str == "CMD_SUCCESS")
		{
			return CommandResultCodeEnumRaw::CMD_SUCCESS;
		}

		return CommandResultCodeEnumRaw::UNDEF;
	}
};

int main()
{
	CommandResultCodeEnum cmdResult(CommandResultCodeEnumRaw::CMD_ERROR);
	CommandResultCodeEnum otherCmdResult(CommandResultCodeEnumRaw::CMD_SUCCESS);

	std::cout << "cmdResult.toString(): " << cmdResult.toString() << std::endl;
	std::cout << "cmdResult.toS32(): " << cmdResult.toS32() << std::endl;
	std::cout << "cmdResult.toU32(): " << cmdResult.toU32() << std::endl;
	if(cmdResult != otherCmdResult)
	{
		std::cout << "cmdResult.compare: different!\n";
	}
	else
	{
		std::cout << "cmdResult.compare: same!\n";
	}

	if(cmdResult.convertToEnum("CMD_INVALID_ARGUMENTS") == CommandResultCodeEnumRaw::CMD_INVALID_ARGUMENTS)
	{
		std::cout << "cmdResult.convertToEnum(CMD_INVALID_ARGUMENTS): true!\n";
	}
	else
	{
		std::cout << "cmdResult.convertToEnum(CMD_INVALID_ARGUMENTS): false!\n";
	}
	
	cmdResult = otherCmdResult;
	std::cout << "cmdResult.copy_assignment: " << cmdResult.toString() << std::endl;

	cmdResult = CommandResultCodeEnum(CommandResultCodeEnumRaw::CMD_INVALID_ARGUMENTS);
	std::cout << "cmdResult.move_assignment: " << cmdResult.toString() << std::endl;

	return 0;
}