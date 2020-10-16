#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class Node : public cSimpleModule // maybe an = instead of a :
{
private:
  int gate_Count;
  int num_msgs;
  int node_id;

protected:
  virtual void initialize() override;
  virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Node);

void Node :: handleMessage(cMessage *msg){
  num_msgs++;
  EV << "Node" << node_id << " messaged received : " << msg->getName() << endl;
  EV << "Message count: " << num_msgs << endl;

  int gate = intuniform(0, gate_Count - 1);
  EV << "Forwarding message on outGate " << gate << endl;
  send(msg, "outGates" , gate);
}
void Node :: initialize(){
  num_msgs = 0;
  node_id = (int) par("id");
  gate_Count = (int) par("gateCount");
  if(node_id == 0) {
    EV << "Sending initial message\n";
    cMessage *msg = new cMessage("message");
    send(msg, "outGates" , intuniform(0, gate_Count-1));
  }

}
