/*
 * Copyright 2010, The Android Open Source Project
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "PluginObject.h"

#ifndef navigationPlugin__DEFINED
#define navigationPlugin__DEFINED

class NavigationPlugin : public SubPlugin {
public:
    NavigationPlugin(NPP inst);
    virtual ~NavigationPlugin();
    virtual bool supportsDrawingModel(ANPDrawingModel);
    virtual int16_t handleEvent(const ANPEvent* evt);
private:
    void draw(ANPCanvas*);
    void drawPlugin(const ANPBitmap& bitmap, const ANPRectI& clip);

    bool        m_hasFocus;

    ANPRectF*    m_activeNav;
    ANPRectF    m_navUp;
    ANPRectF    m_navDown;
    ANPRectF    m_navLeft;
    ANPRectF    m_navRight;
    ANPRectF    m_navCenter;

    ANPPaint*   m_paintDisabled;
    ANPPaint*   m_paintActive;

    bool handleNavigation(ANPKeyCode keyCode);
    ANPPaint* getPaint(ANPRectF*);
};

#endif // navigationPlugin__DEFINED
