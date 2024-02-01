import QtQuick
import QtQuick.Controls

Window {
    id: id_w
    objectName: "root_window"
    width: 640
    height: 480
    visible: true
    title: qsTr("appWithIcon--eton")
    Column {
        Text {
            id: id_textInfo
            text: "Hello Icon in Gnome Dash!"
            font.family: "Helvetica"
            font.pointSize: 24
            color: "blue"
        }

        Image {
            //anchors.h: parent
            id: id_image
            objectName: "imgItem1"
            source: "avator-slicer.png"
            //source: "siho128.png"
        }
        Button {
            id: id_bt1

            onClicked: {
                id_image.source = "siho128.png"
                console.log(id_image.source)
            }
        }
    }
}
