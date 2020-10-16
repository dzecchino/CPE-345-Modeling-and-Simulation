simple Node3
{
parameters:
    @display("i=block/routing");
    int num_msgs = 10;
    
   gates:
       input in;
       output out;
}

network Classwork4
{
   submodules:
       node1: Node3{
           parameters:
               @display("i=,cyan;p=38,69");
       }
       node2: Node3{
           parameters:
               @display("i=,gold;p=154,69");
       }
       node3: Node3{
           parameters:
               @display("i=,red;p=154,143");
       }
   connections:
       node1.out --> {delay = 100 ms; } --> node2.in;
       node2.out --> {delay = 100 ms; } --> node3.in;
       node3.out --> {delay = 100 ms; } --> node1.in;
}
