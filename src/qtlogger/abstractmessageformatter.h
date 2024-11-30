// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2024 Mikhail Yatsenko <mikhail.yatsenko@gmail.com>

#pragma once

#include <QSharedPointer>

#include "messagehandler.h"
#include "logger_global.h"

class QMessageLogContext;

namespace QtLogger {

class QTLOGGER_EXPORT AbstractMessageFormatter : public MessageHandler
{
public:
    virtual ~AbstractMessageFormatter() = default;

    virtual QString format(const LogMessage &logMsg) const = 0;

    Type type() const override { return MessageHandler::Formatter; }

    bool process(LogMessage &logMsg) override final
    {
        logMsg.setFormattedMessage(format(logMsg));
        return true;
    }
};

using AbstractMessageFormatterPtr = QSharedPointer<AbstractMessageFormatter>;

} // namespace QtLogger
