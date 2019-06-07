# What ?

simulator-system is the a static library that enables remote interaction with
Veriltor-based simulator. It is not in charge of spawning main components, this
task is done by the main function. The system core receive as inputs the
different components and connect them together. In this way, the core behavior
remains the same for all simulated design but user can choose different external
interface (i.e. socket, pipe, mapped memory, ...) and different design driver
(AXI-Lite, Wishbone).
