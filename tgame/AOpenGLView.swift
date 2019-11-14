//
//  AOpenGLView.swift
//  tgame
//
//  Created by Michael on 28/10/2019.
//  Copyright © 2019 Michael. All rights reserved.
//

import Cocoa

fileprivate let fps = 60.0

class AOpenGLView: NSOpenGLView {

    private var animationInterval:TimeInterval = 1.0 / fps
    private var animationTimer:Timer? = nil
    private let engineBridge = CPPBridge()

    override init?(frame frameRect: NSRect, pixelFormat format: NSOpenGLPixelFormat?) {
        super.init(frame: frameRect, pixelFormat: format)
        
        openGLContext?.view = self
        engineBridge.updateScreenSize(withWidth: bounds.width, height: bounds.height)
        engineBridge.startGame()
        startAnimation()
    }
    
    required init?(coder decoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func viewDidEndLiveResize() {
        stopAnimation()
        engineBridge.updateScreenSize(withWidth: frame.width, height: frame.height)
        startAnimation()
    }
    
    override var acceptsFirstResponder : Bool {
        return true
    }

    override func keyDown(with event: NSEvent) {
        engineBridge.processKeyboardEvent(UInt32(event.keyCode))
    }
    
    private func startAnimation() {
        animationTimer = Timer.scheduledTimer(timeInterval: animationInterval, target: self, selector: #selector(animationHandler), userInfo: nil, repeats: true)
    }
    
    private func stopAnimation() {
        if animationTimer == nil {
            return
        }
        
        animationTimer!.invalidate()
        animationTimer = nil
    }
    
    @objc private func animationHandler() {
        engineBridge.processGameCycle()
        openGLContext?.flushBuffer()
    }
    
}
