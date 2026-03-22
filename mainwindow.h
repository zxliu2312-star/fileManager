#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeView>
#include <QLineEdit>

#include <QVBoxLayout>
#include <QLabel>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    QFileSystemModel *fileModel;
    QTreeView *fileTree;
    QLineEdit *pathEdit;
    QString currentPath;
private slots:
    void onTreeDoubleClicked(const QModelIndex &index);
    void onGoBack();    
};
#endif // MAINWINDOW_H
