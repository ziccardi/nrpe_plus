cmake_minimum_required(VERSION 3.13)  # CMake version check
project(nrpe++)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

include_directories(/usr/local/include)

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES
        src/main.cpp
        src/ServerHandler.cpp
        src/ServerListener.cpp
        src/network/RequestDecoder.cpp
        src/network/v2/V2PacketDecoder.cpp
        src/network/v3/V3PacketDecoder.cpp src/network/protocol/v2/NRPEV2AbstractPacket.cpp src/network/protocol/v2/NRPEV2AbstractPacket.hpp src/network/protocol/Packet.cpp src/network/protocol/Packet.hpp src/network/protocol/v2/NRPEV2Request.cpp src/network/protocol/v2/NRPEV2Request.hpp src/network/protocol/v3/NRPEV3AbstractPacket.cpp src/network/protocol/v3/NRPEV3AbstractPacket.hpp src/network/protocol/v3/NRPEV3Request.hpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(nrpe++ ${SOURCE_FILES})