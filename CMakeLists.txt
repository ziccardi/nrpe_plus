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
        src/network/decoders/v2/V2PacketDecoder.cpp
        src/network/decoders/v3/V3PacketDecoder.cpp
        src/network/protocol/v2/NRPEV2AbstractPacket.cpp
        src/network/protocol/v2/NRPEV2AbstractPacket.hpp
        src/network/protocol/Packet.hpp
        src/network/protocol/v2/NRPEV2Request.hpp
        src/network/protocol/v3/NRPEV3AbstractPacket.cpp
        src/network/protocol/v3/NRPEV3AbstractPacket.hpp
        src/network/protocol/v3/NRPEV3Request.hpp src/network/protocol/v2/NRPEV2Response.hpp
        src/network/encoders/v2/V2PacketEncoder.cpp src/network/encoders/v2/V2PacketEncoder.hpp
        src/network/ResponseEncoder.cpp src/network/ResponseEncoder.hpp
        src/network/encoders/v3/V3PacketEncoder.cpp
        src/network/encoders/v3/V3PacketEncoder.hpp
        src/network/protocol/v3/NRPEV3Response.hpp
        src/network/encoders/v4/V4PacketEncoder.cpp
        src/network/encoders/v4/V4PacketEncoder.hpp
        src/network/protocol/v4/NRPEV4Response.hpp
        src/network/decoders/AbstractPacketDecoder.cpp
        src/network/decoders/AbstractPacketDecoder.hpp
        src/network/protocol/v4/NRPEV4AbstractPacket.cpp
        src/network/protocol/v4/NRPEV4AbstractPacket.hpp
        src/network/protocol/v4/NRPEV4Request.hpp
        src/network/protocol/v4/NRPEV4Response.hpp
        src/network/decoders/v4/V4PacketDecoder.cpp
        src/network/decoders/v4/V4PacketDecoder.hpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(nrpe++ ${SOURCE_FILES})