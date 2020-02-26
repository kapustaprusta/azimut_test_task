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
        std::string tmp_flight_info;
        while (!reader_->IsEOF()) {
            reader_->Read(tmp_flight_info);

            bool is_have_equal = false;
            for (const auto& flight_info : flight_info_list_) {
                if (utils::IsFlightInfoEqual(flight_info, tmp_flight_info)) {
                    is_have_equal = true;
                    break;
                }
            }

            if (!is_have_equal) {
                flight_info_list_.emplace_back(tmp_flight_info);
                writer_->Write(tmp_flight_info);
            }

            tmp_flight_info.clear();
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