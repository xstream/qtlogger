// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2024 Mikhail Yatsenko <mikhail.yatsenko@gmail.com>

#include "iodevicesink.h"

namespace QtLogger {

QTLOGGER_DECL_SPEC
IODeviceSink::IODeviceSink(const QIODevicePtr &device) : m_device(device) { }

QTLOGGER_DECL_SPEC
void IODeviceSink::send(const LogMessage &logMsg)
{
    if (m_device.isNull()) {
        return;
    }

    m_device->write(logMsg.formattedMessage().toLocal8Bit().append("\n"));
}

QTLOGGER_DECL_SPEC
const QIODevicePtr &IODeviceSink::device() const
{
    return m_device;
}

QTLOGGER_DECL_SPEC
void IODeviceSink::setDevice(const QIODevicePtr &device)
{
    m_device = device;
}

} // namespace QtLogger
