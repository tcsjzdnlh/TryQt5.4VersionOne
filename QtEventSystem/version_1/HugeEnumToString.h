#ifndef _xfs_HugeEnumToString_h_
#define _xfs_HugeEnumToString_h_

#include <QtCore/QMultiMap>
#include <QtCore/QString>

// 受转换的 enum 必须语法正确，CHugeEnumToString 不负责语法问题
class CHugeEnumToString
{
public:
	typedef QMultiMap<int, QString> EnumString;
public:
	CHugeEnumToString() = default;
	
	CHugeEnumToString( const QString &_strEnum, bool _bIsFn = true ); // _strEnum 内容就是 enum的定义

	EnumString GetEnumString() const;
	EnumString GetEnumString( const QString &_strEnum, bool _bIsFn = true );

private:
	void Parse( const QString &_strEnum );

private:
	EnumString		m_EnumString;
};



#endif