#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

#include <QFileDialog>

QT_CHARTS_USE_NAMESPACE

void write_json(const QJsonObject &json);

void save_json(const QString &filepath);


QVector<QVector<double>> mForces(2);
QString strReply = "COF_Test_2021_03_22__07_54_55.json";
QLineSeries *series = new QLineSeries();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < 500; i++) {

        *series << QPointF((qreal) i, (qreal) 0.00);
    }
    QPen pen(0x059605);
    pen.setWidth(3);
    series->setPen(pen);


    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("aslşd");
    chart->createDefaultAxes();

    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->chartFrame);

    axisX->setRange(0, 16);
    axisX->setTickCount(11);
    axisX->setLabelFormat("%.2f");
    chartView->chart()->setAxisX(axisX, series);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSelectJson_clicked()
{
    strReply = QFileDialog::getOpenFileName(this, "Select a test Json");

//    strReply = QFileDialog::getOpenFileName(this, "Select a test Json", "C://");
}

void MainWindow::on_pushButtonDraw_clicked()
{
    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

    QJsonObject responseObject = jsonResponse.object();
    QFile file(strReply);

    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QJsonParseError JsonParseError;
    QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
    file.close();

    QJsonObject RootObject = JsonDocument.object();
    read_json(RootObject);

}


void MainWindow::read_json(const QJsonObject &json)
{
    if (json.contains("Company Name:")&& json["Company Name:"].isString())
{
        QString mName = json["Company Name:"].toString();
        ui->labelCompanyNameText->setText(mName);
        ui->labelCompanyName->setText("Company Name:");

}
    else
    {
        ui->labelCompanyName->setText(" ");
        ui->labelCompanyNameText->hide();

    }

    if (json.contains("Operator Name:")&& json["Operator Name:"].isString())
{
        QString mName = json["Operator Name:"].toString();
        ui->labelOperatorNameText->setText(mName);
        ui->labelOperatorName->setText("Operator Name:");

}
    else
    {
        ui->labelOperatorName->setText(" ");
        ui->labelOperatorNameText->hide();

    }

    if (json.contains("Testing Weight(gr):")&& json["Testing Weight(gr):"].isDouble())
{
        QString mName = json["Testing Weight(gr):"].toString();
        ui->labelTestingWeightText->setText(mName);
        ui->labelTestingWeight->setText("Testing Weight(gr):");

}
    else
    {
        ui->labelTestingWeight->setText(" ");
        ui->labelTestingWeightText->hide();

    }

    if (json.contains("Test Mode:")&& json["Test Mode:"].isBool())
{
        QString mName = json["Test Mode:"].toString();
        ui->labelTestModeText->setText(mName);
        ui->labelTestMode->setText("Test Mode:");

}
    else
    {
        ui->labelTestMode->setText(" ");
        ui->labelTestModeText->hide();

    }

    if (json.contains("Sample Name:")&& json["Sample Name:"].isString())
{
        QString mName = json["Sample Name:"].toString();
        ui->labelSampleNameText->setText(mName);
        ui->labelSampleName->setText("Sample Name:");

}
    else
    {
        ui->labelSampleName->setText(" ");
        ui->labelSampleNameText->hide();

    }

    if (json.contains("Sample Width(mm):")&& json["Sample Width(mm):"].isDouble())
{
        QString mName = json["Sample Width(mm):"].toString();
        ui->labelSampleWidthText->setText(mName);
        ui->labelSampleWidth->setText("Sample Width(mm):");

}
    else
    {
        ui->labelSampleWidth->setText(" ");
        ui->labelSampleWidthText->hide();

    }

    if (json.contains("Sample Height(mm):")&& json["Sample Height(mm):"].isDouble())
{
        QString mName = json["Sample Height(mm):"].toString();
        ui->labelSampleHeightText->setText(mName);
        ui->labelSampleHeight->setText("Sample Height(mm):");

}
    else
    {
        ui->labelSampleHeight->setText(" ");
        ui->labelSampleHeightText->hide();

    }

    if (json.contains("Sample Age(months):")&& json["Sample Age(months):"].isDouble())
{
        QString mName = json["Sample Name(months):"].toString();
        ui->labelSampleNameText->setText(mName);
        ui->labelSampleName->setText("Sample Name(months):");

}
    else
    {
        ui->labelSampleName->setText(" ");
        ui->labelSampleNameText->hide();

    }

    if (json.contains("Max Static Coefficient of Friction:")&& json["Max Static Coefficient of Friction:"].isDouble())
{
        QString mName = json["Max Static Coefficient of Friction:"].toString();
        ui->labelMaxStaticCofText->setText(mName);
        ui->labelMaxStaticCof->setText("Max Static Cof:");

}
    else
    {
        ui->labelMaxStaticCof->setText(" ");
        ui->labelMaxStaticCofText->hide();

    }

    if (json.contains("Mean Static Coefficient of Friction:")&& json["Mean Static Coefficient of Friction:"].isDouble())
{
        QString mName = json["Mean Static Coefficient of Friction:"].toString();
        ui->labelMeanStaticCofText->setText(mName);
        ui->labelMeanStaticCof->setText("Mean Static Cof:");

}
    else
    {
        ui->labelMeanStaticCof->setText(" ");
        ui->labelMeanStaticCofText->hide();

    }

    if (json.contains("Max Dynamic Coefficient of Friction:")&& json["Max Dynamic Coefficient of Friction:"].isDouble())
{
        QString mName = json["Max Dynamic Coefficient of Friction:"].toString();
        ui->labelMaxDynamicCofText->setText(mName);
        ui->labelMaxDynamicCof->setText("Max Dynamic Cof:");

}
    else
    {
        ui->labelMaxDynamicCof->setText(" ");
        ui->labelMaxDynamicCofText->hide();

    }

    if (json.contains("Mean Dynamic Coefficient of Friction:")&& json["Mean Dynamic Coefficient of Friction:"].isDouble())
{
        QString mName = json["Mean Dynamic Coefficient of Friction:"].toString();
        ui->labelMeanDynamicCofText->setText(mName);
        ui->labelMeanDynamicCof->setText("Mean Dynamic Cof:");

}
    else
    {
        ui->labelMeanDynamicCof->setText(" ");
        ui->labelMeanDynamicCofText->hide();

    }
    /*
    if (json.contains("Sample Name:")&& json["Sample Name:"].isString())
{
        QString mName = json["Sample Name:"].toString();
        ui->labelSampleNameText->setText(mName);
        ui->labelSampleName->setText("Sample Name:");

}
    else
    {
        ui->labelSampleName->setText(" ");
        ui->labelSampleNameText->hide();

    }
*/


    if (json.contains("Forces:") && json["Forces:"].isArray()) {
        QJsonArray levelArray = json["Forces:"].toArray();

        series->clear();
        series->setUseOpenGL(true);

        for (int levelIndex = 0; levelIndex < levelArray.size(); ++levelIndex){
            series->append( (qreal) levelArray[levelIndex].toArray().at(0).toDouble(), (qreal) levelArray[levelIndex].toArray().at(1).toDouble());
        }
        double a = levelArray[levelArray.size() -1].toArray().at(0).toDouble();
        //double b = levelArray[levelArray.size() -1].toArray().at(1).toDouble(); //make a biggest function

        double b = find_biggest(levelArray) * 1.1;

        chart->axes(Qt::Horizontal).first()->setRange(0, a);
        chart->axes(Qt::Vertical).first()->setRange(0, b);
    }
}

double MainWindow::find_biggest( const QJsonArray &json)
{
    double biggest = 0;
    for (int i = 0; i < json.size(); ++i){
        if (json[i].toArray().at(1).toDouble() > biggest)
        {
            biggest = json[i].toArray().at(1).toDouble();
        }
    }

    return biggest;
}


// devamı data yazma
void write_json(const QJsonObject &json)
{/*
    QString playerObject = "eheheh";
    json["player"] = playerObject;
*/
    QJsonObject recordObject;
    recordObject.insert("FirstName", QJsonValue::fromVariant("John"));
    recordObject.insert("LastName", QJsonValue::fromVariant("Doe"));
    recordObject.insert("Age", QJsonValue::fromVariant(43));

    QJsonObject addressObject;
    addressObject.insert("Street", "Downing Street 10");
    addressObject.insert("City", "London");
    addressObject.insert("Country", "Great Britain");
    recordObject.insert("Address", addressObject);

    QJsonArray phoneNumbersArray;
    phoneNumbersArray.push_back("+44 1234567");
    phoneNumbersArray.push_back("+44 2345678");
    recordObject.insert("Phone Numbers", phoneNumbersArray);

    QJsonDocument doc(recordObject);

}
void save_json(const QString &filepath)
{
    QFile file(filepath);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QJsonParseError JsonParseError;
    QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
    file.close();
    QJsonObject RootObject = JsonDocument.object();
    QJsonValueRef ref = RootObject.find("Address").value();
    QJsonObject m_addvalue = ref.toObject();
    m_addvalue.insert("Street","India");//set the value you want to modify
    ref=m_addvalue; //assign the modified object to reference
    JsonDocument.setObject(RootObject); // set to json document
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(JsonDocument.toJson());
    file.close();
}


