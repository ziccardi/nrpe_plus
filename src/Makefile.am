ACLOCAL_AMFLAGS = -I../m4
AUTOMAKE_OPTIONS = subdir-objects
AM_CPPFLAGS = $(BOOST_CPPFLAGS) -pthread
AM_LDFLAGS = $(BOOST_ASIO_LDFLAGS) $(BOOST_SYSTEM_LDFLAGS) $(PTHREAD_CFLAGS)
LIBS = $(BOOST_ASIO_LIBS) $(BOOST_SYSTEM_LIBS) $(PTHREAD_LIBS)

bin_PROGRAMS = nrpe++

nrpe___SOURCES = main.cpp ServerHandler.cpp ServerListener.cpp \
	network/RequestDecoder.cpp \
	network/ResponseEncoder.cpp \
	network/protocol/Packet.hpp \
	network/decoders/AbstractPacketDecoder.cpp \
	network/protocol/v2/NRPEV2AbstractPacket.cpp \
	network/protocol/v2/NRPEV2Request.hpp \
	network/protocol/v2/NRPEV2Response.hpp \
	network/decoders/v2/V2PacketDecoder.cpp \
	network/encoders/v2/V2PacketEncoder.cpp \
	network/protocol/v3/NRPEV3AbstractPacket.cpp \
	network/protocol/v3/NRPEV3Request.hpp \
	network/protocol/v3/NRPEV3Response.hpp \
	network/decoders/v3/V3PacketDecoder.cpp \
	network/encoders/v3/V3PacketEncoder.cpp \
	network/protocol/v4/NRPEV4AbstractPacket.cpp \
	network/protocol/v4/NRPEV4Request.hpp \
	network/protocol/v4/NRPEV4Response.hpp \
	network/decoders/v4/V4PacketDecoder.cpp \
	network/encoders/v4/V4PacketEncoder.cpp

