#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>

class CustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomWidget(QWidget *parent = nullptr);

private slots:
    void button_clicked();
private:
    QSize sizeHint() const;

};

#endif // CUSTOMWIDGET_H
