#ifndef __LOOK_H__
#define __LOOK_H__

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTcpSocket>
#include <QCheckBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QTimer>
#include <QLabel>

class Look : public QDialog {
	Q_OBJECT
public:
	Look(QWidget *parent=nullptr);

	void setText(QString text);


private:
	void build();
	void configure();
	void setLayouts();

	void onCancel();
	void onOrigin();
	void onCopy();
	void onSend();

	bool tryConnect(QTcpSocket &sock, QString host, int port);
	bool autenticate(QTcpSocket &sock, QString pass);
	QString sendRecv(QTcpSocket &sock, QString msg);
	void showMessage(QString msg, QColor textColor=Qt::black, QColor background_color=Qt::white);

	QVBoxLayout *mVLayout;
	QHBoxLayout *mHLayout[2];
	QTextEdit *mTextEdit;
	QCheckBox *mSendServer;
	QPushButton *mCancel, *mCopy, *mOrigin, *mSend;
	QLineEdit *mServer;
	QSpinBox *mPort;
	QLabel *mMessage;
	QTimer *mTimer;
	

	QString mOriginText;

};

#endif
