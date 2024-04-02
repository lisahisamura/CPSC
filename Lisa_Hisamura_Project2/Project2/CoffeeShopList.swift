//
//  CoffeeShopStore.swift
//  Project2
//
//  Created by Lisa Hisamura on 4/1/24.
//

import Foundation
import SwiftUI
import Combine

// Template for a CoffeeShopList - creates a list of coffee shops

class CoffeeShopList : ObservableObject {
    @Published var coffeeshops: [CoffeeShop]
    
    init (coffeeshops: [CoffeeShop] = []) {
        self.coffeeshops = coffeeshops
    }
}
