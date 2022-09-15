#include "CommandManager.h"

namespace sip
{
	/**
	* @brief �R���X�g���N�^
	*/
	CommandManager::CommandManager()
		: m_ExecuteList{}
		, m_UndoList{}
	{
	}

	/**
	* @brief �f�X�g���N�^
	*/
	CommandManager::~CommandManager()
	{
		clear();
	}

	/**
	* @brief �R�}���h�̓o�^
	* @param command �R�}���h�|�C���^
	* @return true : ����, false : ���s
	*/
	bool CommandManager::regist(CommandPtr&& command)
	{
		if (!command->execute())
		{
			return false;
		}
		m_ExecuteList.push_back(std::move(command));
		m_UndoList.clear();
		while (m_ExecuteList.size() > m_Capacity)
		{
			m_ExecuteList.pop_front();
		}
		return true;
	}

	/**
	* @brief �R�}���h�����̍폜
	*/
	void CommandManager::clear()
	{
		m_ExecuteList.clear();
		m_UndoList.clear();
	}

	/**
	* @brief ���ɖ߂�
	* @return true : ����, false : ���s
	*/
	bool CommandManager::undo()
	{
		if (m_ExecuteList.size() == 0)
		{
			return false;
		}
		auto command = std::move(m_ExecuteList.back());
		m_ExecuteList.pop_back();
		if (!command->undo())
		{
			return false;
		}
		m_UndoList.push_back(std::move(command));
		return true;
	}

	/**
	* @brief ��蒼��
	* @return true : ����, false : ���s
	*/
	bool CommandManager::redo()
	{
		if (m_UndoList.size() == 0)
		{
			return false;
		}
		auto command = std::move(m_UndoList.back());
		m_UndoList.pop_back();
		return regist(std::move(command));
	}

	/**
	* @brief ���s�R�}���h���X�g�̎擾
	* @return ���s�R�}���h���X�g
	*/
	const std::list<CommandPtr>& CommandManager::executeList() const
	{
		return m_ExecuteList;
	}

	/**
	* @brief ���ɖ߂��R�}���h���X�g�̎擾
	* @return ���ɖ߂��R�}���h���X�g
	*/
	const std::list<CommandPtr>& CommandManager::undoList() const
	{
		return m_UndoList;
	}

	/**
	* @brief �R�}���h�L���ő吔�̍Đݒ�(def:50)
	* @param capacity �R�}���h�L���ő吔
	*/
	void CommandManager::setExecuteCommandCapacity(std::size_t capacity)
	{
		m_Capacity = capacity;
		while (m_ExecuteList.size() > m_Capacity)
		{
			m_ExecuteList.pop_front();
		}
	}
}