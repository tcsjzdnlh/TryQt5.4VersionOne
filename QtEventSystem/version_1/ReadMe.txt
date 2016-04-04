/*
	事件(event)  不是 signal,
	event 是 signal 的实现,
	
*/

destination:(从 assistant document 中查看 QEvent)
	qt 事件系统 运行流程
	event 与 signal 的内在关联
	事件过滤器
	自定义事件
	常用事件


// --------------------------------------------------------------

Qt's main event loop (QCoreApplication::exec()) 
fetches native window system events from the event queue, 
translates them into QEvents, 
and sends the translated events to QObjects.
(note:QEvent 在 QObject 之间 流转)


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