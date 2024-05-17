// @file Cafe.swift
// @brief Creates the Cafe struct with the different variables that go under each cafe
// @author Lisa Hisamura hisamura@chapman.edu
// @CPSC356 Final Project

import Foundation
import SwiftUI

struct Cafe: Codable, Identifiable {
    var id: String
    var name: String
    var city: String
    var isStudyFriendly: Bool
    var imageName: String
    var review: String?
}
