#ifndef _xfs_XfsStyle_h_
#define _xfs_XfsStyle_h_

#include <QtWidgets/QCommonStyle>

class CXfsStyle : public QCommonStyle
{
	Q_OBJECT
public:
	enum EGeometry { e_slider_height = 27, e_slider_length = 13 };
public:
	CXfsStyle();

	void polish( QPalette &_palette ) override;
	void polish( QWidget *_pWidget ) override;
	void unpolish( QWidget *_pWidget ) override;

	void drawComplexControl( ComplexControl _cc, const QStyleOptionComplex *_pOption,
							QPainter *_pPainter, const QWidget *_pWidget = nullptr ) const override;

	void drawControl( ControlElement _ce, const QStyleOption *_pOption,
						QPainter *_pPainter, const QWidget *_pWidget = nullptr ) const override;

	void drawPrimitive( PrimitiveElement _pe, const QStyleOption *_pOption,
						QPainter *_pPainter, const QWidget *_pWidget = nullptr ) const override;

	QRect subElementRect( SubElement _se, const QStyleOption *_pOption = nullptr,
							const QWidget *_pWidget = nullptr ) const override;
	QRect subControlRect( ComplexControl _cc, const QStyleOptionComplex *_pOption,
						  SubControl _sc, const QWidget *_pWidget = nullptr ) const override;

	int pixelMetric( PixelMetric _pm, const QStyleOption *_pOption = nullptr,
					const QWidget *_pWidget = nullptr ) const override;

	int styleHint( StyleHint _sh, const QStyleOption *_pOption = nullptr,
					const QWidget *_pWidget = nullptr, QStyleHintReturn *_pSHRet = nullptr ) const override;


	QSize sizeFromContents( ContentsType _ct, const QStyleOption *_pOption, 
							const QSize &_size, const QWidget *_pWidget = nullptr ) const override;

protected:
	void DrawHoverRect( QPainter *_pPainter, const QRect &_hr ) const;
};


#endif