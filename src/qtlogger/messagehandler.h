// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2024 Mikhail Yatsenko <mikhail.yatsenko@gmail.com>

#pragma once

#include <QSharedPointer>

#include "logmessage.h"
#include "logger_global.h"

class QMessageLogContext;

namespace QtLogger {

class QTLOGGER_EXPORT MessageHandler
{
public:
    enum Type { HandlerType, FilterType, FormatterType, SinkType, PipelineType, OtherType };

    virtual ~MessageHandler() = default;

    virtual Type type() const { return MessageHandler::HandlerType; }

    virtual bool process(LogMessage &logMsg) = 0;
};

using MessageHandlerPtr = QSharedPointer<MessageHandler>;

} // namespace QtLogger
