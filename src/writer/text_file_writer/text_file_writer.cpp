#include "text_file_writer.h"

namespace writer {

    TextFileWriter::TextFileWriter(const std::string& file_path) {
        file_stream_ = std::ofstream(file_path, std::ofstream::out);
        if (!file_stream_.is_open()) {
            throw std::runtime_error("invalid file path");
        }
    }

    TextFileWriter::~TextFileWriter() {
        file_stream_.close();
    }

    uint32_t TextFileWriter::Write(const std::string& buffer) {
        file_stream_ << buffer << std::endl;

        return buffer.size();
    }

} // writer