#include "form.h"


Form::Form(QWidget *parent)
	: QDialog(parent)
{
	build();
	configure();
	setLayouts();
}

void Form::build() {
	mVLayout = new QVBoxLayout(this);
	mHLayout[0] = new QHBoxLayout(this);
	mHLayout[1] = new QHBoxLayout(this);
	mLine = new QLineEdit(this);
	mBox = new QComboBox(this);
	mCancel = new QPushButton(this);
	mSend = new QPushButton(this);

}

void Form::configure() {
	mBox->addItems({"http://", "https://"});
	mCancel->setText("cancel");
	mSend->setText("enter");
	mSend->setStyleSheet("color: #F0FFF0;background-color: #228B22");

	connect (mCancel, &QPushButton::clicked, this, &QDialog::reject);
	connect (mSend, &QPushButton::clicked, this, &QDialog::accept);
}

void Form::setLayouts() {
	mHLayout[0]->addWidget(mBox);
	mHLayout[0]->addWidget(mLine);     	
	mHLayout[1]->addWidget(mCancel);
	mHLayout[1]->addWidget(mSend);

	mVLayout->addLayout(mHLayout[0]);
	mVLayout->addLayout(mHLayout[1]);

	setLayout(mVLayout);
}


QString Form::getUrl() {
	return mBox->currentText()+mLine->text();
}
