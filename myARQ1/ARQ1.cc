#include<stdio.h>
#include<string.h>
#include<omnetpp.h>

using namespace omnetpp;

class Source : public cSimpleModule
{
  private:
    simtime_t timeout; //timeout for source
    cMessage *timeoutEvent; //holds pointer to the timeout self-message

  public:
    Source();
    virtual ~Source();
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Source);

Source::Source()
{
  timeoutEvent = nullptr;
}
Source::~Source()
{
  cancelAndDelete(timeoutEvent);
}
void Source::initialize()
{
  timeout = 1.0;// we will initialize the timour to 1
  timeoutEvent = new cMessage("timeoutEvent"); //schedule the first timeout event for the first packet

  //Generate and send initial message.
  EV << "Sending initial message\n";
  cMessage *msg =new cMessage("packet");
  send(msg, "out");
  scheduleAt(simTime()+timeout, timeoutEvent);
}

void Source::handleMessage(cMessage *msg)
{
  if (msg == timeoutEvent){
    //if we recieve the timeout event, no ACK was recieved in time and the timer expired-need to resend
    EV << "Timout expired, resending message and restarting timer\n";
    cMessage *newMsg = new cMessage("packet");
    send(newMsg, "out");
    scheduleAt(simTime()+timeout, timeoutEvent);
  }
}

class Destination : public cSimpleModule
{
protected:
  virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Destination);

void Destination::handleMessage(cMessage *msg)
{
  if (uniform(0, 1) < 0.1){ //lose message withh probability 0.1 - will implement this later differently
    bubble("message lost"); //use animation
    delete msg;
  }
  else {
    EV << "Sending back same message as ACK.\n";
    send(msg, "out");
  }
}
