#include <QApplication>
#include "headers/Worksheet.h"

int main(int argc, char **argv)
{
    Q_INIT_RESOURCE(MapMakerResources);

    QApplication app(argc, argv);

    Worksheet worksheet;
    worksheet.show();
    
    return app.exec();
}
