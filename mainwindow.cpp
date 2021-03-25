#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>

void clicked();

void read_json(const QJsonObject &json);
void write_json(const QJsonObject &json);

void save_json(const QString &filepath);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, &QPushButton::clicked, qApp, clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void clicked()
{
    QString result = "clicked";
    qDebug() << result;
    QString strReply = "COF_Test_2021_03_22__07_54_55.json";
    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

    QJsonObject responseObject = jsonResponse.object();
    QFile file(strReply);

    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QJsonParseError JsonParseError;
    QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
    file.close();
    QJsonObject RootObject = JsonDocument.object();
    read_json(RootObject);/*
    QString strOutput = "deneme.json";
   //save_json(strReply);
    QJsonDocument jsonOutput = QJsonDocument::fromJson(strOutput.toUtf8());
    QJsonObject outputObject = jsonResponse.object();
    write_json(outputObject);*/
}

void read_json(const QJsonObject &json)
{
    if (json.contains("Company Name:")&& json["Company Name:"].isString())
{
        QString mName = json["Company Name:"].toString();
        qDebug() << mName;
}

    if (json.contains("Forces:") && json["Forces:"].isArray()) {
        QJsonArray levelArray = json["Forces:"].toArray();
        //qDebug() << levelArray;
        QVector<QVector<double>> mForces(2);
        //mForces[0][1] = 12;
        qDebug() << mForces.size();
        mForces[0].resize(levelArray.size());
        mForces[1].resize(levelArray.size());
        qDebug() << mForces.size();
        for (int levelIndex = 0; levelIndex < levelArray.size(); ++levelIndex) {

            //QJsonObject levelObject = levelArray[levelIndex].toObject();
            //mForces.append(levelArray[levelIndex].toDouble());
            //mForces.append(levelArray[levelIndex].toArray());
            mForces[0][levelIndex] = (levelArray[levelIndex].toArray().at(0).toDouble());
           mForces[1][levelIndex] = (levelArray[levelIndex].toArray().at(1).toDouble());
/*
                QVector<double> a;
                a.clear();
            //mForces[0][levelIndex] = levelArray[levelIndex].toArray().at(0).toDouble();
                qDebug() << levelArray[levelIndex].toArray().at(0).toDouble();
                qDebug() << levelArray[levelIndex].toArray().at(1).toDouble();
*/
        }
        qDebug() << mForces;
    }
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
    qDebug() << doc.toJson();

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
