//
//  CoffeeShop.swift
//  Project2
//
//  Created by Lisa Hisamura on 4/1/24.
//

import Foundation
import SwiftUI

// Lists necessary variables for a CoffeeShop object

struct CoffeeShop : Codable, Identifiable {
    var id: String
    var name: String
    var city: String
    var isStudyFriendly: Bool
    var imageName: String
}

