#include "Sockett.h"

Sockett::Sockett(QObject *parent) : QObject(parent)
{

}
 void Sockett::connect(const QString ip)
 {

     qDebug() <<"IP address:"<< ip;
    socket1 = new QTcpSocket(this);
    //socket1->connectToHost(ip,5600);
    socket1->connectToHost(ip,2222);
    if(socket1->waitForConnected(3000))
        {
            qDebug() << "Connected!";
    datanumber=300;
            // send
           // socket1->write("hello server\r\n\r\n\r\n\r\n");
            char str[10];
            sprintf(str,"#%d$",datanumber);
             socket1->write(str);
            socket1->waitForBytesWritten(1000);
            socket1->waitForReadyRead(3000);
          // while(socket1->bytesAvailable()==0);
            int recived=socket1->bytesAvailable();
            qDebug() << "Reading: " <<recived;

             QByteArray datarec = socket1->readAll();

//             for(int count=0;count<recived;count++)
//             {
//                 qDebug()<<datarec.at(count) ;
//             }
             QByteArray temp("***");
             int starpos=0;
             int ii=0;
                    starpos=  datarec.indexOf(temp);
                //     qDebug()<<"starpos:"<<starpos<<"\n";
                     for(;ii<100;ii++)
                     {
                         //qDebug()<<((ii*3)+starpos+3);
                         datablock.uni.c[0]= datarec.at((ii*3)+starpos+3);
                         datablock.uni.c[1]= datarec.at((ii*3)+starpos+4);
                       //  qDebug()<<"ii="<<ii<<";"<<  (int)datablock.uni.c[0]<<";"<<(int)datarec.at((ii*3)+starpos+3);
                         qDebug()<<datablock.uni.dataval<<',';
                     }
                    // qDebug()<<"endpos:"<<endpos<<"\n";



            qDebug() <<datarec;
    
          //  qDebug() <<datarec.toUInt();
            socket1->close();
        }
        else
        {
            qDebug() << "Not connected!";
        }        

 }
QString Sockett::IPred(void)
 {
return("null");
 }
