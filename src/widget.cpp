#include "widget.h"
#include "defines.h"

#include <QMessageBox>
#include <QList>

#include <QDesktopWidget>
#include <QApplication>
#include <QMouseEvent>
#include <QMetaType>
#include <QDebug>

Widget::Widget(QWidget *widget) 
	: QWidget(widget)
{
	build();
	configure();
	setConnections();
	setLayouts();
}

void Widget::build() {
	mVLayout = new QVBoxLayout(this);
	mWebView = new WebView(this);
	mShowUrl = new QLabel(this);
}

void Widget::configure() {
	mShowUrl->setStyleSheet("color: black; background-color: #a4bdba; opacity: 0.7; font-size: 30");
	
}


void Widget::setShowUrlGeometry() {
	int x,y,h,w;
	QSize s = size();
	x = 0;
	y = s.height()*0.97;
	w = s.width()*0.5;
	h = s.height()*0.03;
	mShowUrl->setGeometry(x, y, w, h);
}



void Widget::setConnections() {
	connect (mWebView, &WebView::mouseClicked, [&](QMouseEvent *event) {
		mEvents.push_back(event->pos());
	});


	connect (mWebView, &WebView::keyPressed, [&](QString text) {
		mEvents.push_back(text);
	});

	connect (mWebView, &WebView::deletePressed, [&]() {
		if (mEvents.count() > 0 && mEvents.last().type() == QMetaType::QString)
			mEvents.pop_back();
	});

	connect (mWebView, &WebView::enterPressed, [&]() {
		mEvents.push_back(tr("[enter]"));
	});

	connect (mWebView, &WebView::popBack, [&]() -> QString {
		QString r = mEvents.last().value<QString>();
		mEvents.pop_back();
		return r;
	});

	connect (mWebView, &WebView::onCompleted, [&]() {
		emit onCompleted(parseEvents());
	});

	connect (mWebView, &WebView::onShowPressed, [&]() {
		QMessageBox::information(this, "steps", parseEvents());
	});

	connect (mWebView, &WebView::onPTerminalPressed, [&]() {
			qDebug() << parseEvents();
	});

	connect (mWebView, &WebView::urlChanged, [&](QUrl url) {
		QString s = url.toString();
		mShowUrl->setText(s);
		setShowUrlGeometry();
	});

	connect (mWebView, &WebView::onHelp, [&]() {
		QMessageBox::information(this, "help", HELP_MESSAGE); 
	});

	connect (mWebView, &WebView::onExit, [&]() {
		close();
	});

}


void Widget::setLayouts() {
	mVLayout->setMargin(0);
	mVLayout->addWidget(mWebView);
	setLayout(mVLayout);
}





QString Widget::parseSize() {
	QString ret;
	QSize s = size();
	ret = tr("width=%1&height=%2;").arg(s.width()).arg(s.height());
	return ret;
}



QString Widget::parseEvents() {
	QString ret;
	QVariant::Type typeBefore;
	QPoint pos;
	int x = 0;
	ret = mUrl+";"+parseSize();
	for (QVariant event : mEvents) {
		if (event.type() == QMetaType::QPoint) {
			if (typeBefore == QMetaType::QString)
				ret += ";";
			pos = event.toPoint();
			ret += tr("x=%1&y=%2;").arg(pos.x()).arg(pos.y());
		} else {
			if (typeBefore != QMetaType::QString)
				ret += "text=";
			ret += event.toString();
		}
		typeBefore = event.type();
	}

	if (ret[ret.length()-1] == ';')
		ret.remove(ret.length()-1, 1);

	return ret;
}



void Widget::setUrl(QString url) {
	mUrl = url;
	mWebView->load(QUrl(mUrl));
}

