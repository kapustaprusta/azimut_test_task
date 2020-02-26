#include "text_file_reader.h"

namespace reader {

    TextFileReader::TextFileReader(const std::string& file_path) {
        file_stream_ = std::ifstream(file_path, std::ifstream::in);
        if (!file_stream_.is_open()) {
            throw std::runtime_error("invalid file path");
        }
    }

    TextFileReader::~TextFileReader() {
        file_stream_.close();
    }

    uint32_t TextFileReader::Read(std::string& buffer) {
        std::getline(file_stream_, buffer);

        return buffer.size();
    }

    bool TextFileReader::IsEOF() const {
        return file_stream_.eof();
    }

}