#ifndef _xfs_Book_h_
#define _xfs_Book_h_

#include <QtCore/QObject>

namespace test_qt_assistance_system
{
	namespace mac_Q_ENUMS
	{
		class CBook : public QObject
		{
			//Q_GADGET
			Q_OBJECT
			Q_ENUMS( EWeek )

		public:
			enum EWeek{ e_monday, e_tuesday, e_wednesday, e_friday, e_saturday, e_sunday };
		};



	}
}


#endif