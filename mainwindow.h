#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

    QChart *chart = new QChart();
    QChartView *chartView = new QChartView(chart);
    QValueAxis *axisX = new QValueAxis;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonSelectJson_clicked();
    void on_pushButtonDraw_clicked();

    void read_json(const QJsonObject &json);
    double find_biggest(const QJsonArray &json);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
