
#include "destination.h"

Define_Module(Destination);
/*
void Destination::initialize()
{
    // TODO - Generated method body
}
*/
void Destination::handleMessage(cMessage *msg)
{
    cPacket* pkt_r = check_and_cast<cPacket*> (msg);
    if(pkt_r->hasBitError()) {
        EV<<"Packet received in error";
        pkt_r ->setKind(1); //NACK
    }
    else{
        EV<<"Packet received correctly";
        pkt_r ->setKind(0); //ACK
    }
    pkt_r -> setBitError(false);
    send(pkt_r, "out");


}

