#ifndef SIP_CHANGE_COMMAND_H_
#define SIP_CHANGE_COMMAND_H_
#include "../ICommand.h"

namespace sip
{
	template < typename T >
	class ChangeCommand : public ICommand
	{
	public:
		/**
		* @brief �R���X�g���N�^
		* @param obj �ύX�Ώ�
		* @param val �ύX��l
		*/
		explicit ChangeCommand(T* obj, const T& val)
			: m_pObject{ obj }
			, m_value{ val }
			, m_prevValue{}
		{
			if (m_pObject)
			{
				m_prevValue = *m_pObject;
			}
		}

		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~ChangeCommand() = default;

		/**
		* @brief ���s
		* @return true : ����, false : ���s
		*/
		virtual bool execute() override
		{
			return false;
		}

		/**
		* @brief ���ɖ߂�
		* @return true : ����, false : ���s
		*/
		virtual bool undo() override
		{
			return false;
		}

		/**
		* @brief ��蒼��
		* @return true : ����, false : ���s
		*/
		virtual bool redo() override
		{
			return false;
		}

		/**
		* @brief ���O������̎擾
		* @return ���O������
		*/
		virtual std::string logStr() const override
		{
			return "not found template.";
		}

	private:

		T  m_prevValue;  //!< �ύX�O
		T  m_value;      //!< �ύX��
		T* m_pObject;    //!< �ύX�Ώ�
	};


#define ChangeCommandInlineDefault(TYPE)                 \
	template <>											 \
	inline virtual bool ChangeCommand<TYPE>::execute()	 \
	{													 \
		if (m_pObject == nullptr)						 \
		{												 \
			return false;								 \
		}												 \
		*m_pObject = m_value;							 \
		return true;									 \
	}													 \
														 \
	template <>											 \
	inline virtual bool ChangeCommand<TYPE>::undo()		 \
	{													 \
		if (m_pObject == nullptr)						 \
		{												 \
			return false;								 \
		}												 \
		*m_pObject = m_prevValue;						 \
		return true;									 \
	}													 \
														 \
	template <>											 \
	inline virtual bool ChangeCommand<TYPE>::redo()      \
	{													 \
		return execute();								 \
	}													 
}

// INLINE
#include "ChangeStringCommand.inl"
#include "ChangeIntegerCommand.inl"

#endif // !SIP_CHANGE_COMMAND_H_
