AUTOMAKE_OPTIONS = subdir-objects
bin_PROGRAMS = nrpe++

nrpe___SOURCES = main.cpp ServerHandler.cpp ServerListener.cpp network/RequestDecoder.cpp \
	network/decoders/v2/V2PacketDecoder.cpp network/decoders/v3/V3PacketDecoder.cpp \
	network/protocol/Packet.hpp \
	network/protocol/v2/NRPEV2AbstractPacket.cpp network/protocol/v2/NRPEV2Request.hpp \
	network/protocol/v3/NRPEV3AbstractPacket.cpp network/protocol/v2/NRPEV3Request.hpp
