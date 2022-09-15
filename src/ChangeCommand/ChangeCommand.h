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
		* @brief コンストラクタ
		* @param obj 変更対象
		* @param val 変更後値
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
		* @brief デストラクタ
		*/
		virtual ~ChangeCommand() = default;

		/**
		* @brief 実行
		* @return true : 成功, false : 失敗
		*/
		virtual bool execute() override
		{
			return false;
		}

		/**
		* @brief 元に戻す
		* @return true : 成功, false : 失敗
		*/
		virtual bool undo() override
		{
			return false;
		}

		/**
		* @brief やり直し
		* @return true : 成功, false : 失敗
		*/
		virtual bool redo() override
		{
			return false;
		}

		/**
		* @brief ログ文字列の取得
		* @return ログ文字列
		*/
		virtual std::string logStr() const override
		{
			return "not found template.";
		}

	private:

		T  m_prevValue;  //!< 変更前
		T  m_value;      //!< 変更後
		T* m_pObject;    //!< 変更対象
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
