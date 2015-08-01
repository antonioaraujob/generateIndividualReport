#include "gen.h"

Gen::Gen()
{
    channel = 0;
    maxChannelTime = 0;
    minChannelTime = 0;
    APs = 0;
    FONC = 0;
}

Gen::~Gen()
{
}

Gen::Gen(int ch, double min, double max, double aps, double fonc)
{
    channel = ch;
    minChannelTime = min;
    maxChannelTime = max;
    APs = aps;
    FONC = fonc;
}

int Gen::getLatency()
{
    return minChannelTime+maxChannelTime;
}

double Gen::getValue(int index)
{
    if (index ==0)
        return channel;
    else if (index == 1)
        return minChannelTime;
    else if (index == 2)
        return maxChannelTime;
    else if (index == 3)
        return APs;
    else
        return FONC;
}

void Gen::setChannel(int c)
{
    channel = c;
}

int Gen::getChannel()
{
    return channel;
}

void Gen::setMinChannelTime(double min)
{
    minChannelTime = min;
}

double Gen::getMinChannelTime()
{
    return minChannelTime;
}

void Gen::setMaxChannelTime(double max)
{
    maxChannelTime = max;
}

double Gen::getMaxChannelTime()
{
    return maxChannelTime;
}

void Gen::setAPs(double aps)
{
    APs = aps;
}

double Gen::getAPs()
{
    return APs;
}

void Gen::setFONC(double fonc)
{
    FONC = fonc;
}

double Gen::getFONC()
{
    return FONC;
}
