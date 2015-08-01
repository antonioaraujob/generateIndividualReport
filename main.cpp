#include <QCoreApplication>
#include <QFile>
#include <QStringList>
#include <QTextStream>


#include "gen.h"

// generateIndividualReport <individuals.txt>



inline static bool xLessThanChannel(Gen * g1, Gen * g2)
{
    return g1->getChannel() < g2->getChannel();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    QStringList arguments = a.arguments();

    //qDebug("numero de argumentos: ");
    //qDebug(qPrintable(QString::number(arguments.size())));

    if (arguments.size() != 2)
    {
        qDebug("error al ejecutar al programa. ./generateIndividualReport individuals.txt");
        return 1;
    }

    //qDebug(qPrintable(arguments.at(0)));
    //qDebug(qPrintable(arguments.at(1)));


    // leer el archivo de individuos resultantes de la simulacion
    QFile inputFile("individuosFrenteParetoModificadoPorAPsDescendente.txt");
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug(qPrintable("Error: no se pudo leer el archivo de individuos."));
        return 1;
    }

    bool firstLine = true;

    QTextStream in(&inputFile);

    int individualNumber = 0;

    // leer cada linea y procesarla
    while (!in.atEnd())
    {
        QString line = in.readLine();

        /*
        if (firstLine)
        {
            firstLine = false;
            continue;
        }
        */

        //qDebug(qPrintable(line));

        //individualNumber++;

        QStringList parameters = line.split(",");

        int channel = 0;
        double min = 0;
        double max = 0;
        double aps = 0;
        double fonc = 0;



        Gen * gen;

        QList<Gen*> genList;

        for (int i=0; i<11; i++)
        {
            //qDebug(qPrintable(parameters.at(i)));
            channel = parameters.at(i*5).toInt();
            min = parameters.at((i*5)+1).toDouble();
            max = parameters.at((i*5)+2).toDouble();
            aps = parameters.at((i*5)+3).toDouble();
            fonc = parameters.at((i*5)+4).toDouble();

            gen = new Gen(channel, min, max, aps, fonc);
            genList.append(gen);


        }

        // ordenar la lista de genes con respecto al canal
        qSort(genList.begin(), genList.end(), xLessThanChannel);

        // recorrer la lista de genes y escribir el archivo correspondiente al individuo
        QString of = "individual"+QString::number(individualNumber)+".txt";
        QFile outputFile(of);
        if (outputFile.exists())
        {
            outputFile.remove();
        }
        if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug("Error: no se pudo escribir el archivo para el individuo");
            return 1;
        }

        QTextStream out(&outputFile);
        QString newLine = "";

        for (int i=0; i<genList.size(); i++)
        {
            Gen * g = genList.at(i);
            newLine.append(QString::number(g->getChannel()));
            newLine.append(" ");
            newLine.append(QString::number(g->getMinChannelTime()));
            newLine.append(" ");
            newLine.append(QString::number(g->getMaxChannelTime()));
            newLine.append(" ");
            newLine.append(QString::number(g->getAPs()));
            newLine.append(" ");
            newLine.append(QString::number(g->getFONC()));
            newLine.append("\n");
            out << newLine;
            newLine.clear();
        }


        outputFile.close();
        individualNumber++;
    }

    QString msg = "generados los "+ QString::number(individualNumber) +" archivos individualX.txt";

    qDebug(qPrintable(msg));
    return 0;
}
