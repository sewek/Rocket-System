#pragma once

namespace System
{
    class Core
    {
    private:
        /* data */
    public:
        Core();
        ~Core();

        void devicesLoad();
        void devicesStartUp();
        void devicesStop();
        void devicesUnload();
        void devicesTest();
    };
} // namespace System
