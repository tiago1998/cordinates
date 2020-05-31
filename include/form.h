#ifndef __FORM_H__
#define __FORM_H__

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>

class Form : public QDialog {
	Q_OBJECT
public:
	Form(QWidget *parent=nullptr);
	QString getUrl();

private:
	void build();
	void configure();
	void setLayouts();

	QVBoxLayout *mVLayout;
	QHBoxLayout *mHLayout[2];
	QPushButton *mCancel, *mSend;
	QLineEdit *mLine;
	QComboBox *mBox;

};

#endif
