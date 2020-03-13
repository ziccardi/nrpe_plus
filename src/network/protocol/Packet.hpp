//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#ifndef NRPE_PACKET_HPP
#define NRPE_PACKET_HPP

#include <cstdint>
#include <memory>
#include <string>

class Packet {
private:
    const int16_t _version;
    const int16_t _packetType;
    const int16_t _resultCode;
    const int16_t _alignment;
    const std::shared_ptr<char> _buffer;
    const std::shared_ptr<char> _padding;
    u_int32_t _crc32;

public:
    Packet(int16_t version, int16_t type, u_int32_t crc32, int16_t resultCode, int16_t alignment, std::shared_ptr<char> buffer,  std::shared_ptr<char> padding)
        : _version(version), _packetType(type), _crc32(crc32), _resultCode(resultCode), _alignment(alignment), _buffer(buffer), _padding(padding)
    { }

    int16_t getVersion() const { return _version; }
    int16_t getPacketType() const { return _packetType; }
    u_int32_t getCrc32() const { return _crc32; }
    int16_t getResultCode() const { return _resultCode; }
    int16_t getAlignment() const { return _alignment; }
    const std::shared_ptr<char>& getBuffer() const { return _buffer; }
    const std::shared_ptr<char>& getPadding() const { return _padding; }
    std::string getCommand() const { return std::string(_buffer.get()); }

    bool validateCRC() const { return _crc32 == crc32(); }

    void updateCRC() { _crc32 = crc32(); }
protected:
    virtual u_int32_t crc32() const = 0;
};


#endif //NRPE_PACKET_HPP
