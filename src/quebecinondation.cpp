/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "quebecinondation.h"

#include <KLocalizedString>
#include <nlohmann/json.hpp>

QuebecInondation::QuebecInondation(QObject *parent, const KPluginMetaData &data, const QVariantList &args)
    : Plasma::Applet(parent, data, args),
      m_nativeText(i18n("Text coming from C++ plugin"))
{
    networkManager = new QNetworkAccessManager(this);

    connect(networkManager, &QNetworkAccessManager::finished, this, &QuebecInondation::onDownloadFinished);
}

QuebecInondation::~QuebecInondation()
{
}

QString QuebecInondation::nativeText() const
{
    return m_nativeText;
}

void QuebecInondation::refresh()
{
    QUrl url(QString::fromUtf8("https://geoegl.msp.gouv.qc.ca/apis/mapserver-vigilance/ws/vigilance.fcgi?service=wfs&version=1.1.0&request=getfeature&typename=stations_igo2_public&outputformat=geojson&epsg:4326"));

    QNetworkRequest request(url);
    networkManager->get(request);
}

void QuebecInondation::onDownloadFinished(QNetworkReply* reply)
{
    if (reply->error() != QNetworkReply::NetworkError::NoError)
    {
        m_nativeText = i18n("Network request failed");
        return;
    }
    m_nativeText = QString::fromUtf8("Potato");

    nlohmann::json parsedJson = nlohmann::json::parse(reply->readAll(), nullptr, false, true);
    if (parsedJson.empty())
    {
        m_nativeText = i18n("Error parsing the JSON");
        return;
    }
}

K_PLUGIN_CLASS(QuebecInondation)

#include "quebecinondation.moc"
#include "moc_quebecinondation.cpp"
