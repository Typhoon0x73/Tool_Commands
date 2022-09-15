#ifndef SIP_ICOMMAND_H_
#define SIP_ICOMMAND_H_

#include <memory>
#include <string_view>

namespace sip
{
	/**
	* @brief �R�}���h���ۃN���X
	*/
	class ICommand
	{
	public:

		/**
		* @brief �f�X�g���N�^
		*/
		virtual ~ICommand() = default;

		/**
		* @brief ���s
		* @return true : ����, false : ���s
		*/
		virtual bool execute() = 0;

		/**
		* @brief ���ɖ߂�
		* @return true : ����, false : ���s
		*/
		virtual bool undo() = 0;

		/**
		* @brief ��蒼��
		* @return true : ����, false : ���s
		*/
		virtual bool redo() = 0;

		/**
		* @brief ���O������̎擾
		* @return ���O������
		*/
		virtual std::string logStr() const = 0;
	};

	// �R�}���h�|�C���^
	using CommandPtr = std::unique_ptr<ICommand>;
}

#endif // !SIP_ICOMMAND_H_
