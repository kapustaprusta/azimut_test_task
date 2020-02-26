#pragma once

#include <list>
#include <memory>

#include "../task.h"
#include "../../reader/reader.h"
#include "../../writer/writer.h"
#include "../../utils/utils.h"

namespace task {

    class CheckerTask final : public ITask {
        public:
            explicit CheckerTask(const std::shared_ptr<reader::IReader>& reader, const std::shared_ptr<writer::IWRiter>& writer);
            ~CheckerTask() = default;

            void Start() ;
            void Reset();

            void SetReader(const std::shared_ptr<reader::IReader>& reader);
            void SetWriter(const std::shared_ptr<writer::IWRiter>& writer);

            std::list<std::string> GetFlightInfoList() const;

        private:
            std::shared_ptr<reader::IReader> reader_;
            std::shared_ptr<writer::IWRiter> writer_;

            std::list<std::string> flight_info_list_;
    };

} // task