
#ifndef CTKEVENTCOMMON_H
#define CTKEVENTCOMMON_H


#include <QObject>

const static QString CTK_E_MAINWINDOW_TOPIC = "ctk_e_mainwindow_topic";
const static QString CTK_E_PLUGIN1_TOPIC = "ctk_e_plugin1_topic";
const static QString CTK_E_PLUGIN2_TOPIC = "ctk_e_plugin2_topic";

class CtkEventCommon : public QObject
{
    Q_OBJECT
public:
    explicit CtkEventCommon(QObject *parent = nullptr);

signals:

};

#endif // CTKEVENTCOMMON_H
