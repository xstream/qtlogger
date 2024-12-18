// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2024 Mikhail Yatsenko <mikhail.yatsenko@gmail.com>

#pragma once

#include <QSharedPointer>

#include "../formatter.h"
#include "../logger_global.h"

namespace QtLogger {

using JsonFormatterPtr = QSharedPointer<class JsonFormatter>;

class QTLOGGER_EXPORT JsonFormatter : public Formatter
{
public:
    static JsonFormatterPtr instance()
    {
        static const auto s_instance = JsonFormatterPtr::create();
        return s_instance;
    }

    QString format(const LogMessage &lmsg) override;
};

} // namespace QtLogger
