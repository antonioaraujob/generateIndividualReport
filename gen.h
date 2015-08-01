#ifndef GEN_H
#define GEN_H

/**
 * @brief Clase que abstrae un gen de un individuo. Incluye: Channel, MinChannelTime, MaxChannelTime, APs y FONC
 */
class Gen
{

private:
    int channel;
    double maxChannelTime;
    double minChannelTime;
    double APs;
    double FONC;

public:
    /**
     * @brief Constructor
     */
    Gen();

    /**
     * @brief Destructor
     */
    ~Gen();

    /**
     * @brief Constructor
     * @param ch canal
     * @param min minCHannelTime
     * @param max maxChannelTime
     * @param aps APs
     * @param fonc FONC
     */
    Gen(int ch, double min, double max, double aps, double fonc);

    /**
     * @brief retorna la latencia del gen (minCHannelTime+maxChannelTime)
     * @return retorna la latencia del gen (minCHannelTime+maxChannelTime)
     */
    int getLatency();

    /**
     * @brief getValue
     * @param index
     * @return
     */
    double getValue(int index);

    /**
     * @brief asigna el valor del canal del gen
     * @param c canal a asignar
     */
    void setChannel(int c);

    int getChannel();

    /**
     * @brief asigna el valor de minCHannelTime del gen
     * @param min minCHannelTime a asignar
     */
    void setMinChannelTime(double min);

    double getMinChannelTime();

    /**
     * @brief asigna el valor de maxChannelTime del gen
     * @param max maxChannelTime a asignar
     */
    void setMaxChannelTime(double max);

    double getMaxChannelTime();

    /**
     * @brief asigna el valor de APs del gen
     * @param aps APs a asignar
     */
    void setAPs(double aps);

    double getAPs();

    void setFONC(double fonc);

    /**
     * @brief Retorna el valor del indice FONC para el gen
     * @return valor del indice FONC para el gen
     */
    double getFONC();


};

#endif // GEN_H
