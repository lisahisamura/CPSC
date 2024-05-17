// @file RecommendationsList.swift
// @author Lisa Hisamura hisamura@chapman.edu
// @CPSC356 Final Project


import Foundation
import SwiftUI
import Combine

// Template for a Cafe List - creates a list of recommended cafes

var recommendationsData: [Cafe] = loadJson("cafeRecommendations.json")

class RecommendationsList : ObservableObject {
    @Published var recommendations: [Cafe]
    
    init (recommendations: [Cafe] = []) {
        self.recommendations = recommendations
    }
}
