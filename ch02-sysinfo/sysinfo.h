#ifndef SYSINFO_H
#define SYSINFO_H

// Strategy pattern
class SysInfo
{
public:
    static SysInfo& instance();
    virtual ~SysInfo();

    virtual void init() = 0;
    virtual double cpuLoadAverage() = 0;
    virtual double memoryUsed() = 0;

protected:
    explicit SysInfo();

private: // Since only one instance of the object must exist, allowing the copy constructor and the assignment operator is nonsense.
    SysInfo(const SysInfo& rhs);
    SysInfo& operator=(const SysInfo& rhs);
};

#endif // SYSINFO_H
