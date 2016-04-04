#ifndef _xfs_HugeEnumToString_h_
#define _xfs_HugeEnumToString_h_

#include <QtCore/QMultiMap>
#include <QtCore/QString>

// ��ת���� enum �����﷨��ȷ��CHugeEnumToString �������﷨����
class CHugeEnumToString
{
public:
	typedef QMultiMap<int, QString> EnumString;
public:
	CHugeEnumToString() = default;
	
	CHugeEnumToString( const QString &_strEnum, bool _bIsFn = true ); // _strEnum ���ݾ��� enum�Ķ���

	EnumString GetEnumString() const;
	EnumString GetEnumString( const QString &_strEnum, bool _bIsFn = true );

private:
	void Parse( const QString &_strEnum );

private:
	EnumString		m_EnumString;
};



#endif