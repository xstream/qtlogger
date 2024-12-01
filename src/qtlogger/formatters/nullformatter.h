// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2024 Mikhail Yatsenko <mikhail.yatsenko@gmail.com>

#pragma once

#include <QSharedPointer>

#include "../formatter.h"
#include "../logger_global.h"

namespace QtLogger {

using NullFormatterPtr = QSharedPointer<class NullFormatter>;

class QTLOGGER_EXPORT NullFormatter : public Formatter
{
public:
    static NullFormatterPtr instance()
    {
        static const auto s_instance = NullFormatterPtr::create();
        return s_instance;
    }

    QString format(const LogMessage &logMsg) const override { return logMsg.message(); }
};

} // namespace QtLogger
