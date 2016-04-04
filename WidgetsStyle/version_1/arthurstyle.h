
#ifndef ARTHURSTYLE_H
#define ARTHURSTYLE_H

#include <QCommonStyle>

QT_USE_NAMESPACE

class ArthurStyle : public QCommonStyle
{
public:
    ArthurStyle();

    void drawHoverRect(QPainter *painter, const QRect &rect) const;

    void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
                       QPainter *painter, const QWidget *widget = 0) const Q_DECL_OVERRIDE;
    void drawControl(ControlElement element, const QStyleOption *option,
                     QPainter *painter, const QWidget *widget) const Q_DECL_OVERRIDE;
    void drawComplexControl(ComplexControl control, const QStyleOptionComplex *option,
                            QPainter *painter, const QWidget *widget) const Q_DECL_OVERRIDE;
    QSize sizeFromContents(ContentsType type, const QStyleOption *option,
                           const QSize &size, const QWidget *widget) const Q_DECL_OVERRIDE;

    QRect subElementRect(SubElement element, const QStyleOption *option, const QWidget *widget) const Q_DECL_OVERRIDE;
    QRect subControlRect(ComplexControl cc, const QStyleOptionComplex *opt,
                         SubControl sc, const QWidget *widget) const Q_DECL_OVERRIDE;

    int pixelMetric(PixelMetric metric, const QStyleOption *option, const QWidget *widget) const Q_DECL_OVERRIDE;

    void polish(QPalette &palette) Q_DECL_OVERRIDE;
    void polish(QWidget *widget) Q_DECL_OVERRIDE;
    void unpolish(QWidget *widget) Q_DECL_OVERRIDE;
};

#endif
