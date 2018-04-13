#ifndef DESKTOPLINUXPLATFORM_H
#define DESKTOPLINUXPLATFORM_H

#include "Platform.h"

#define WIDTH 800
#define HEIGHT 600

namespace MaliSDK
{
class DesktopLinuxPlatform : public Platform
{
public:
    void createX11Window()
    {
        XSetWindowAttributes swa;
        swa.event_mask = ExposureMask | PointerMotionMask | KeyPressMask;
        window = XCreateWindow (
            display, DefaultRootWindow(display),
            0, 0, WIDTH, HEIGHT, 0,
            CopyFromParent, InputOutput,
            CopyFromParent, CWEventMask,
            &swa);
        XMapWindow(display, window);

        XSizeHints sizehints;
        sizehints.x = 0;
        sizehints.y = 0;
        sizehints.width = WIDTH;
        sizehints.height = HEIGHT;
        sizehints.flags = USSize;//| USPosition;
        XSetNormalHints(display, window, &sizehints);
        const char *name = "DesktopLinuxPlatform";
        XSetStandardProperties(display, window, name, name, None, (char **) NULL, 0, &sizehints);
    }

    virtual void createWindow(int width, int height) {}
    virtual WindowStatus checkWindow(void) {}
    virtual void destroyWindow(void) {}
};
}

using namespace MaliSDK; // For Platform::log

#endif /* DESKTOPLINUXPLATFORM_H */
