#ifndef CALCULATION_H
#define CALCULATION_H

#include <QtGui/QMainWindow>
#include "ui_calculation.h"

class calculation : public QMainWindow
{
	Q_OBJECT

public:
	calculation(QWidget *parent = 0, Qt::WFlags flags = 0);
	~calculation();

private:
	bool toMatchNum(const QString &str, float &result);//���ȷֵ���������
	bool toMatchNumX(const QString &str, float &result);//���С������
private:
	Ui::calculationClass ui;
	
public slots://�ۺ���������־
void caculate();//ת������
void clear();//���QLineEdit

};

#endif // CALCULATION_H
