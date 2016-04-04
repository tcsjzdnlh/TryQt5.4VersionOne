#ifndef QWIDGET_H
#define QWIDGET_H

#include <QtGui/qwindowdefs.h>
#include <QtCore/qobject.h>
#include <QtCore/qmargins.h>
#include <QtGui/qpaintdevice.h>
#include <QtGui/qpalette.h>
#include <QtGui/qfont.h>
#include <QtGui/qfontmetrics.h>
#include <QtGui/qfontinfo.h>
#include <QtWidgets/qsizepolicy.h>
#include <QtGui/qregion.h>
#include <QtGui/qbrush.h>
#include <QtGui/qcursor.h>
#include <QtGui/qkeysequence.h>

#ifdef QT_INCLUDE_COMPAT
#include <QtGui/qevent.h>
#endif

QT_BEGIN_NAMESPACE


class QLayout;
class QWSRegionManager;
class QStyle;
class QAction;
class QVariant;
class QWindow;

class QIcon;
class QBackingStore;
class QPlatformWindow;
class QLocale;
class QGraphicsProxyWidget;
class QGraphicsEffect;
class QRasterWindowSurface;
class QUnifiedToolbarSurface;
class QPixmap;

class QWidgetData
{
public:
    WId winid;
    uint widget_attributes;
    Qt::WindowFlags window_flags;
    uint window_state : 4;
    uint focus_policy : 4;
    uint sizehint_forced :1;
    uint is_closing :1;
    uint in_show : 1;
    uint in_set_window_state : 1;
    mutable uint fstrut_dirty : 1;
    uint context_menu_policy : 3;
    uint window_modality : 2;
    uint in_destructor : 1;
    uint unused : 13;
    QRect crect;
    mutable QPalette pal;
    QFont fnt;
    QRect wrect;
};

class QWidgetPrivate;

class Q_WIDGETS_EXPORT QWidget : public QObject, public QPaintDevice
{
 
 
public:
    enum RenderFlag {
        DrawWindowBackground = 0x1,
        DrawChildren = 0x2,
        IgnoreMask = 0x4
    };
    Q_DECLARE_FLAGS(RenderFlags, RenderFlag)

    explicit QWidget(QWidget* parent = 0, Qt::WindowFlags f = 0);
    ~QWidget();


    // GUI style setting
    QStyle *style() const;
    void setStyle(QStyle *);



    // Widget coordinates

public:
    QRect frameGeometry() const;
    const QRect &geometry() const;
    QRect normalGeometry() const;

    int x() const;
    int y() const;
    QPoint pos() const;
    QSize frameSize() const;
    QSize size() const;
    inline int width() const;
    inline int height() const;
    inline QRect rect() const;
    QRect childrenRect() const;
    QRegion childrenRegion() const;



#ifdef Q_QDOC
    void setupUi(QWidget *widget);
#endif


    // Widget coordinate mapping



    // Widget appearance functions


    void setMask(const QBitmap &);
    void setMask(const QRegion &);
    QRegion mask() const;
    void clearMask();

    void render(QPaintDevice *target, const QPoint &targetOffset = QPoint(),
                const QRegion &sourceRegion = QRegion(),
                RenderFlags renderFlags = RenderFlags(DrawWindowBackground | DrawChildren));

    void render(QPainter *painter, const QPoint &targetOffset = QPoint(),
                const QRegion &sourceRegion = QRegion(),
                RenderFlags renderFlags = RenderFlags(DrawWindowBackground | DrawChildren));

    Q_INVOKABLE QPixmap grab(const QRect &rectangle = QRect(QPoint(0, 0), QSize(-1, -1)));

#ifndef QT_NO_GRAPHICSEFFECT
    QGraphicsEffect *graphicsEffect() const;
    void setGraphicsEffect(QGraphicsEffect *effect);
#endif //QT_NO_GRAPHICSEFFECT




#ifndef QT_NO_STYLE_STYLESHEET
    void setStyleSheet(const QString& styleSheet);
#endif
public:
#ifndef QT_NO_STYLE_STYLESHEET
    QString styleSheet() const;
#endif




    // Update/refresh functions
    inline bool updatesEnabled() const;
    void setUpdatesEnabled(bool enable);

#ifndef QT_NO_GRAPHICSVIEW
    QGraphicsProxyWidget *graphicsProxyWidget() const;
#endif

public Q_SLOTS:
    void update();
    void repaint();

public:
    inline void update(int x, int y, int w, int h);
    void update(const QRect&);
    void update(const QRegion&);

    void repaint(int x, int y, int w, int h);
    void repaint(const QRect &);
    void repaint(const QRegion &);



public:




    QRegion visibleRegion() const;

    void setContentsMargins(int left, int top, int right, int bottom);
    void setContentsMargins(const QMargins &margins);
    void getContentsMargins(int *left, int *top, int *right, int *bottom) const;
    QMargins contentsMargins() const;

    QRect contentsRect() const;



    void setAttribute(Qt::WidgetAttribute, bool on = true);
    inline bool testAttribute(Qt::WidgetAttribute) const;

    QPaintEngine *paintEngine() const;

    void ensurePolished() const;

    bool isAncestorOf(const QWidget *child) const;



    bool autoFillBackground() const;
    void setAutoFillBackground(bool enabled);

    QBackingStore *backingStore() const;

    QWindow *windowHandle() const;

    static QWidget *createWindowContainer(QWindow *window, QWidget *parent=0, Qt::WindowFlags flags=0);

    friend class QDesktopScreenWidget;




    int metric(PaintDeviceMetric) const;
    void initPainter(QPainter *painter) const;
    QPaintDevice *redirected(QPoint *offset) const;
    QPainter *sharedPainter() const;

    virtual void inputMethodEvent(QInputMethodEvent *);
public:
    virtual QVariant inputMethodQuery(Qt::InputMethodQuery) const;

    Qt::InputMethodHints inputMethodHints() const;
    void setInputMethodHints(Qt::InputMethodHints hints);

protected Q_SLOTS:
    void updateMicroFocus();
protected:

    void create(WId = 0, bool initializeWindow = true,
                         bool destroyOldWindow = true);
    void destroy(bool destroyWindow = true,
                 bool destroySubWindows = true);

    virtual bool focusNextPrevChild(bool next);
    inline bool focusNextChild() { return focusNextPrevChild(true); }
    inline bool focusPreviousChild() { return focusNextPrevChild(false); }

protected:
    QWidget(QWidgetPrivate &d, QWidget* parent, Qt::WindowFlags f);
private:
    void setBackingStore(QBackingStore *store);

    bool testAttribute_helper(Qt::WidgetAttribute) const;

    QLayout *takeLayout();


#ifdef Q_OS_MAC
    friend bool qt_mac_is_metal(const QWidget *w);
#endif
    friend Q_WIDGETS_EXPORT QWidgetData *qt_qwidget_data(QWidget *widget);
    friend Q_WIDGETS_EXPORT QWidgetPrivate *qt_widget_private(QWidget *widget);

private:
    Q_DISABLE_COPY(QWidget)
    Q_PRIVATE_SLOT(d_func(), void _q_showIfNotHidden())

    QWidgetData *data;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(QWidget::RenderFlags)

