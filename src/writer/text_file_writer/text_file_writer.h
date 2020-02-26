#pragma once

#include <fstream>

#include "../writer.h"

namespace writer {

    class TextFileWriter final : public IWRiter {
        public:
            explicit TextFileWriter(const std::string& file_path);
            ~TextFileWriter() final;

            uint32_t Write(const std::string& buffer) override;

        private:
            std::ofstream file_stream_;
    };

} // writer