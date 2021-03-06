# lauSim Client

This is the client forthe Lightweight Automatic fault Simulator. While the server manages the faults and dispatches them, the task of the client is to inject these faults into the applications to mimic actual faults.

# Design Considerations

The client runs on the same nodes as the programs itself and should be transparent to the application, to the extend that simulated faults should not be distinguishable from simulated ones. This entails that the performance characteristics should not be disturbed by the client and therefore requires a compact and efficient design. For this reason the client does not come with a plugin system, but multiple versions are generated at compile time. The next bit point is the actual injection of faults. Here there are basically two possibilities: First faults could be injected by a library loaded into the program or second, by another program outside of the applications memory. To keep the amount of code and data injected into the process to a minimum, the networking is done in a dedicated process, which communicates with the injector the possibly resides inside the targets process, via a fifo queue. In case of a loadable library, the fault injection has to be initialized before the main program starts to be able to intercept calls to other libraries. It also has to listen to command while the program orderly executes. For this reason a thread, dedicated to communication, has to be created during initialization.

# Initialization of the injector

Creating the fifo and reading from it is common to all fault injection techniques and the backbone of the injector. It is therefor implemented independently and accessible via a common interface. Initializing the loadable library is a complex procedure. It starts in a constructor, specific to this method of injection and then initializes the fifo in the back end. Next it waits for the synchronization of the server and lastly creates a new thread to listen to commands. The constructor exits and loading of the rest of the binary commences. Not returning before the synchronization enables the back end to stall the loading and effectively synchronizes the clients.

# limitations of this approach

Both, the loadable library, as well as the external process have some limitations to them. As they both are designed to be transparent to the program, they cannot know about the progress the program makes. For this reason the clients can not run in sync apart from all starting at the same time. The loadable library will always have effects measurable by the program it is injected into. These effects can be the heap state or even the presence of mapped pages. An external program has the downside, that it knows less about the state of the program and injection of faults may be more difficult.
