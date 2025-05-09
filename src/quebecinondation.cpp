/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "quebecinondation.h"

#include <KLocalizedString>

QuebecInondation::QuebecInondation(QObject *parent, const KPluginMetaData &data, const QVariantList &args)
    : Plasma::Applet(parent, data, args),
      m_nativeText(i18n("Text coming from C++ plugin"))
{
}

QuebecInondation::~QuebecInondation()
{
}

QString QuebecInondation::nativeText() const
{
    return m_nativeText;
}

K_PLUGIN_CLASS(QuebecInondation)

#include "quebecinondation.moc"
#include "moc_quebecinondation.cpp"
