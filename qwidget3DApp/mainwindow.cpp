
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init3DSence();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init3DSence()
{
    //step1  创建一个3d 得view, 此颜色设置view的背景色，内部即glClearColor()的颜色
    m_view = new Qt3DExtras::Qt3DWindow();
    m_view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));

    //如果要将 3DWidnow 嵌入到widget中，需要一个widget来装它
    QWidget* container = QWidget::createWindowContainer(m_view);
    QSize screenSize = m_view->screen()->size();
    container->setMinimumSize(QSize(200, 100));
    container->setMaximumSize(screenSize);
    ui->d3DLayout->addWidget(container);


    //创建场景根节点
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;
    m_view->setRootEntity(rootEntity);


    //相机相关的属性控制
    Qt3DRender::QCamera* camEntity = m_view->camera();
    camEntity->lens()->setPerspectiveProjection(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
    camEntity->setPosition(QVector3D(0, 0, 10.0f));
    camEntity->setUpVector(QVector3D(0, 1, 0));
    camEntity->setViewCenter(QVector3D(0, 0, 0));
    //加一个Camera的 轨道控制器
    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    camController->setCamera(camEntity);

    //创建一个点光源
    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(1);
    lightEntity->addComponent(light);

    //将点光源 移动到 摄像机位置
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(camEntity->position());
    lightEntity->addComponent(lightTransform);
    m_view->setRootEntity(rootEntity);


    //模型加载
    Qt3DCore::QEntity* ent1 = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QSphereMesh* mesh1 = new Qt3DExtras::QSphereMesh(ent1);
    QVector3D pos1(QVector3D(-2.0f, 0.0f, 0.0f));
    addGeoMesh(rootEntity, mesh1, pos1);


    Qt3DCore::QEntity* ent2 = new Qt3DCore::QEntity(rootEntity);
    Qt3DExtras::QCuboidMesh* mesh2 = new Qt3DExtras::QCuboidMesh(ent2);
    QVector3D pos2(QVector3D(2.0f, 0.0f, 0.0f));
    addGeoMesh(rootEntity, mesh2, pos2);
}

void MainWindow::addGeoMesh(Qt3DCore::QEntity *rootEntity, Qt3DRender::QGeometryRenderer *geometry, QVector3D pos)
{
    //添加一个TestMesh; Mesh 中有两个立方体，
    Qt3DCore::QEntity* ent = new Qt3DCore::QEntity(rootEntity);

    Qt3DExtras::QPhongMaterial *material = new Qt3DExtras::QPhongMaterial();
    material->setDiffuse(QColor(QRgb(0x928327)));						//漫反射颜色
    material->setShininess(0.1f);

    Qt3DCore::QTransform *objTransformMesh = new Qt3DCore::QTransform();
    objTransformMesh->setTranslation(pos);
    objTransformMesh->setRotationX(45.0f);
    objTransformMesh->setScale(1.0f);

    ent->addComponent(geometry);
    ent->addComponent(material);
    ent->addComponent(objTransformMesh);
}



