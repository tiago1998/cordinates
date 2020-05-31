#ifndef __CREDENTIALS_H__
#define __CREDENTIALS_H__

#include <QDialog>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>

class Credentials : public QDialog {
	Q_OBJECT
public:
	Credentials(QWidget *parent=nullptr);
	QString password();

private:
	void build();
	void configure();
	void setLayouts();

	QVBoxLayout *mVLayout;
	QHBoxLayout *mHLayout;
	QFormLayout *mFLayout;
	QLineEdit  *mPass;
	QPushButton *mCancel, *mLogin;
	QCheckBox *mVisible;

};


#endif
