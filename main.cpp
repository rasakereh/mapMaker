#include <QApplication>
#include <QHBoxLayout>
#include "headers/MapDraft.h"

int main(int argc, char **argv)
{
    Q_INIT_RESOURCE(MapMakerResources);

    QApplication app(argc, argv);

    QWidget mainWidget;
    QHBoxLayout *horizontalLayout = new QHBoxLayout(&mainWidget);
    horizontalLayout->addWidget(new MapDraft);
    horizontalLayout->addWidget(new MapDraft);

    mainWidget.setWindowTitle(QObject::tr("Draggable Icons"));
    mainWidget.show();

    return app.exec();
}
