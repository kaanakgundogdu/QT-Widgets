#include <QApplication>
#include "customwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomWidget c;
    c.setWindowTitle("Kaan's custom widget");
    c.show();

    return a.exec();
}
