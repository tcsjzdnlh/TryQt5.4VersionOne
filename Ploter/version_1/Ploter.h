#ifndef _xfs_Ploter_h_
#define _xfs_Ploter_h_

#include <QtWidgets/QWidget>
#include <QtCore/QMap>
#include <QtCore/QVector>
#include <QtCore/QPointF>
#include <QtCore/QRect>
#include <QtWidgets/QToolButton>
#include <QtGui/QPixmap>
#include "PloterSettings.h"


class CPloter : public QWidget
{
	Q_OBJECT
public:
	CPloter( QWidget *_pParent = nullptr );
	
	


public:
	// --- 坐标系
	void SetPloterSettings( const CPloterSettings &_s );

	// ---曲线数据点
	void SetCurveData( int _id, QVector<QPointF> &_data );
	void ClearCurve( int _id );

private:
	void InitCurveData( const QString &_fn );
	void InitPloterSetting();

public:
	// 给  layout 用的
	QSize minimumSizeHint() const;
	QSize sizeHint() const;


private:
	// ---
	void UpdateRubberBandRegion();

	// ---
	void DrawGrid( QPainter *_pPainter );
	void DrawCurves( QPainter *_pPainter );

	// ---
	void RefreshOffScreenImage();

protected:
	// ---
	void paintEvent( QPaintEvent *_pEvent );

	// ---
	void resizeEvent( QResizeEvent *_pEvent );

	// ---
	void keyPressEvent( QKeyEvent *_pEvent );

	// ---
	void mousePressEvent( QMouseEvent *_pEvent );
	void mouseMoveEvent( QMouseEvent *_pEvent );
	void mouseReleaseEvent( QMouseEvent *_pEvent );

	// ---
	void wheelEvent( QWheelEvent *_pEvent );

public slots :
	void ZoomIn();
	void ZoomOut();


private:
	enum { eMargin = 50 };

	// 不同缩放级别的坐标系统
	QVector<CPloterSettings>		m_Settings;
	int								m_CurrentSetting;
	

	// 曲线图
	QMap<int, QVector<QPointF>>		m_Curves;

	// 缩放按钮
	QToolButton						*m_pZoomIn;
	QToolButton						*m_pZoomOut;

	// 选中框
	bool							m_bRubberBandIsShow;
	QRect							m_RubberRect;

	// 后台绘图缓冲区
	QPixmap							m_PloterBackBuffer;
};


#endif