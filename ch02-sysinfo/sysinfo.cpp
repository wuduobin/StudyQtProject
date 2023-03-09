#include "sysinfo.h"

#include <QtGlobal>

#ifdef Q_OS_WIN
    #include "sysinfowindowsimpl.h"
#elif defined(Q_OS_MAC)
    #include "sysinfomacimpl.h"
#elif defined(Q_OS_LINUX)
    #include "sysinfolinuximpl.h"
#endif

SysInfo::SysInfo()
{
}

SysInfo &SysInfo::instance()
{
#ifdef Q_OS_WIN
    static SysinfoWindowsImpl singleton;
#elif defined(Q_OS_MAC)
    static SysInfoMacImpl singleton;
#elif defined(Q_OS_LINUX)
    static SysInfoLinuxImpl singleton;
#endif

    return singleton;
}

SysInfo::~SysInfo()
{
}
