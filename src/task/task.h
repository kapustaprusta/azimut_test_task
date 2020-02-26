#pragma once

namespace task {

    class ITask {
        public:
            explicit ITask() = default;
            virtual ~ITask() = default;

            virtual void Start() = 0;
            virtual void Reset() = 0;
    };

} // task