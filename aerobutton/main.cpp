#include <QtGui>
#include <QTextCodec>
#include <QApplication>
#include <QObject>
#include <QVBoxLayout>
#include <QSpinBox>
#include "AeroButton.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  
	//AeroButton::connect(&button, SIGNAL(clicked()), qApp, SLOT(quit()));
	QIcon icon("./tbl.png");
    //icon.addFile(QString::fromUtf8(":/images/cell_adjast.png"), QSize(), QIcon::Normal, QIcon::Off);
	
	QWidget	w;
	QVBoxLayout	*l = new QVBoxLayout(&w);
	
	AeroButton *button = new AeroButton("Test");

	button->setColor(QColor(Qt::darkRed));
	button->setShadow(QColor(Qt::black));
	button->setHighlight(QColor(Qt::red));
	button->setRoundness(20);
	button->setOpacity(0.65);
	button->setIcon(icon);
	
	QSpinBox	*round = new QSpinBox(&w);
	round->setValue(20);
	QSpinBox::connect(round, SIGNAL(valueChanged (int)),
						button, SLOT(setRoundness(int)));
						
	QDoubleSpinBox	*opacity = new QDoubleSpinBox(&w);
	opacity->setValue(0.65);
	opacity->setSingleStep(0.1);
	QSpinBox::connect(opacity, SIGNAL(valueChanged (double)),
						button, SLOT(setOpacity(double)));
	
	l->addWidget(round);
	l->addWidget(opacity);
	//l->addWidget(button);
	
	w.setLayout(l);
	
	w.show();
	
	button->show();
	
	return app.exec();
}
