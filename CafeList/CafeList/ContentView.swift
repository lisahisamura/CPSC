// @file ContentView.swift
// @brief Creates the tab views for MyCafes and Recommendations.
// @author Lisa Hisamura hisamura@chapman.edu
// @CPSC356 Final Project

import SwiftUI

struct ContentView: View {
    
    // Bottom navigation menu - made up of two tab views (MyCafes and Recommendations)
    
    @State private var selection = 1
    
    var body: some View {
        TabView(selection: $selection) {
            MyCafes()
                .tabItem {
                    Image(systemName: "cup.and.saucer")
                    Text("My Cafes")
                }.tag(1)
            
            
            Recommendations()
                .tabItem {
                    Image(systemName: "star")
                    Text("Recommendations")
                }.tag(2)

        }
       
        // Appearance of screen
        
        .font(.largeTitle)
        .accentColor(Color.init(red: 0.859, green: 0.424, blue: 0.251))

    }
}

#Preview {
    ContentView()
}

