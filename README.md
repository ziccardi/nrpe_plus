#NRPE++
NRPE++ is a C++ implementation of [NRPE](https://github.com/NagiosEnterprises/nrpe).

The software is in pre-alpha version and, thus supporting NRPE protocol version 2, 3 and 4, it currently just return an _Hello World_ message to
any received query.

## Compile the sources

### Linux Ubuntu 19

1. Install the dependencies:
    ```bash
    sudo apt-get install libasio-dev libboost-system-dev
    ```
2. Check-out the source code
    ```bash
    git clone https://github.com/ziccardi/nrpe_plus.git
    cd nrpe_plus
    ```
3. Run the compilation
    1. `./configure`
    2. `make`
    
4. Compiled file named `nrpe++` will be created into the `src` folder.

### CentOS 7

CentOS 7 is shipped with a very old version of boost that is not supported by NRPE++, so we will have to install boost
from the sources.

#### Installing BOOST
1. `mkdir boost && cd boost`
2. `wget https://dl.bintray.com/boostorg/release/1.72.0/source/boost_1_72_0.tar.gz`
3. `tar xvfz boost_1_72_0.tar.gz && cd boost_1_72_0`
4. `sudo ./bootstrap.sh --prefix=/usr/local/boost`
5. `sudo ./b2 install`
6. Cross your fingers and wait

#### Compiling NRPE++

1. Check-out the source code
    ```bash
    git clone https://github.com/ziccardi/nrpe_plus.git
    cd nrpe_plus
    ```
2. CPPFLAGS="-std=c++11 -I /usr/local/boost/include/" ./configure
3. make
4. Compiled file named `nrpe++` will be created into the `src` folder.

**NOTE** We need to specify the `CPPFLAGS` because CentOS ships with a very old `gcc` compiler.

### MacOS

**Prerequisites**: you need to have [brew](https://brew.sh/) up and running to follow this instructions.

1. Install `boost`
    ```bash
    brew install boost
   ```
2. Check-out the source code
    ```bash
    git clone https://github.com/ziccardi/nrpe_plus.git
    cd nrpe_plus
    ```
3. Run the compilation
    1. `./configure`
    2. `make`
    
4. Compiled file named `nrpe++` will be created into the `src` folder.

Enjoy!