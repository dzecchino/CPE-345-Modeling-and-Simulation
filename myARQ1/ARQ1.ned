simple Source{
    parameters:
        @display("i=block/source");
    gates:
        input in;
        output out;
}

simple Destination{
    parameters:
        @display("i=block/sink");
    gates:
        input in;
        output out;
}
network ARQ1
{
    @display("bgb=179,108");
    submodules:
        source: Source {
            @display("p=40,42");
        }
        destination: Destination {
            @display("p=124,42");
        }
    connections:
        source.out --> {delay = 20 ms; } --> destination.in;
        destination.out --> {delay = 20 ms; } --> source.in;
}
