#include "webview.h"

#include <QDebug>

WebView::WebView(QWidget *parent)
	: QWebView(parent)
{

	shift = false;
}


void WebView::mousePressEvent(QMouseEvent *event) {
	qDebug() << tr("new click at x=%1 y=%2").
		arg(event->pos().x()).arg(event->pos().y());


	emit mouseClicked(event);
	mouseReleaseEvent(event);
}


void WebView::keyReleaseEvent(QKeyEvent *event) {
	qDebug() << tr("key pressed: %1 -> %2").arg(event->key()).arg(event->text());

	switch (event->key()) {
		case Qt::Key_Backspace:
			emit deletePressed();
			break;
		case Qt::Key_Return:
			emit enterPressed();
			break;
		case Qt::Key_Shift:
			shift = true;
			break;
		case Qt::Key_Control:
			onControl();
			break;
		default:
			
			if (shift) {
				emitKeyShift(event);
				shift = false;
			} else if ((event->key() >= 0x20 && event->key() <= 0x5d)
			|| (event->key() == 0x2022)
			|| (event->key() == 0x221a)
			|| (event->key() == 0x2122)
			|| (event->key() == 0x2713)
			|| (event->key() == 0x2206)
			|| (event->key() == 0x20ac)
			|| (event->key() == 0x3a0)
			|| (event->key() == 0x2e)
			|| (event->key() == 0xf7)
			|| (event->key() == 0xd7)
			|| (event->key() == 0x60)
			|| (event->key() == 0xa2)
			|| (event->key() == 0xa3)
			|| (event->key() == 0xa5)
			|| (event->key() == 0xa9)
			|| (event->key() == 0xae)
			|| (event->key() == 0xb0)
			|| (event->key() == 0xb6))
				emit keyPressed(event->text());
	
		}

	event->accept();
}


void WebView::emitKeyShift(QKeyEvent *event) {

	switch (event->key()) {
		case Qt::Key_1:
			emit keyPressed("!");
			break;
		case Qt::Key_2:
			emit keyPressed("@");
			break;
		case Qt::Key_3:
			emit keyPressed("#");
			break;
		case Qt::Key_4:
			emit keyPressed("$");
			break;
		case Qt::Key_5:
			emit keyPressed("%");
			break;
		case Qt::Key_6:
			emit keyPressed("^");
			break;
		case Qt::Key_7:
			emit keyPressed("&");
			break;	
		case Qt::Key_8:
			emit keyPressed("*");
			break;
		case Qt::Key_9:
			emit keyPressed("(");
			break;
		case Qt::Key_0:
			emit keyPressed(")");
			break;
		case Qt::Key_Equal:
			emit keyPressed("+");
			break;
		case Qt::Key_Minus:
			emit keyPressed("_");
			break;
		case Qt::Key_Apostrophe:
			emit keyPressed("\"");
			break;
		case Qt::Key_Semicolon:
			emit keyPressed(":");
			break;
		case Qt::Key_Slash:
			emit keyPressed("?");
			break;
		case Qt::Key_QuoteLeft:
			emit keyPressed("~");
			break;
		case Qt::Key_Backslash:
			emit keyPressed("|");
			break;
		case Qt::Key_BracketLeft:
			emit keyPressed("{");
			break;
		case Qt::Key_BracketRight:
			emit keyPressed("}");
			break;	
		case Qt::Key_Comma:
			emit keyPressed("<");
			break;
		case Qt::Key_Period:
			emit keyPressed(">");
			break;
		default:
			if (event->key() > 0x40 && event->key() < 0x91)
				emit keyPressed(event->text().toUpper());
	}
}

void WebView::onControl() {
	QString r = emit popBack();

	qDebug() << tr("control: %1").arg(r);
	if (r == ".")
		emit onCompleted();
	else if (r == "\u0013")
		emit onShowPressed();
	else if (r == "\u0014")
		emit onPTerminalPressed();
	else if (r == "\b")
		emit onHelp();
	else if (r == "\u001A")
		emit onExit();
}
