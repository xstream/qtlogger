// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2024 Mikhail Yatsenko <mikhail.yatsenko@gmail.com>

#include "jsonformatter.h"

#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>

namespace QtLogger {

QTLOGGER_DECL_SPEC
QString JsonFormatter::format(const LogMessage &logMsg) const
{
    QJsonObject obj;

    obj[QStringLiteral("message")] = logMsg.message();

    auto attrs = logMsg.allAttributes();
    for (auto it = attrs.cbegin(); it != attrs.cend(); ++it) {
        obj.insert(it.key(), QJsonValue::fromVariant(it.value()));
    }

    return QString::fromUtf8(QJsonDocument(obj).toJson());
}

} // namespace QtLogger
