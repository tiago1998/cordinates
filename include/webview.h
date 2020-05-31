#ifndef __WEB_VIEW_H__
#define __WEB_VIEW_H__

#include <QWebView>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPoint>

class WebView : public QWebView {
	Q_OBJECT
public:
	WebView (QWidget *parent=nullptr);

signals:
	void mouseClicked(QMouseEvent*);
	void keyPressed(QString);
	void deletePressed();
	void enterPressed();
	void onShowPressed();
	void onPTerminalPressed();
	void onCompleted();
	QString popBack();
	void onHelp();
	void onExit();


protected:
	void mousePressEvent(QMouseEvent *event) override;
	void keyReleaseEvent(QKeyEvent *event) override;


private:
	void emitKeyShift(QKeyEvent*);
	void onControl();

	bool shift;

};


#endif
