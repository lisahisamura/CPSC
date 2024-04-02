//
//  CoffeeShopData.swift
//  Project2
//
//  Created by Lisa Hisamura on 4/1/24.
//

import Foundation
import UIKit
import SwiftUI

// Used to read json file - catches errors in case it cannot load the file

var coffeeShopData: [CoffeeShop] = loadJson("coffeeShopData.json")

func loadJson<T: Decodable> (_ filename: String) -> T {
    let data: Data
    guard let file = Bundle.main.url(forResource: filename, withExtension: nil)
    else {
        fatalError("\(filename) not found.")
    }
    do {
        data = try Data(contentsOf: file)
    } catch {
        fatalError("Could not load \(filename): \(error)")
    }
    do {
        return try JSONDecoder().decode(T.self, from: data)
    } catch {
        fatalError("Unable to parse \(filename): \(error)")
    }
}
