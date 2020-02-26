#include "checker_task.h"

namespace task {

    CheckerTask::CheckerTask(const std::shared_ptr<reader::IReader>& reader, const std::shared_ptr<writer::IWRiter>& writer) {
        if (!reader || !writer) {
            throw std::runtime_error("invalid arguments");
        }

        reader_ = reader;
        writer_ = writer;
    }

    void CheckerTask::Start() {
        std::vector<uint8_t> flight_info_buffer;
        while (!reader_->IsEOF()) {
            reader_->Read(flight_info_buffer);
            std::string tmp_flight_info(flight_info_buffer.begin(), flight_info_buffer.end());
            flight_info_buffer.clear();

            bool is_have_equal = false;
            for (const auto& flight_info : flight_info_list_) {
                if (utils::IsFlightInfoEqual(flight_info, tmp_flight_info)) {
                    is_have_equal = true;
                    break;
                }
            }

            if (!is_have_equal) {
                flight_info_list_.emplace_back(tmp_flight_info);
                writer_->Write(std::vector<uint8_t>(tmp_flight_info.begin(), tmp_flight_info.end()));
            }
        }
    }

    void CheckerTask::Reset() {
        flight_info_list_.clear();
    }

    void CheckerTask::SetReader(const std::shared_ptr<reader::IReader>& reader) {
        if (!reader) {
            throw std::runtime_error("invalid argument");
        }

        reader_ = reader;
    }

    void CheckerTask::SetWriter(const std::shared_ptr<writer::IWRiter>& writer) {
        if (!writer) {
            throw std::runtime_error("invalid argument");
        }

        writer_ = writer;
    }

    std::list<std::string> CheckerTask::GetFlightInfoList() const {
        return flight_info_list_;
    }

} // task