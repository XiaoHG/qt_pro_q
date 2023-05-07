
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QQuickView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pQuickView = new QQuickView();
    m_pQuickContext = m_pQuickView->rootContext();

    m_pDataManager = new DataManager();
    m_pQuickContext->setContextProperty("dataManager", m_pDataManager);

    m_pQuickView->setSource(QUrl("qrc:/qml/test_page.qml"));
    QWidget *p_container = QWidget::createWindowContainer(m_pQuickView, this);
    ui->verticalLayout_qml->addWidget(p_container);

    m_pQuickItem = m_pQuickView->rootObject();

    connect(this, SIGNAL(notifyChangedForQml()), (QObject*)m_pQuickItem, SIGNAL(notifyChangedFromCPlus()));
    connect((QObject*)m_pQuickItem, SIGNAL(selectedChangedForCPlus()), this, SLOT(selectedChangedFromQml()));
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
}

