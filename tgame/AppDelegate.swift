//
//  AppDelegate.swift
//  tgame
//
//  Created by Michael on 28/10/2019.
//  Copyright © 2019 Michael. All rights reserved.
//

import Cocoa

@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate {

    @IBOutlet weak var window: NSWindow!

    func applicationDidFinishLaunching(_ aNotification: Notification) {
        let pixelFormatAttributes:[NSOpenGLPixelFormatAttribute] = [
            UInt32(NSOpenGLPFANoRecovery),
            UInt32(NSOpenGLPFAColorSize), UInt32(32),
            UInt32(NSOpenGLPFADepthSize), UInt32(32),
            UInt32(NSOpenGLPFAMaximumPolicy),
            UInt32(NSOpenGLPFADoubleBuffer),
            UInt32(NSOpenGLPFAAccelerated),
            UInt32(0)
        ]
        let openglView = AOpenGLView.init(frame: window.frame, pixelFormat: NSOpenGLPixelFormat(attributes:pixelFormatAttributes))
        window.contentView = openglView
        window.makeFirstResponder(openglView)
   }

}

