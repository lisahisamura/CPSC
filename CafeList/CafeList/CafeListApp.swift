// @file CafeListApp.swift
// @author Lisa Hisamura hisamura@chapman.edu
// @CPSC356 Final Project

import SwiftUI

@main
struct CafeListApp: App {
    @Environment(\.scenePhase) private var scenePhase
    var body: some Scene {
        WindowGroup {
            ContentView()
        }
        .onChange(of: scenePhase, perform: { phase in
            switch phase {
            case .active:
                print("Active")
            case .inactive:
                print("Inactive")
            case .background:
                print("Background")
            default:
                print("I do not know")
            }
        })
    }
}

