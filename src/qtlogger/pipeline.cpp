// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2024 Mikhail Yatsenko <mikhail.yatsenko@gmail.com>

#include "pipeline.h"

namespace QtLogger {

QTLOGGER_DECL_SPEC
Pipeline::Pipeline(std::initializer_list<HandlerPtr> handlers) : m_handlers(handlers) { }

QTLOGGER_DECL_SPEC
void Pipeline::append(const HandlerPtr &handler)
{
    if (handler.isNull())
        return;

    m_handlers.append(handler);
}

QTLOGGER_DECL_SPEC
void Pipeline::append(std::initializer_list<HandlerPtr> handlers)
{
    m_handlers.append(handlers);
}

QTLOGGER_DECL_SPEC
void Pipeline::remove(const HandlerPtr &handler)
{
    if (handler.isNull())
        return;

    m_handlers.removeAll(handler);
}

QTLOGGER_DECL_SPEC
void Pipeline::clear()
{
    m_handlers.clear();
}

QTLOGGER_DECL_SPEC
Pipeline &Pipeline::operator<<(const HandlerPtr &handler)
{
    append(handler);
    return *this;
}

QTLOGGER_DECL_SPEC
bool Pipeline::process(LogMessage &lmsg)
{
    QString fmsg;
    QVariantHash attrs;

    if (m_scoped) {
        if (lmsg.isFormatted()) {
            fmsg = lmsg.formattedMessage();
        }
        attrs = lmsg.attributes();
    }

    for (auto &handler : m_handlers) {
        if (!handler)
            continue;
        if (!handler->process(lmsg))
            break;
    }

    if (m_scoped) {
        lmsg.setFormattedMessage(fmsg);
        lmsg.attributes() = attrs;
    }

    return true;
}

} // namespace QtLogger
