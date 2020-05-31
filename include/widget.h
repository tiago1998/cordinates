#ifndef __WIDGET_H__
#define __WIDGET_H__

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QResizeEvent>
#include <QVariant>
#include <QVector>
#include <QLabel>
#include <QPoint>
#include <QList>

#include "webview.h"

class Widget : public QWidget {
	Q_OBJECT
public:
	Widget(QWidget *widget = nullptr);
	
	void setUrl(QString str);

signals:
	void onCompleted(QString);


private:
	void build();
	void configureSize();
	void configure();
	void setLayouts();
	void setConnections();
	void setShowUrlGeometry();
	
	QPoint scalePos(QPoint pos);
	QString parseSize();
	QString parseEvents();


	QVBoxLayout *mVLayout;
	WebView *mWebView;
	QLabel *mShowUrl;

	QVector<QVariant> mEvents;
	
	QString mUrl;
};


#endif
