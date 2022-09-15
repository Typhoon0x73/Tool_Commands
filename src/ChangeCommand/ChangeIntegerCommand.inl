#ifndef SIP_CHANGE_INTEGER_COMMAND_H_
#define SIP_CHANGE_INTEGER_COMMAND_H_

#include "ChangeCommand.h"
#include <cstdint>
#include <string>

namespace sip
{

#define ChangeCommandInlineLog_INT(TYPE)                                            \
	template<>																		\
	inline virtual std::string ChangeCommand<TYPE>::logStr() const					\
	{																				\
		if (m_pObject == nullptr)													\
		{																			\
			return "change object is nullptr.";										\
		}																			\
		return (std::to_string(m_prevValue) + " to " + std::to_string(m_value));	\
	}

	using ChangeS8Command  = ChangeCommand<std::int8_t  >;
	using ChangeS16Command = ChangeCommand<std::int16_t >;
	using ChangeS32Command = ChangeCommand<std::int32_t >;
	using ChangeS64Command = ChangeCommand<std::int64_t >;
	using ChangeU8Command  = ChangeCommand<std::uint8_t >;
	using ChangeU16Command = ChangeCommand<std::uint16_t>;
	using ChangeU32Command = ChangeCommand<std::uint32_t>;
	using ChangeU64Command = ChangeCommand<std::uint64_t>;

	ChangeCommandInlineDefault(std::int8_t  )
	ChangeCommandInlineDefault(std::int16_t )
	ChangeCommandInlineDefault(std::int32_t )
	ChangeCommandInlineDefault(std::int64_t )
	ChangeCommandInlineDefault(std::uint8_t )
	ChangeCommandInlineDefault(std::uint16_t)
	ChangeCommandInlineDefault(std::uint32_t)
	ChangeCommandInlineDefault(std::uint64_t)
	ChangeCommandInlineLog_INT(std::int8_t  )
	ChangeCommandInlineLog_INT(std::int16_t )
	ChangeCommandInlineLog_INT(std::int32_t )
	ChangeCommandInlineLog_INT(std::int64_t )
	ChangeCommandInlineLog_INT(std::uint8_t )
	ChangeCommandInlineLog_INT(std::uint16_t)
	ChangeCommandInlineLog_INT(std::uint32_t)
	ChangeCommandInlineLog_INT(std::uint64_t)
}

#endif // !SIP_CHANGE_INTEGER_COMMAND_H_
