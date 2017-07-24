#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <map>
#include <string>

#include <QFrame>
#include <QHBoxLayout>
#include <QPushButton>

class Toolbar: public QFrame
{
public:
    Toolbar(QWidget *parent = nullptr);
    
private:
    std::map<std::string, QPushButton *> toolbarButtons;
    
    QHBoxLayout toolbarLayout;
    
};

#endif // TOOLBAR_H
