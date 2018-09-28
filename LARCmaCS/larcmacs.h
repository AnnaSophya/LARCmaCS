#ifndef LARCMACS_H
#define LARCMACS_H

#include <QWidget>

#include "fieldScene.h"
#include "receiver.h"
#include "mainAlg.h"
#include "sceneView.h"
#include "connector.h"
#include "remotecontrol.h"


#define NUM_CONTROL_ROBOTS 12

namespace Ui
{
    class LARCmaCS;
}

class LARCmaCS : public QWidget
{
    Q_OBJECT

public:
    RemoteControl remotecontol;
    explicit LARCmaCS(QWidget *parent = 0);
    ~LARCmaCS();

    FieldScene *fieldscene;
    QString * macsArray;

protected:
    bool scalingRequested;
    sceneView sceneview;
    Receiver receiver;
    MainAlg mainalg;
    Connector connector;


private:
    Ui::LARCmaCS *ui;
    float drawscale;
    qreal sizescene;
    QString wifiaddrdata[NUM_CONTROL_ROBOTS];
    QUdpSocket socket;

private slots:
    void fieldsceneUpdateRobots();
    void UpdateSSLFPS(QString message);
    void UpdateStatusBar(QString message);
    void UpdatePauseState(QString message);
    void updateView();
    void scaleView(int);

private slots:
    void on_pushButton_Pause_clicked();
    void on_pushButton_SetMLdir_clicked();
    void on_pushButton_RC_clicked();
    void remcontrolsender(int l, int r,int k, int b, bool kickUp);

    void on_checkBox_MlMaxFreq_stateChanged(int arg1);

    void on_AddRobot_pushButton_clicked();

    void on_robotIpList_activated(const QString &arg1);

    void on_pushButton_RemoteControl_clicked();

    void on_robotIndex_currentIndexChanged(int index);

signals:
    void sendToConnectorRM(int N,QByteArray command);
    void receiveMacArray(QString*);
    void ChangeMaxPacketFrequencyMod(bool state);
    void MatlabPause();
    void MLEvalString(QString s);
    void updateRobots();
    void openPort(QString);
    void addIp(int, QString);
};

#endif // LARCMACS_H
