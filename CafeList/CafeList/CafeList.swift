// @file CafeList.swift
// @brief Initializes an array of cafes
// @author Lisa Hisamura hisamura@chapman.edu
// @CPSC356 Final Project

import Foundation
import SwiftUI
import Combine

// Template for a CafeList - creates a list of cafe
class CafeList : ObservableObject {
    @Published var cafes: [Cafe]
    
    init (cafes: [Cafe] = []) {
        self.cafes = cafes
    }
}
