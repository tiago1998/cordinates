#include <QApplication>
#include <QString>
#include <QObject>
#include <QDialog>
#include <QDebug>
#include <stdlib.h>
#include "widget.h"
#include "form.h"
#include "look.h"
#include "defines.h"

int main(int argc, char *argv[]) {
	if (argc > 1 
	&& QString(argv[1]).indexOf("help") > -1
	&& strlen(argv[1]) < 6) {
		printf ("%s [url]\n", argv[0]);
		printf (HELP_MESSAGE);
		return 1;
	}

	QApplication app(argc, argv);

	
	Form form;
	Widget widget;

	QString url;
	if(argc == 2) { 
		url = argv[1];
		if (not url.startsWith("http"))
			url = "http://"+url;
	}
	else if (form.exec() == QDialog::Accepted) 
		url = form.getUrl();
	else {
		app.quit();
		return 127;
	}
	QObject::connect (&widget, &Widget::onCompleted, [&](QString txt) {
		widget.close();
		Look look;
		look.setText(txt);
		look.exec();
	});

	widget.setUrl(url);
	widget.showMaximized();//FullScreen();
	
	app.exec();

}
