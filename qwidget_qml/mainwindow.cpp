
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QQuickView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pQuickView.reset(new QQuickView());
    m_pQuickContext.reset(m_pQuickView->rootContext());

    m_pDataManager.reset(new DataManager());
    m_pQuickContext->setContextProperty("dataManager", m_pDataManager.get());
    qmlRegisterType<DataManager>("DataManager", 1, 0, "DataManager");

    m_pQuickView->setSource(QUrl("qrc:/qml/test_page.qml"));
    QWidget *p_container = QWidget::createWindowContainer(m_pQuickView.get(), this);
    ui->verticalLayout_qml->addWidget(p_container);

    m_pQuickItem.reset(m_pQuickView->rootObject());

    connect(this, SIGNAL(notifyChangedForQml()), (QObject*)m_pQuickItem.get(), SIGNAL(notifyChangedFromCPlus()));
    connect((QObject*)m_pQuickItem.get(), SIGNAL(selectedChangedForCPlus()), this, SLOT(selectedChangedFromQml()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString name = m_pDataManager->name();
    name += "m";
    m_pDataManager->setName(name);
    emit notifyChangedForQml();
}

void MainWindow::selectedChangedFromQml()
{
    QStringList selectedList = m_pQuickItem->property("selectedList").toStringList();
    qDebug() << "qin --- MainWindow::selectedChangedFromQml(), selectedList = " << selectedList;

    DataManager *data_manger = qobject_cast<DataManager*>(m_pQuickItem->findChild<QObject *>("data_manager"));
    qDebug() << "qin --- MainWindow::selectedChangedFromQml(), data_manger->name() = " << data_manger->name();
}

