simple Node{
    
	parameters:
	    @display("i=block/source");
	    int gateCount;
	    int id;
	gates:
	    input inGates[gateCount];
	    output outGates[gateCount];
}

network Homework4
{
    parameters:
        @display("bgb=479,238");
        int nodeCount = default(5);
    submodules:
        nodes[nodeCount]: Node{
        	gateCount = nodeCount - 1;
        	id = index;
        	@display("p=126,58");
        }
    connections allowunconnected:
        for i=0..nodeCount-1, for j=0..nodeCount-2 
        {
        	nodes[i].outGates[j] --> {delay = 100 ms;} --> nodes[(i+j+1)%nodeCount].inGates[j];
        }
}
