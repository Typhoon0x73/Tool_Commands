#ifndef SIP_SWAP_COMMAND_H_
#define SIP_SWAP_COMMAND_H_
#include "../ICommand.h"

namespace sip
{
	template< typename T >
	class SwapCommand : public ICommand
	{
	public:
		/**
		* @brief �R���X�g���N�^
		* @param v1 ����ւ��ΏۂP
		* @param v2 ����ւ��ΏۂQ
		*/
		explicit SwapCommand(T* v1, T* v2)
			: m_pValue1(v1)
			, m_pValue2(v2)
		{
		}

		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~SwapCommand() = default;

		/**
		* @brief ���s
		* @return true : ����, false : ���s
		*/
		virtual bool execute() override
		{
			if (!(m_pValue1 && m_pValue2))
			{
				return false;
			}
			std::swap(*m_pValue1, *m_pValue2);
			return true;
		}

		/**
		* @brief ���ɖ߂�
		* @return true : ����, false : ���s
		*/
		virtual bool undo() override
		{
			return execute();
		}

		/**
		* @brief ��蒼��
		* @return true : ����, false : ���s
		*/
		virtual bool redo() override
		{
			return execute();
		}

		/**
		* @brief ���O������̎擾
		* @return ���O������
		*/
		virtual std::string logStr() const override
		{
			return "swaped.";
		}

	private:

		T* m_pValue1{ nullptr };
		T* m_pValue2{ nullptr };
	};
}

#endif // !SIP_SWAP_COMMAND_H_
