/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import org.kde.plasma.plasmoid
import org.kde.plasma.components as PlasmaComponents3

PlasmoidItem {
    id: root
    fullRepresentation: ColumnLayout {
        anchors.fill: parent
        Timer {
            interval: 500; running: true; repeat: true
            onTriggered: label.text = Plasmoid.nativeText
        }
        PlasmaComponents3.Button {
            text: "Refresh"
            onClicked: Plasmoid.refresh()
        }
        PlasmaComponents3.Label {
            id : label
            Layout.alignment: Qt.AlignCenter
            text: Plasmoid.nativeText
        }
    }
}
