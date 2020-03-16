//
// Created by Massimiliano Ziccardi on 13/03/2020.
//

#ifndef NRPE_PACKET_HPP
#define NRPE_PACKET_HPP

#include <cstdint>
#include <memory>
#include <string>
#include <utility>

class Packet {
private:
    const int16_t _version;
    const int16_t _packetType;
    const int16_t _resultCode;
    const int16_t _alignment;
    const std::shared_ptr<char> _buffer;
    u_int32_t _bufferLength;
    const std::shared_ptr<char> _padding;
    const int16_t _paddingLength;
    u_int32_t _crc32;

public:
    Packet(int16_t version,
            int16_t type,
            u_int32_t crc32,
            int16_t resultCode,
            int16_t alignment,
            std::shared_ptr<char> buffer,
            u_int32_t bufferLength,
            std::shared_ptr<char> padding,
            int16_t paddingLength)
        : _version(version), _packetType(type), _crc32(crc32), _resultCode(resultCode),
          _alignment(alignment), _buffer(std::move(buffer)), _bufferLength(bufferLength), _padding(std::move(padding)),
          _paddingLength(paddingLength)
    { }
    virtual ~Packet() {}

    int16_t getVersion() const { return _version; }
    int16_t getPacketType() const { return _packetType; }
    u_int32_t getCrc32() const { return _crc32; }
    int16_t getResultCode() const { return _resultCode; }
    int16_t getAlignment() const { return _alignment; }
    const std::shared_ptr<char>& getBuffer() const { return _buffer; }
    u_int32_t getBufferLength() const { return _bufferLength; }
    const std::shared_ptr<char>& getPadding() const { return _padding; }
    int16_t getPaddingLength() const { return _paddingLength; }
    std::string getCommand() const { return std::string(_buffer.get()); }

    bool validateCRC() const { return _crc32 == crc32(); }

    void updateCRC() { _crc32 = crc32(); }
protected:
    virtual u_int32_t crc32() const = 0;

};


#endif //NRPE_PACKET_HPP
