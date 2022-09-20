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
		* @brief コンストラクタ
		* @param v1 入れ替え対象１
		* @param v2 入れ替え対象２
		*/
		explicit SwapCommand(T* v1, T* v2)
			: m_pValue1(v1)
			, m_pValue2(v2)
		{
		}

		/**
		* @brief デストラクタ
		*/
		virtual ~SwapCommand() = default;

		/**
		* @brief 実行
		* @return true : 成功, false : 失敗
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
		* @brief 元に戻す
		* @return true : 成功, false : 失敗
		*/
		virtual bool undo() override
		{
			return execute();
		}

		/**
		* @brief やり直し
		* @return true : 成功, false : 失敗
		*/
		virtual bool redo() override
		{
			return execute();
		}

		/**
		* @brief ログ文字列の取得
		* @return ログ文字列
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
