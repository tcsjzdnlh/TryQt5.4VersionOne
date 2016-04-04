/*
	�¼�(event)  ���� signal,
	event �� signal ��ʵ��,
	
*/

destination:(�� assistant document �в鿴 QEvent)
	qt �¼�ϵͳ ��������
	event �� signal �����ڹ���
	�¼�������
	�Զ����¼�
	�����¼�


// --------------------------------------------------------------

Qt's main event loop (QCoreApplication::exec()) 
fetches native window system events from the event queue, 
translates them into QEvents, 
and sends the translated events to QObjects.
(note:QEvent �� QObject ֮�� ��ת)


// --------------------------------------------------------------

events come from the underlying window system (spontaneous() returns true)



manually send events :
using QCoreApplication::sendEvent() 
and QCoreApplication::postEvent() (spontaneous() returns false)


// --------------------------------------------------------------


QObjects receive events by having their QObject::event() function called. 
The function can be reimplemented in subclasses to customize event handling and add additional event types; 
QWidget::event() is a notable example. By default, 
events are dispatched to event handlers like QObject::timerEvent() and QWidget::mouseMoveEvent(). 
QObject::installEventFilter() allows an object to intercept events destined for another object.




// --------------------------------------------------------------

QEvent:
	1.EventType
	2.flag:	set with accept()   ----- cleared with ignore()
			It is set by default, 
			but don't rely on this as subclasses may choose to clear it in their constructor.