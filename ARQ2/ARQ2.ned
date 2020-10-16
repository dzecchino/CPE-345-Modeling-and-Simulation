
network ARQ2
{
    @display("bgb=264,193");
    submodules:
        source: Source {
            @display("p=37,81");
        }
        destination: Destination {
            @display("p=174,81");
        }
    connections:
        source.out -->{ber = 1e-3; delay = 100ms;} -->destination.in;
        destination.out -->{delay = 100ms;}-->source.in;
}
