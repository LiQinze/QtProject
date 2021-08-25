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
	bool toMatchNum(const QString &str, float &result);//检测度分的整数部分
	bool toMatchNumX(const QString &str, float &result);//检测小数部分
private:
	Ui::calculationClass ui;
	
public slots://槽函数声明标志
void caculate();//转换部分
void clear();//清空QLineEdit

};

#endif // CALCULATION_H
