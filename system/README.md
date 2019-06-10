# What ?

simulator-system is the a static library that enables remote interaction with
Veriltor-based simulator. It is not in charge of spawning main components, this
task is done by the main function. The system core receive as inputs the
different components and connect them together. In this way, the core behavior
remains the same for all simulated design but user can choose different external
interface (i.e. socket, pipe, mapped memory, ...) and different design driver
(AXI-Lite, Wishbone).

# How ?

The two main components of simulator-system are:

* AbstractNet : this class defines the requirements for a creating a Net
component. The Net components enables external communication.

* AbstractSimulator : this class defines the requirements for creating a
simulator driver. The Simulator Driver enables internal design read/write access through the peripheral memory interface (.i.e. AXI, Wishbone).

# Compiling ?

The compilation is made easy thanks to cmake!

```
cd system

mkdir build; cd build

cmake ..

# For Debug
# cmake -DCMAKE_BUILD_TYPE=Debug ..

make
```
