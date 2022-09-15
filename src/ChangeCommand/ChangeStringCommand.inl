#ifndef SIP_CHANGE_STRING_COMMAND_H_
#define SIP_CHANGE_STRING_COMMAND_H_

#include "ChangeCommand.h"
#include <string>

namespace sip
{
	using ChangeStringCommand = ChangeCommand<std::string>;
	
	ChangeCommandInlineDefault(std::string)

	template<>
	inline std::string ChangeStringCommand::logStr() const
	{
		if (m_pObject == nullptr)
		{
			return "change object is nullptr.";
		}
		return (m_prevValue + " to " + m_value);
	}
}

#endif // !SIP_CHANGE_STRING_COMMAND_H_