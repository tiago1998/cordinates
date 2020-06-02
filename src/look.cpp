#include "look.h"
#include "credentials.h"
#include <QMessageBox>

Look::Look(QWidget *parent)
	: QDialog(parent)
{
	build();
	configure();
	setLayouts();

}


void Look::build() {
	mVLayout    = new QVBoxLayout(this);
	mHLayout[0] = new QHBoxLayout(this);
	mHLayout[1] = new QHBoxLayout(this);
	mTextEdit   = new QTextEdit(this);
	mSendServer = new QCheckBox(this);
	mCancel     = new QPushButton(this);
	mCopy 	    = new QPushButton(this);
	mOrigin	    = new QPushButton(this);
	mSend       = new QPushButton(this);
	mServer     = new QLineEdit(this);
	mPort	    = new QSpinBox(this);
	mMessage    = new QLabel(this);
	mTimer 	    = new QTimer(this);

}


void Look::configure() {
	mSendServer->setText("send server");
	mCancel->setText("exit");
	mCopy->setText("copy");
	mOrigin->setText("origin");
	mSend->setText("send");
	
	mSendServer->setChecked(false);
	mServer->setVisible(false);
	mPort->setVisible(false);
	mSend->setVisible(false);

	mMessage->setVisible(false);
	mMessage->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	mMessage->setStyleSheet("font-size: 40px");

	mPort->setRange(1, 65535);

	connect (mSendServer, &QCheckBox::stateChanged, [&](int state) {
		bool visible = state == Qt::Checked;
		mServer->setVisible(visible);
		mPort->setVisible(visible);
		mSend->setVisible(visible);
	});

	connect (mTimer, &QTimer::timeout, [&]() {
		mMessage->setVisible(false);
		mTimer->stop();
	});

	mSend->setStyleSheet("background-color: #7B68EE");
	connect (mCancel, &QPushButton::clicked, this, &Look::onCancel);
	connect (mCopy,   &QPushButton::clicked, this, &Look::onCopy);
	connect (mOrigin, &QPushButton::clicked, this, &Look::onOrigin);
	connect (mSend,   &QPushButton::clicked, this, &Look::onSend);

}

void Look::setLayouts() {
	mHLayout[0]->addWidget(mSendServer);
	mHLayout[0]->addWidget(mCancel);
	mHLayout[0]->addWidget(mCopy);
	mHLayout[0]->addWidget(mOrigin);
	mHLayout[1]->addWidget(mServer);
	mHLayout[1]->addWidget(mPort);
	mHLayout[1]->addWidget(mSend);

	mVLayout->addWidget(mMessage);
	mVLayout->addWidget(mTextEdit);
	mVLayout->addLayout(mHLayout[0]);
	mVLayout->addLayout(mHLayout[1]);

	setLayout(mVLayout);
}


void Look::setText(QString text) {
	mOriginText = text;
	mTextEdit->setText(text);
}


void Look::onCancel() {
	reject();
}


void Look::onCopy() {
	mTextEdit->copy();
	showMessage("copied", Qt::black, Qt::green); 
}


void Look::onOrigin() {
	mTextEdit->setText(mOriginText);
	showMessage("text reseted", Qt::black, Qt::blue);
}


void Look::onSend() {
	QString host = mServer->text();
	int port = mPort->value();

	QTcpSocket sock;
	if (not tryConnect(sock, host, port)) {
		showMessage("can't connect to host", Qt::white, Qt::red);
		return;
	}

	Credentials cdt(this);
	if (cdt.exec() == QDialog::Accepted) {
		QString password = cdt.password();
		
		if (not autenticate(sock, password)) {
			showMessage("wrong key", Qt::white, Qt::red);
			return;
		}
		
		QString data = mTextEdit->toPlainText();
		QString r = sendRecv(sock, "storeData_"+data);
		if (r != "ok")
			showMessage(r, Qt::white, Qt::red);
		else
			showMessage("uploaded with sucess", Qt::black, Qt::green);
	}

	sock.close();

}


bool Look::tryConnect(QTcpSocket &sock, QString host, int port) {
	sock.connectToHost(host, port);
	return sock.waitForConnected(10000);

}

QString Look::sendRecv(QTcpSocket &sock, QString msg) {
	sock.write(msg.toStdString().c_str());
	sock.flush();
	sock.waitForBytesWritten(10000);
	sock.waitForReadyRead(10000);
	return sock.readAll();
}


bool Look::autenticate(QTcpSocket &sock, QString pass) {
	return sendRecv(sock, pass) == "ok";
}


void Look::showMessage(QString message, QColor textColor, QColor background_color) {
	mMessage->setStyleSheet("color: "+textColor.name()+"; background-color: "+background_color.name());
	mMessage->setText(message);
	mMessage->setVisible(true);
	mTimer->start(3*1000);
}
