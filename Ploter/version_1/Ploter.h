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
	// --- ����ϵ
	void SetPloterSettings( const CPloterSettings &_s );

	// ---�������ݵ�
	void SetCurveData( int _id, QVector<QPointF> &_data );
	void ClearCurve( int _id );

private:
	void InitCurveData( const QString &_fn );
	void InitPloterSetting();

public:
	// ��  layout �õ�
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

	// ��ͬ���ż��������ϵͳ
	QVector<CPloterSettings>		m_Settings;
	int								m_CurrentSetting;
	

	// ����ͼ
	QMap<int, QVector<QPointF>>		m_Curves;

	// ���Ű�ť
	QToolButton						*m_pZoomIn;
	QToolButton						*m_pZoomOut;

	// ѡ�п�
	bool							m_bRubberBandIsShow;
	QRect							m_RubberRect;

	// ��̨��ͼ������
	QPixmap							m_PloterBackBuffer;
};


#endif