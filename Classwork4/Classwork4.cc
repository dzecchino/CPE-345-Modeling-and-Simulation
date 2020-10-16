#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class Node3 : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Node3);

void Node3::initialize()
{
    if (strcmp("node1", getName()) == 0) {
        EV << "Sending initial message\n";
        cMessage *msg = new cMessage("tictocMsg");
        send(msg, "out");
    }
}
void Node3::handleMessage(cMessage *msg)
{
    EV << "Received message " << msg->getName() << ", sending out message again\n";
    send(msg, "out"); // send out the message
}
