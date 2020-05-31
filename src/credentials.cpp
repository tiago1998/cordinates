#include "credentials.h"

Credentials::Credentials(QWidget *parent)
	: QDialog(parent)
{
	build();
	configure();
	setLayouts();

}

void Credentials::build() {
	mVLayout = new QVBoxLayout(this);
	mHLayout = new QHBoxLayout(this);
	mFLayout = new QFormLayout(this);
	mPass = new QLineEdit(this);
	mVisible = new QCheckBox(this);
	mCancel = new QPushButton(this);
	mLogin = new QPushButton(this);
}

void Credentials::configure() {
	mCancel->setText("cancel");
	mLogin->setText("login");
	mVisible->setText("visible");

	mPass->setEchoMode(QLineEdit::Password);

	connect (mVisible, &QCheckBox::stateChanged, [&](int type) {
		if (type == Qt::Checked)
			mPass->setEchoMode(QLineEdit::Normal);
		else
			mPass->setEchoMode(QLineEdit::Password);
	});
	connect (mCancel, &QPushButton::clicked, this, &QDialog::reject);
	connect (mLogin,  &QPushButton::clicked, this, &QDialog::accept);
}

void Credentials::setLayouts() {
	mFLayout->addRow("pass:", mPass);
	
	mHLayout->addWidget(mCancel);
	mHLayout->addWidget(mLogin);

	mVLayout->addLayout(mFLayout);
	mVLayout->addWidget(mVisible);
	mVLayout->addLayout(mHLayout);

	setLayout(mVLayout);
}



QString Credentials::password() {
	return mPass->text();
}
