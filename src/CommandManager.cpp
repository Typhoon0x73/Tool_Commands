#include "CommandManager.h"

namespace sip
{
	/**
	* @brief コンストラクタ
	*/
	CommandManager::CommandManager()
		: m_ExecuteList{}
		, m_UndoList{}
	{
	}

	/**
	* @brief デストラクタ
	*/
	CommandManager::~CommandManager()
	{
		clear();
	}

	/**
	* @brief コマンドの登録
	* @param command コマンドポインタ
	* @return true : 成功, false : 失敗
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
	* @brief コマンド履歴の削除
	*/
	void CommandManager::clear()
	{
		m_ExecuteList.clear();
		m_UndoList.clear();
	}

	/**
	* @brief 元に戻す
	* @return true : 成功, false : 失敗
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
	* @brief やり直し
	* @return true : 成功, false : 失敗
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
	* @brief 実行コマンドリストの取得
	* @return 実行コマンドリスト
	*/
	const std::list<CommandPtr>& CommandManager::executeList() const
	{
		return m_ExecuteList;
	}

	/**
	* @brief 元に戻すコマンドリストの取得
	* @return 元に戻すコマンドリスト
	*/
	const std::list<CommandPtr>& CommandManager::undoList() const
	{
		return m_UndoList;
	}

	/**
	* @brief コマンド記憶最大数の再設定(def:50)
	* @param capacity コマンド記憶最大数
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