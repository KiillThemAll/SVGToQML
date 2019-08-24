import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Shapes 1.0
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3

Window {
    id:wind
    visible: true
    width: 640
    height: 480
    title: qsTr("SVGToQML")

    Component.onCompleted: showMaximized()


    ListView{
        id: svgViewer
        anchors.fill: parent
        model: pathModel
        clip: true

        delegate: Shape{

            transform: Scale {
                id:sc
                xScale: 1; yScale: 1
            }
            Connections {
                target: wind
                onHeightChanged: resizeView()
                onWidthChanged: resizeView()
                function resizeView(){
                    if (wind.height*scaleX/scaleY < wind.width) {
                        sc.xScale = wind.height/scaleY; sc.yScale = wind.height/scaleY
                    }
                    else {
                        sc.xScale = wind.width/scaleX; sc.yScale = wind.width/scaleX
                    }
                }
            }
            ShapePath {
                strokeColor: stroke
                strokeWidth: 4
                joinStyle: ShapePath.RoundJoin

                PathSvg {path: d}
            }
        }
    }
}
