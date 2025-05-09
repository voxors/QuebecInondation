/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

import QtQuick
import QtQuick.Layouts
import org.kde.plasma.plasmoid
import org.kde.plasma.components as PlasmaComponents3


PlasmoidItem {
    id: root
    fullRepresentation: ColumnLayout {
        anchors.fill: parent
        Image {
            Layout.fillHeight: true
            Layout.fillWidth: true
            fillMode: Image.PreserveAspectFit
            source: "../images/pairs.svg"
        }
        Timer {
            interval: 500; running: true; repeat: true
            onTriggered: label.text = Plasmoid.nativeText
        }
        PlasmaComponents3.Label {
            id : label
            Layout.alignment: Qt.AlignCenter
            text: Plasmoid.nativeText
        }
    }
}
