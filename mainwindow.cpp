#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , fileModel(new QFileSystemModel(this))
    , fileTree(new QTreeView(this))
    , pathEdit(new QLineEdit(this))
    , currentPath("D:/")
{
    ui->setupUi(this);
    
    // ========== 步骤 1：设置文件模型 ==========
    fileModel->setRootPath(currentPath);
    
    // ========== 步骤 2：配置树视图 ==========
    fileTree->setModel(fileModel);
    fileTree->setRootIndex(fileModel->index(currentPath));
    fileTree->setMinimumSize(600, 400);
    
    // ========== 步骤 3：配置路径编辑框 ==========
    pathEdit->setText(currentPath);
    pathEdit->setReadOnly(true);
    pathEdit->setMaximumHeight(30);
    
    // ========== 步骤 4：创建返回按钮 ==========
    QPushButton *backButton = new QPushButton("返回上一级", this);
    backButton->setMaximumWidth(100);
    
    // ========== 步骤 5：创建布局并添加组件 ==========
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(new QLabel("当前路径："));
    layout->addWidget(pathEdit);
    layout->addWidget(backButton);
    layout->addWidget(new QLabel("文件列表："));
    layout->addWidget(fileTree);
    layout->setSpacing(10);
    layout->setContentsMargins(10, 10, 10, 10);
    
    // ========== 步骤 6：连接信号和槽 ==========
    connect(fileTree, &QTreeView::doubleClicked, this, &MainWindow::onTreeDoubleClicked);
    connect(backButton, &QPushButton::clicked, this, &MainWindow::onGoBack);
    
    // ========== 步骤 7：设置窗口属性 ==========
    setWindowTitle("文件管理器");
    resize(800, 600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ========== 双击打开文件夹 ==========
void MainWindow::onTreeDoubleClicked(const QModelIndex &index)
{
    // 获取被双击项目的文件路径
    QString filePath = fileModel->filePath(index);
    
    // 判断是否为目录
    if (fileModel->isDir(index)) {
        // 更新当前路径
        currentPath = filePath;
        
        // 更新路径编辑框显示
        pathEdit->setText(currentPath);
        
        // 更新树视图的根目录
        fileTree->setRootIndex(fileModel->index(currentPath));
    }
}

// ========== 返回上一级目录 ==========
void MainWindow::onGoBack()
{
    // 创建一个 QDir 对象表示当前目录
    QDir dir(currentPath);
    
    // 返回上一级目录
    if (dir.cdUp()) {
        // 获取上一级目录的路径
        currentPath = dir.absolutePath();
        
        // 更新路径编辑框显示
        pathEdit->setText(currentPath);
        
        // 更新树视图的根目录
        fileTree->setRootIndex(fileModel->index(currentPath));
    }
}
