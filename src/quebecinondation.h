/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef QUEBECINONDATION_H
#define QUEBECINONDATION_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <Plasma/Applet>

class QuebecInondation : public Plasma::Applet
{
    Q_OBJECT
    Q_PROPERTY(QString nativeText READ nativeText CONSTANT)

public:
    explicit QuebecInondation(QObject *parent, const KPluginMetaData &data, const QVariantList &args);
    ~QuebecInondation();

    QString nativeText() const;
    Q_SLOT void refresh();

private:
    QString m_nativeText;
    QNetworkAccessManager* networkManager;
    Q_SLOT void onDownloadFinished(QNetworkReply* reply);
};

#endif
