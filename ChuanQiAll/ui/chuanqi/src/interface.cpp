#include "interface.h"

Interface::Interface(QObject *parent)
    : QObject{parent}
{}

void Interface::renderInterface(QString renderingmethod )
{
    if (renderingmethod == "Automatic") {
        qputenv("QT_QUICK_BACKEND", QByteArray(""));
    } else if (renderingmethod == "OpenGL") {
        qputenv("QT_QUICK_BACKEND", QByteArray("native"));
    } else if (renderingmethod == "OpenGL RHI") {
        qputenv("QT_QUICK_BACKEND", QByteArray("opengl"));
    } else if (renderingmethod == "Direct3D11 RHI") {
        qputenv("QT_QUICK_BACKEND", QByteArray("d3d11"));
    } else if (renderingmethod == "Vulkan RHI") {
        qputenv("QT_QUICK_BACKEND", QByteArray("vulkan"));
    } else if (renderingmethod == "OpenVG") {
        qputenv("QT_QUICK_BACKEND", QByteArray("openvg"));
    } else if (renderingmethod == "Direct3D 9 ANGLE") {
        qputenv("QT_QUICK_BACKEND", QByteArray("d3d9angle"));
    } else if (renderingmethod == "Direct3D 11 ANGLE") {
        qputenv("QT_QUICK_BACKEND", QByteArray("d3d11angle"));
    }
}


